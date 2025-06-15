/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:10:28 by jlacaze-          #+#    #+#             */
/*   Updated: 2024/12/27 14:37:18 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_eol_finder(const char *s) // stcnl
{
	size_t	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

size_t	ft_strlen(const char *str) // ft_l
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *old_stack, char *buffer)
{
	char	*new_stack;
	size_t	i;
	size_t	j;

	new_stack = ft_cal_z(ft_strlen(old_stack) + ft_strlen(buffer)+ 1, 1);
	if (!new_stack)
	{
		free(old_stack);
		return (NULL);
	}
	i = 0;
	while (old_stack[i])
	{
		new_stack[i] = old_stack[i];
		i++;
	}
	j = 0;
	while (buffer[j])
	{
		new_stack[i + j] = buffer[j];
		j++;
	}
	new_stack[i + j] = '\0';
	free(old_stack);
	return (new_stack);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	if (start >= ft_strlen(s))
	{
		sub = (char *)ft_cal_z(1, sizeof(char));
		if (!sub)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	sub = (char *)ft_cal_z(len + 1, sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

void	*ft_cal_z(size_t num, size_t size)
{
	size_t	i;
	char	*p;
	void	*arr;

	arr = malloc(num * size);
	if (!arr)
		return (NULL);
	i = 0;
	p = (char *)arr;
	while (i < num * size)
	{
		p[i] = 0;
		i++;
	}
	return (arr);
}
