/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:58:51 by halnuma           #+#    #+#             */
/*   Updated: 2024/11/19 12:42:01 by halnuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *input, ...);
void	ft_putnbr_base(size_t n, char *base);
int		ft_ptrlen(size_t n, char *base, int count);
void	ft_putunbr_base(unsigned int n, char *base);
int		ft_unbrlen_base(unsigned int n, char *base, int count);
void	ft_putunbr(unsigned int n);
int		ft_unbrlen(unsigned int n, int count);
int		ft_printchar(char c);
int		ft_printstr(char *s);
void	ft_printnbr(int n);
int		ft_nbrlen(int n, int count);

#endif