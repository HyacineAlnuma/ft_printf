/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:29:01 by halnuma           #+#    #+#             */
/*   Updated: 2024/11/19 12:38:37 by halnuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_printnbr(int n)
{
	if (n == INT_MIN)
		ft_printstr("-2147483648");
	else if (n < 0)
	{
		ft_printchar('-');
		ft_printnbr(n * -1);
	}
	else
	{
		if (n > 9)
		{
			ft_printnbr((n / 10));
			ft_printchar((n % 10) + '0');
		}
		else
			ft_printchar((n % 10) + '0');
	}
}

void	ft_putunbr(unsigned int n)
{
	if (n > 9)
	{
		ft_putunbr((n / 10));
		ft_printchar((n % 10) + '0');
	}
	else
	{
		ft_printchar((n % 10) + '0');
	}
}

int	ft_unbrlen(unsigned int n, int count)
{
	if (n > 9)
	{
		count++;
		return (ft_unbrlen((n / 10), count));
	}
	else
	{
		count++;
		return (count);
	}
}

int	ft_nbrlen(int n, int count)
{
	if (n == INT_MIN)
	{
		return (11);
	}
	else if (n < 0)
	{
		count++;
		return (ft_nbrlen((n * -1), count));
	}
	else
	{
		if (n > 9)
		{
			count++;
			return (ft_nbrlen((n / 10), count));
		}
		else
		{
			count++;
			return (count);
		}
	}
}
