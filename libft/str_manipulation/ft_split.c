/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:25:13 by jlacaze-          #+#    #+#             */
/*   Updated: 2024/11/29 23:34:46 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countword(char const *str, char c)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
	}
	return (count);
}

static void	*ft_free(char **splitted, int i)
{
	while (--i >= 0)
		free(splitted[i]);
	free(splitted);
	return (NULL);
}

static char	*ft_extract_word(const char *str, char c)
{
	size_t	word_len;

	word_len = 0;
	while (str[word_len] && str[word_len] != c)
		word_len++;
	return (ft_substr(str, 0, word_len));
}

char	**ft_split(char const *str, char c)
{
	char	**splitted;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	splitted = malloc((ft_countword(str, c) + 1) * sizeof(char *));
	if (!splitted)
		return (NULL);
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
		{
			splitted[i] = ft_extract_word(str, c);
			if (!splitted[i++])
				return (ft_free(splitted, i - 1));
			str += ft_strlen(splitted[i - 1]);
		}
	}
	splitted[i] = NULL;
	return (splitted);
}
