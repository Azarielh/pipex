/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:07:56 by jlacaze-          #+#    #+#             */
/*   Updated: 2025/02/17 15:25:27 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"


int	select_flag_n_print(char flag, va_list args)
{
	int				len;
	unsigned long	tmp_ptr;

	len = 0;
	if (flag == '%')
		len = ft_putchar_fd('%', 1);
	if (flag == 'c')
		len = ft_putchar_fd(va_arg(args, int), 1);
	if (flag == 's')
		len = ft_putstr_fd(va_arg(args, char *), 1);
	if (flag == 'p')
	{
		tmp_ptr = va_arg(args, unsigned long);
		if ((void *)tmp_ptr == NULL)
			return (write(1, "(nil)", 5));
		len = write(1, "0x", 2);
		len += ft_puthex(tmp_ptr, flag);
	}
	if (flag == 'd' || flag == 'i')
		len = ft_putnbr_fd(va_arg(args, int), 1);
	if (flag == 'u')
		len = ft_putnbr_deci(va_arg(args, unsigned int));
	else if (flag == 'x' || flag == 'X')
		len = ft_puthex(va_arg(args, unsigned int), flag);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	index;
	size_t	printed_len;

	index = -1;
	printed_len = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[++index])
	{
		if (str[index] != '%')
			printed_len += ft_putchar_fd(str[index], 1);
		else
		{
			if (ft_are_u_1_of_u(str[index + 1], "cspdiuxX%"))
				printed_len += select_flag_n_print(str[++index], args);
			else
				return (ft_putstr_fd("There is a flag error in your input", 1));
		}
	}
	va_end(args);
	return (printed_len);
}
