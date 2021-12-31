/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_conv_extended.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:05:03 by itomescu          #+#    #+#             */
/*   Updated: 2021/10/26 12:31:59 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	x_conv(va_list ptr, char c)
{
	unsigned int	i;
	int				len;

	len = 0;
	i = va_arg(ptr, unsigned int);
	ft_hex(i, &len, c);
	return (len);
}

int	s_conv(va_list ptr)
{
	int		len;
	char	*pt;

	pt = va_arg(ptr, char *);
	len = 0;
	if (pt == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (pt[len] != '\0')
	{
		write(1, &pt[len], 1);
		len++;
	}
	return (len);
}

int	p_conv(va_list ptr)
{
	int					len;
	unsigned long int	i;

	len = 0;
	i = va_arg(ptr, unsigned long int);
	if (i == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	write(1, "0x", 2);
	len += 2;
	ft_hex_p(i, &len);
	return (len);
}

int	d_conv(va_list ptr)
{
	int		i;
	int		len;

	len = 0;
	i = va_arg(ptr, int);
	ft_putnbr_id(i, &len);
	return (len);
}

int	u_conv(va_list ptr)
{
	unsigned int	i;
	int				len;

	len = 0;
	i = va_arg(ptr, unsigned int);
	ft_putnbr_u(i, &len);
	return (len);
}
