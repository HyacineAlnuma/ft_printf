/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:02:04 by halnuma           #+#    #+#             */
/*   Updated: 2024/11/14 15:27:31 by halnuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

int	ft_printf(const char *input, ...)
{
	va_list			vars;
	size_t			i;
	int				ival;
	char			*sval;
	unsigned int	uval;

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
				ft_putchar_fd(ival, 1);
			}
			if (input[i + 1] == 's')
			{
				sval = va_arg(vars, char *);
				ft_putstr_fd(sval, 1);
			}
			// if (input[i + 1] == 'p')
			// {
			// 	(void *)current = va_arg(vars, (void *));
			// 	ft_putstr_fd(current, 1);
			// }
			if (input[i + 1] == 'd')
			{
				ival = va_arg(vars, int);
				ft_putnbr_fd(ival, 1);
			}
			if (input[i + 1] == 'i')
			{
				ival = va_arg(vars, int);
				ft_putnbr_fd(ival, 1);
			}
			if (input[i + 1] == 'u')
			{
				uval = va_arg(vars, unsigned int);
				ft_putnbr_fd(uval, 1);
			}
			// if (input[i + 1] == 'x')
			// {
			// 	(char *)current = va_arg(vars, (char *));
			// 	ft_putnbr_base_fd(current, 0, 1);
			// }
			// if (input[i + 1] == 'X')
			// {
			// 	(char *)current = va_arg(vars, (char *));
			// 	ft_putnbr_base_fd(current, 1, 1);
			// }
			if (input[i + 1] == '%')
			{
				ival = va_arg(vars, int);
				ft_putchar_fd(ival, 1);
			}
			i += 2;
		}
		i++;
	}
	va_end(vars);
	return (0);
}

int	main(void)
{
	ft_printf("yo %i test", 2);
	return (0);
}
