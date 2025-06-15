/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlacaze- <jlacaze-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 23:58:56 by jlacaze-          #+#    #+#             */
/*   Updated: 2025/02/10 23:42:40 by jlacaze-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

size_t	ft_putstr_fd(char *str, int fd)
{
	size_t	len;

	if (!str)
		return (write(1, "(null)", 6));
	len = write(fd, str, ft_strlen(str));
	return (len);
}
