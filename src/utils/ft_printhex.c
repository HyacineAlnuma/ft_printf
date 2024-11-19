/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:25:42 by halnuma           #+#    #+#             */
/*   Updated: 2024/11/19 12:48:30 by halnuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_putunbr_base(unsigned int n, char *base)
{
	unsigned int	base_len;

	base_len = ft_strlen(base);
	if (n >= base_len)
	{
		ft_putunbr_base((n / base_len), base);
		ft_printchar(base[n % base_len]);
	}
	else
		ft_printchar(base[n % base_len]);
}

int	ft_unbrlen_base(unsigned int n, char *base, int count)
{
	unsigned int	base_len;

	base_len = ft_strlen(base);
	if (n >= base_len)
	{
		count++;
		return (ft_unbrlen_base((n / base_len), base, count));
	}
	else
	{
		count++;
		return (count);
	}
}
