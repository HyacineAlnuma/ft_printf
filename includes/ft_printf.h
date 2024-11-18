/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halnuma <halnuma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:58:51 by halnuma           #+#    #+#             */
/*   Updated: 2024/11/18 17:58:28 by halnuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *input, ...);
void	ft_putnbr_base_fd(size_t n, char *base, int fd);
void	ft_putunbr_base_fd(unsigned int n, char *base, int fd);
void	ft_putunbr_fd(unsigned int n, int fd);

#endif