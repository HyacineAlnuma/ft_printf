/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:55:32 by halnuma           #+#    #+#             */
/*   Updated: 2024/11/18 17:51:06 by halnuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_putnbr_base_fd(size_t n, char *base, int fd)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_base_fd(n * -1, base, fd);
	}
	else
	{
		if (n >= base_len)
		{
			ft_putnbr_base_fd((n / base_len), base, fd);
			ft_putchar_fd(base[n % base_len], fd);
		}
		else
		{
			ft_putchar_fd(base[n % base_len], fd);
		}
	}
}
