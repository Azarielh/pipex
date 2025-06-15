/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:10:22 by jlacaze-          #+#    #+#             */
/*   Updated: 2024/12/27 14:34:30 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *stack, char *buffer)
{
	int	read_bytes;

	if (!stack)
		stack = ft_cal_z(1, sizeof(char));
	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(stack);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		stack = ft_strjoin(stack, buffer);
		if (ft_eol_finder(stack) != -1)
			break ;
	}
	return (stack);
}

static char	*extract_line(char **stack)
{
	int		index_nl;
	char	*printed;
	char	*temp;

	index_nl = ft_eol_finder(*stack);
	if (index_nl == -1)
	{
		if ((*stack)[0] != '\0')
		{
			printed = ft_substr(*stack, 0, ft_strlen(*stack));
			free(*stack);
			*stack = NULL;
			return (printed);
		}
		free(*stack);
		*stack = NULL;
		return (NULL);
	}
	printed = ft_substr(*stack, 0, index_nl + 1);
	temp = ft_substr(*stack, index_nl + 1, ft_strlen(*stack) - index_nl - 1);
	free(*stack);
	*stack = temp;
	return (printed);
}

char	*get_next_line(int fd)
{
	static char	*stack;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)ft_cal_z(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	stack = read_line(fd, stack, buffer);
	free(buffer);
	if (!stack)
		return (NULL);
	line = extract_line(&stack);
	return (line);
}
