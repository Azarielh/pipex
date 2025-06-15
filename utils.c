/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:30:28 by jlacaze-          #+#    #+#             */
/*   Updated: 2025/03/28 23:23:44 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	create_child(char *cmd, char **env, int fd_in)
{
	int		pipe_fd[2];
	int		pid;

	if (pipe(pipe_fd) == -1)
		print_error("pipe failed", 1);
	pid = fork();
	if (pid == -1)
		print_error("fork failed", 1);
	if (pid == 0)
	{
		close(pipe_fd[READ_END]);
		dup2(pipe_fd[WRITE_END], STDOUT_FILENO);
		close(pipe_fd[WRITE_END]);
		if (fd_in == -1)
			print_error("open infile failed", 1);
		exec_cmd(cmd, env);
	}
	else
	{
		close(pipe_fd[WRITE_END]);
		dup2(pipe_fd[READ_END], STDIN_FILENO);
		close(pipe_fd[READ_END]);
	}
}
// valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full ./pipex Makefile cat cat bonjour

void	delete_tmp_file(char *infile_name)
{
	if (unlink(infile_name) == -1)
		print_error("unlink failed", -1);
}

void	write_here_doc(char *limiter, char *infile_name)
{
	char	*line;
	int		infile;

	line = NULL;
	infile = open(infile_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (infile == -1)
		print_error("create infile failed", -1);
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			print_error("failed to read line", 1);
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, infile);
		free(line);
	}
	close(infile);
}

int	open_files(t_pipex *pipex, int argc, char **argv)
{
	pipex->infile = open(pipex->infile_name, O_RDONLY);
	pipex->outfile = open(argv[argc - 1], pipex->flags, 0644);
	dup2(pipex->infile, STDIN_FILENO);
	return (pipex->infile);
}

pid_t	last_command(int argc, char **argv, char **env, t_pipex pipex)
{
	int pid;
	close(pipex.infile);
	if (argc >= 6 && ft_strncmp(argv[1], "here_doc\0", 9) == 0)
		delete_tmp_file(pipex.infile_name);
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
		exec_cmd(argv[argc - 2], env);
	}
	return (pid);
}
