/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 20:43:54 by jlacaze-          #+#    #+#             */
/*   Updated: 2025/03/29 00:02:50 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**getent_env(char **env, char *key)
{
	char	**paths;
	int		i;

	i = 0;
	paths = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], key, 5) == 0)
		{
			paths = ft_split_v2(env[i] + 5, ':');
			if (paths == NULL)
				return (NULL);
			break ;
		}
		i++;
	}
	return (paths);
}

char	*get_path(char *cmd, char **env)
{
	char	**paths;
	char	*path;
	char	*temp_path;
	int		i;

	paths = getent_env(env, "PATH=");
	if (paths == NULL)
		return (NULL);
	i = 0;
	while (paths[i++])
	{
		temp_path = ft_strjoin(paths[i], "/");
		if (temp_path == NULL)
		{
			free_arr(paths);
			return (NULL);
		}
		path = ft_strjoin(temp_path, cmd);
		free(temp_path);
		if (path == NULL)
		{
			free_arr(paths);
			return (NULL);
		}
		if (access(path, F_OK) == 0)
		{
			free_arr(paths);
			return (path);
		}
		free(path);
	}
	free_arr(paths);
	return (NULL);
}

void	exec_cmd(char *arg, char **env)
{
	char	*path;
	char	**cmd_args;

	cmd_args = ft_split_v2(arg, ' ');
	if (cmd_args == NULL)
		print_error("failed to allocate memory", 1);
	path = get_path(cmd_args[0], env);
	if (path == NULL)
	{
		free_arr(cmd_args);
		print_error("command not found", 127);
	}
	execve(path, cmd_args, env);
	free_arr(cmd_args);
	print_error("execve failed", 1);
}
