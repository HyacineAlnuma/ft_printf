/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:02:04 by halnuma           #+#    #+#             */
/*   Updated: 2024/11/18 17:59:04 by halnuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

//cc *.c -I../includes -L.. -lftprintf

int	ft_printf(const char *input, ...)
{
	va_list			vars;
	size_t			i;
	int				ival;
	char			*sval;
	unsigned int	uval;
	size_t			mval;

	va_start(vars, input);
	i = 0;
	while (input[i])
	{
		if (input[i] != '%')
			ft_putchar_fd(input[i], 1);
		else
		{
			if (input[i + 1] == 'c')
			{
				ival = va_arg(vars, int);
				if (!ival)
					ft_putchar_fd(0, 1);
				else
					ft_putchar_fd(ival, 1);
			}
			if (input[i + 1] == 's')
			{
				sval = va_arg(vars, char *);
				if (!sval)
					ft_putstr_fd("(null)", 1);
				else
					ft_putstr_fd(sval, 1);
			}
			if (input[i + 1] == 'p')
			{
				mval = va_arg(vars, size_t);
				if (!mval)
					ft_putstr_fd("(nil)", 1);
				else
				{
					ft_putstr_fd("0x", 1);
					ft_putnbr_base_fd(mval, "0123456789abcdef", 1);
				}
			}
			if (input[i + 1] == 'd')
			{
				ival = va_arg(vars, int);
				if (!ival)
					ft_putchar_fd('0', 1);
				else
					ft_putnbr_fd(ival, 1);
			}
			if (input[i + 1] == 'i')
			{
				ival = va_arg(vars, int);
				if (!ival)
					ft_putchar_fd('0', 1);
				else
					ft_putnbr_fd(ival, 1);
			}
			if (input[i + 1] == 'u')
			{
				uval = va_arg(vars, unsigned int);
				if (!uval)
					ft_putchar_fd('0', 1);
				else
					ft_putunbr_fd(uval, 1);
			}
			if (input[i + 1] == 'x')
			{
				uval = va_arg(vars, unsigned int);
				if (!uval)
					ft_putchar_fd('0', 1);
				else
					ft_putunbr_base_fd(uval, "0123456789abcdef", 1);
			}
			if (input[i + 1] == 'X')
			{
				uval = va_arg(vars, unsigned int);
				if (!uval)
					ft_putchar_fd('0', 1);
				else
					ft_putunbr_base_fd(uval, "0123456789ABCDEF", 1);
			}
			if (input[i + 1] == '%')
				ft_putchar_fd('%', 1);
			i++;
		}
		i++;
	}
	va_end(vars);
	return (0);
}

int	main(void)
{
	char c = '0';
	char *s = "test";
	int	d = -456;
	int	i = 123456789;
	int u = 123;
	void	*p = &i;
	
	//ft_printf("FT_PRINTF:\nchar:%c\nstring:%s\npointer:%p\ndecimal:%d\nint:%i\nudec:%u\nhex-low:%x\nhex-up:%X\nsign:%%\n", c, s, p, d, i, u, i, i);
	//printf("\nREAL PRINTF:\nchar:%c\nstring:%s\npointer:%p\ndecimal:%d\nint:%i\nudec:%u\nhex-low:%x\nhex-up:%X\nsign:%%\n", c, s, p, d, i, u, i, i);
	ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	ft_printf("%p %u %x\n", p, -42, -42);
	printf("%p %u %x", p, -42, -42);
	return (0);
}
