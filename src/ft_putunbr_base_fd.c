/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:56:17 by halnuma           #+#    #+#             */
/*   Updated: 2024/11/18 17:56:19 by halnuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_putunbr_base_fd(unsigned int n, char *base, int fd)
{
	unsigned int	base_len;

	base_len = ft_strlen(base);
	if (n >= base_len)
	{
		ft_putunbr_base_fd((n / base_len), base, fd);
		ft_putchar_fd(base[n % base_len], fd);
	}
	else
	{
		ft_putchar_fd(base[n % base_len], fd);
	}
}