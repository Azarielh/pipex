/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 23:40:51 by jlacaze-          #+#    #+#             */
/*   Updated: 2024/11/14 20:24:06 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*uns;
	unsigned char	bc;
	size_t			i;

	uns = (unsigned char *)s;
	bc = (unsigned char)c;
	i = 0;
	while (n > 0)
	{
		uns[i] = bc;
		n--;
		i++;
	}
	return (s);
}
