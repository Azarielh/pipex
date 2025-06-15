 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:29:38 by jlacaze-          #+#    #+#             */
/*   Updated: 2025/03/28 23:00:34 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(char *msg, int exit_code)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	if (unlink(".here_doc") == -1 && errno != ENOENT)
	{
		perror("unlink failed");
		exit(EXIT_FAILURE);
	}
	if (errno != 0)
		perror(msg);
	exit(exit_code);
}

void	check_here_doc(int argc, char **argv, t_pipex *pipex, int *i)
{
	if (argc >= 6 && ft_strncmp(argv[1], "here_doc\0", 9) == 0)
	{
		(*i) = 3;
		pipex->flags = O_WRONLY | O_CREAT | O_APPEND;
		pipex->infile_name = ".here_doc";
		write_here_doc(argv[2], pipex->infile_name);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	t_pipex	pipex;
	int		status;
	pid_t	pid;
	pid_t	last_pid;
	int		exitcode;

	if (argc < 5)
        print_error("Usage: ./pipex file1 cmd1 cmd2 file2\n", 1);
	i = 2;
	pipex.infile_name = argv[1];
	pipex.flags = O_WRONLY | O_CREAT | O_TRUNC;
	check_here_doc(argc, argv, &pipex, &i);
	int fd_in = open_files(&pipex, argc, argv);
	while (i < argc - 2)
	{
		create_child(argv[i], envp, fd_in);
		i++;
	}
	last_pid = last_command(argc, argv, envp, pipex);
	pid = 0;
	exitcode = 1;
	while (pid != -1)
	{
		pid = wait(&status);
		if (pid == last_pid && WIFEXITED(status))
			exitcode = WEXITSTATUS(status);
		if (pid == last_pid && WIFSIGNALED(status))
			exitcode = 128 + WTERMSIG(status);
	}
	return (exitcode);
}
