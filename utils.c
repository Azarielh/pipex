/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:30:28 by jlacaze-          #+#    #+#             */
/*   Updated: 2025/06/25 01:39:23 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	safe_dup(int old_fd, int new_fd, char *context)
{
	if (dup2(old_fd, new_fd) == -1)
	{
		close(old_fd);
		print_error(context, 0);
	}
}

void	create_child(char *cmd, char **env, t_pipex *pipex)
{
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		print_error("pipe failed", 1);
	pipex->current_pid = fork();
	if (pipex->current_pid == -1)
		print_error("fork failed", 1);
	if (pipex->current_pid == 0)
	{
		safe_dup(pipe_fd[WRITE_END], STDOUT_FILENO, "child : dup2");
		close_fds(2, pipe_fd[READ_END], pipe_fd[WRITE_END]);
		close_fds(2, pipex->infile, pipex->outfile);
		if (pipex->infile == -1)
			print_error("open infile failed", 1);
		exec_cmd(cmd, env);
	}
	else
	{
		safe_dup(pipe_fd[READ_END], STDIN_FILENO, "parent : dup2");
		close_fds(2, pipe_fd[READ_END], pipe_fd[WRITE_END]);
	}
}

void	open_files(t_pipex *pipex, int argc, char **argv, char *infile_name)
{
	pipex->infile_name = infile_name;
	pipex->infile = open(infile_name, O_RDONLY);
	pipex->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->infile != -1)
		safe_dup(pipex->infile, STDIN_FILENO, "open_files");
}

pid_t	last_command(int argc, char **argv, char **env, t_pipex pipex)
{
	int	pid;

	if (pipex.outfile == -1)
	{
		pid = 0;
		while (pid != -1)
			pid = wait(NULL);
		close_fds(2, pipex.infile, pipex.outfile);
		print_error("open outfile failed", 1);
	}
	pid = fork();
	if (pid == -1)
		print_error("fork failed", 1);
	if (pid == 0)
	{
		safe_dup(pipex.outfile, STDOUT_FILENO, "last_child : dup2");
		close_fds(2, pipex.infile, pipex.outfile);
		exec_cmd(argv[argc - 2], env);
	}
	return (pid);
}
