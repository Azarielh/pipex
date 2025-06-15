/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:48:56 by jlacaze-          #+#    #+#             */
/*   Updated: 2024/12/06 03:08:03 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t				i;
	unsigned char		ud_c;
	const unsigned char	*ud_str;

	i = 0;
	ud_c = (unsigned char)c;
	ud_str = (const unsigned char *)str;
	while (i < n)
	{
		if (ud_str[i] == ud_c)
			return ((void *)&ud_str[i]);
		i++;
	}
	return (NULL);
}
