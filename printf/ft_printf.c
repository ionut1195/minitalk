/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:26:24 by itomescu          #+#    #+#             */
/*   Updated: 2021/10/25 15:59:43 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		printed;
	int		i;

	va_start(list, str);
	printed = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			write(1, &str[i], 1);
			printed++;
		}
		else
		{
			printed += ft_convert(list, str[i + 1]);
			i++;
		}
		i++;
	}
	va_end(list);
	return (printed);
}
