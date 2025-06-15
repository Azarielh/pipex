/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:22:25 by jlacaze-          #+#    #+#             */
/*   Updated: 2025/02/11 00:07:44 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long	ft_puthex(unsigned long nb, char caps)
{
	char			*base;
	long			reste;
	unsigned long	printed_len;
	int				temp;

	base = "0123456789abcdef";
	if (caps == 'X')
		base = "0123456789ABCDEF";
	printed_len = 0;
	reste = nb % 16;
	nb = nb / 16;
	if (nb > 0)
	{
		temp = ft_puthex(nb, caps);
		if (temp == -1)
			return (-1);
		printed_len += temp;
	}
	temp = ft_putchar_fd(base[reste], 1);
	if (temp == -1)
		return (-1);
	printed_len += temp;
	return (printed_len);
}
