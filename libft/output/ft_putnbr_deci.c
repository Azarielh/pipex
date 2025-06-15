/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_deci.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 00:00:00 by jlacaze-          #+#    #+#             */
/*   Updated: 2025/02/11 00:07:59 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Need to be transform into putnbr_base
long long	ft_putnbr_deci(unsigned long nb)
{
	long long	unb;
	long long	len;

	len = 0;
	unb = nb;
	if (unb >= 10)
		len += ft_putnbr_deci(unb / 10);
	len += ft_putchar_fd((unb % 10) + '0', 1);
	return (len);
}
