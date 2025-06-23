/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:30:28 by jlacaze-          #+#    #+#             */
/*   Updated: 2025/06/23 22:31:56 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// static void fd_redirection (int W_END, int R_END, int fd_in)
// {
// 	if (dup2(W_END, STDOUT_FILENO) == -1){
// 		close_fds(3, fd_in, R_END, W_END);
// 		print_error(RED"At fd_redirection > stdout"RESET, 1);
// 	}
// 	if (dup2(fd_in, STDIN_FILENO) == -1){
// 		close_fds(3, W_END, R_END, fd_in);
// 		ft_printf("fd_in = %d\n W_END = %d\n R_END = %d\n", fd_in, W_END, R_END);
// 		print_error(RED"At fd_redirection > (stdin)"RESET, 1);
// 	}
// }

int	create_child(char *cmd, char **env, t_pipex *pipex)
{
	int		pipe_fd[2];

// todo : secure dup2
	if (pipe(pipe_fd) == -1)
		print_error("pipe failed", 1);
	pipex->current_pid = fork();
	if (pipex->current_pid == -1)
		print_error("fork failed", 1);
	(void)env; // to avoid unused variable warning
	(void)cmd; // to avoid unused variable warning

	if (pipex->current_pid == 0)
	{
		close(pipe_fd[READ_END]);
		dup2(pipe_fd[WRITE_END], STDOUT_FILENO);
		close(pipe_fd[WRITE_END]);
		if (pipex->infile == -1)
			print_error("open infile failed", 1);
		close(pipex->infile);
		close(pipex->outfile);
		exec_cmd(cmd, env);
	}
	else
	{
		close(pipe_fd[WRITE_END]);
		dup2(pipe_fd[READ_END], STDIN_FILENO);
		close(pipe_fd[READ_END]);
	}
	return (pipe_fd[READ_END]);
}
// valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full ./pipex Makefile cat cat bonjour

void	delete_tmp_file(char *infile_name)
{
	if (unlink(infile_name) == -1)
		print_error("unlink failed", -1);
}

int	open_files(t_pipex *pipex, int argc, char **argv)
{
	pipex->infile = open(pipex->infile_name, O_RDONLY);
	pipex->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(pipex->infile, STDIN_FILENO);
	return (pipex->infile);
}

pid_t	last_command(int argc, char **argv, char **env, t_pipex pipex)
{
	int pid;
	close(pipex.infile);
	if (pipex.outfile == -1)
	{
		pid = 0;
		while (pid != -1)
			pid = wait(NULL);
		print_error("open outfile failed", 1);
	}
	pid = fork();
	if (pid == -1)
		print_error("fork failed", 1);
	if (pid == 0)
	{
		dup2(pipex.outfile, STDOUT_FILENO);
		close(pipex.outfile);
		exec_cmd(argv[argc - 2], env);
	}
	return (pid);
}
