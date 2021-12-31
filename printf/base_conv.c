/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:34:28 by itomescu          #+#    #+#             */
/*   Updated: 2021/10/25 15:38:07 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	c_conv(va_list ptr)
{
	int		len;
	char	c;

	len = 1;
	c = (char)va_arg(ptr, int);
	write(1, &c, 1);
	return (len);
}

int	ft_convert(va_list ptr, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += c_conv(ptr);
	else if (c == 's')
		len += s_conv(ptr);
	else if (c == 'p')
		len += p_conv(ptr);
	else if (c == 'd' || c == 'i')
		len += d_conv(ptr);
	else if (c == 'u')
		len += u_conv(ptr);
	else if (c == 'x' || c == 'X')
		len += x_conv(ptr, c);
	else if (c == '%')
		len += write(1, "%", 1);
	else
	{
		write(1, &c, 1);
		len++;
	}
	return (len);
}
