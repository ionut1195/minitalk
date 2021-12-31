/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:42:34 by itomescu          #+#    #+#             */
/*   Updated: 2021/10/25 15:52:53 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_convert(va_list ptr, char c);
int		u_conv(va_list ptr);
int		d_conv(va_list ptr);
int		p_conv(va_list ptr);
int		c_conv(va_list ptr);
int		s_conv(va_list ptr);
int		x_conv(va_list ptr, char c);
void	ft_putnbr_u(unsigned int n, int *pt);
void	ft_putnbr_id(int n, int *pt);
void	ft_hex_p(unsigned long int i, int *p);
void	ft_hex(unsigned int i, int *p, char c);
void	ft_putchar(char c);

#endif
