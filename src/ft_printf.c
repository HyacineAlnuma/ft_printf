/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:02:04 by halnuma           #+#    #+#             */
/*   Updated: 2024/11/19 12:59:54 by halnuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int	ft_printf(const char *input, ...)
{
	va_list			vars;
	size_t			i;
	int				ival;
	char			*sval;
	unsigned int	uval;
	size_t			mval;
	int				count;

	count = 0;
	if (!input)
		return (count);
	va_start(vars, input);
	i = 0;
	while (input[i])
	{
		if (input[i] != '%')
		{
			ft_printchar(input[i]);
			count++;
		}
		else
		{
			if (input[i + 1] == 'c')
			{
				ival = va_arg(vars, int);
				if (!ival)
					ft_printchar(0);
				else
					ft_printchar(ival);
				count++;
			}
			if (input[i + 1] == 's')
			{
				sval = va_arg(vars, char *);
				if (!sval)
				{
					ft_printstr("(null)");
					count += 6;
				}
				else
					count += ft_printstr(sval);
			}
			if (input[i + 1] == 'p')
			{
				mval = va_arg(vars, size_t);
				if (!mval)
				{
					ft_printstr("(nil)");
					count += 5;
				}
				else
				{
					count += ft_printstr("0x");
					count += ft_ptrlen(mval, "0123456789abcdef", 0);
					ft_putnbr_base(mval, "0123456789abcdef");
				}
			}
			if (input[i + 1] == 'd')
			{
				ival = va_arg(vars, int);
				if (!ival)
				{
					ft_printchar('0');
					count++;
				}
				else
				{
					ft_printnbr(ival);
					count += ft_nbrlen(ival, 0);
				}
			}
			if (input[i + 1] == 'i')
			{
				ival = va_arg(vars, int);
				if (!ival)
				{
					ft_printchar('0');
					count++;
				}
				else
				{
					ft_printnbr(ival);
					count += ft_nbrlen(ival, 0);
				}
			}
			if (input[i + 1] == 'u')
			{
				uval = va_arg(vars, unsigned int);
				if (!uval)
				{
					ft_printchar('0');
					count++;
				}
				else
				{
					ft_putunbr(uval);
					count += ft_unbrlen(uval, 0);
				}
			}
			if (input[i + 1] == 'x')
			{
				uval = va_arg(vars, unsigned int);
				if (!uval)
				{
					ft_printchar('0');
					count++;
				}
				else
				{
					ft_putunbr_base(uval, "0123456789abcdef");
					count += ft_unbrlen_base(uval, "0123456789abcdef", 0);
				}
			}
			if (input[i + 1] == 'X')
			{
				uval = va_arg(vars, unsigned int);
				if (!uval)
				{
					ft_printchar('0');
					count++;
				}
				else
				{
					ft_putunbr_base(uval, "0123456789ABCDEF");
					count += ft_unbrlen_base(uval, "0123456789ABCDEF", 0);
				}
			}
			if (input[i + 1] == '%')
			{
				ft_printchar('%');
				count++;
			}
			i++;
		}
		i++;
	}
	va_end(vars);
	return (count);
}

//Faire en sorte que les fonctions gerent elles meme si NULL
//Appeler ft_len dans chaque fonction comme ca celle-ci retournent directement la len
//Mettre toutes les conditions dans une fonction a part

//cc *.c utils/*.c -I../includes -L.. -lftprintf

// int	main(void)
// {
// 	char c = '0';
// 	char *s = "test";
// 	int	d = -456;
// 	int	i = 123456789;
// 	int u = 123;
// 	void	*p = &i;
	
// 	//  ft_printf("FT_PRINTF:\nchar:%c\nstring:%s\npointer:%p\ndecimal:%d\nint:%i\nudec:%u\nhex-low:%x\nhex-up:%X\nsign:%%\n", c, s, p, d, i, u, i, i);
// 	//  printf("\nREAL PRINTF:\nchar:%c\nstring:%s\npointer:%p\ndecimal:%d\nint:%i\nudec:%u\nhex-low:%x\nhex-up:%X\nsign:%%\n", c, s, p, d, i, u, i, i);
// 	//  ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
// 	//  printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
// 	//  ft_printf("%p %u %x\n", p, -42, -42);
// 	//  printf("%p %u %x", p, -42, -42);
// 	// ft_printf("%p\n", -1);
// 	// printf("%p\n", -1);
// 	printf("%i\n", printf("%x\n", -1));
// 	printf("%i\n", ft_printf("%x\n", -1));
// 	//ft_printf("%p\n", -1);
// 	return (0);
// }
