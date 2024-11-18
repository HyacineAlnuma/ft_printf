/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:22:23 by halnuma           #+#    #+#             */
/*   Updated: 2024/11/18 17:56:30 by halnuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_putunbr_fd(unsigned int n, int fd)
{
	if (n > 9)
	{
		ft_putunbr_fd((n / 10), fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
	else
	{
		ft_putchar_fd((n % 10) + '0', fd);
	}
}