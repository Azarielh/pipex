/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:29:38 by jlacaze-          #+#    #+#             */
/*   Updated: 2025/06/25 01:34:28 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "stdarg.h"

void	close_fds(int count, ...)
{
	va_list	args;
	int		fd;

	va_start(args, count);
	while (count--)
	{
		fd = va_arg(args, int);
		if (fd != -1)
			if (close(fd) == -1)
				continue ;
	}
	va_end(args);
}

void	print_error(char *msg, int exit_code)
{
	if (unlink(".here_doc") == -1 && errno != ENOENT)
	{
		perror("unlink failed");
		exit(EXIT_FAILURE);
	}
	if (errno != 0)
		perror(msg);
	else
		ft_printf(RED"Error : "RESET"%s", msg);
	exit(exit_code);
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	t_pipex	pipex;
	int		status;
	int		exitcode;

	if (argc < 5 || strncmp(argv[1], ".here_doc", 9) == 0)
		print_error("Usage: ./pipex file1 cmd1 cmd2 file2\n", 1);
	i = 2;
	open_files(&pipex, argc, argv, argv[1]);
	while (i < argc - 2)
		create_child(argv[i++], envp, &pipex);
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
	close_fds(2, pipex.infile, pipex.outfile);
	return (exitcode);
}
