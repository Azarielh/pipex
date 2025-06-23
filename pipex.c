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


// static int	waitnclose(int infile, int outfile, pid_t last_pid)
// {
// 	int		status;
// 	int		exitcode;
// 	pid_t	pid;

// 	pid = 0;
// 	pid = wait(&status);
// 	while (pid != -1)
// 	{
// 		if (pid == last_pid && WIFEXITED(status))
// 			exitcode = WEXITSTATUS(status);
// 		else if (pid == last_pid && WIFSIGNALED(status))
// 			exitcode = 128 + WTERMSIG(status);
// 		pid = wait(&status);
// 	}
// 	close(infile);
// 	close(outfile);
// 	return (exitcode);
// }

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
	int		exitcode;

	if (argc < 5)
        print_error("Usage: ./pipex file1 cmd1 cmd2 file2\n", 1);
	i = 2;
	pipex.infile_name = argv[1];
ft_printf("infile_name = %s\n", pipex.infile_name);
	pipex.flags = O_WRONLY | O_CREAT | O_TRUNC;
	check_here_doc(argc, argv, &pipex, &i);
	open_files(&pipex, argc, argv);
	while (i < argc - 2)
		pipex.fd_in = create_child(argv[i++], envp, &pipex);
	waitpid(pipex.current_pid, &status, 0);
	pipex.last_pid = last_command(argc, argv, envp, pipex);
	pipex.current_pid = 0;
	exitcode = 1;
	while (pipex.current_pid != -1)
	{
		pipex.current_pid = wait(&status);
		if (pipex.current_pid == pipex.last_pid && WIFEXITED(status))
			exitcode = WEXITSTATUS(status);
		else if (pipex.current_pid == pipex.last_pid && WIFSIGNALED(status))
			exitcode = 128 + WTERMSIG(status);
	}
	return (exitcode);
}
