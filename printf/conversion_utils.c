/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:31:05 by itomescu          #+#    #+#             */
/*   Updated: 2021/10/25 15:53:24 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_id(int n, int *pt)
{
	if (n < 0)
	{
		if (n == -2147483648)
		{
			write(1, "-2147483648", 11);
			(*pt) += 11;
			return ;
		}
		else
		{
			ft_putchar('-');
			n = -1 * n;
			(*pt)++;
		}
	}
	if (n >= 10)
	{
		ft_putnbr_id(n / 10, pt);
		ft_putnbr_id(n % 10, pt);
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
		(*pt)++;
	}
}

void	ft_putnbr_u(unsigned int n, int *pt)
{
	if (n >= 10)
	{
		ft_putnbr_u(n / 10, pt);
		ft_putnbr_u(n % 10, pt);
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
		(*pt)++;
	}
}

void	ft_hex(unsigned int i, int *p, char c)
{
	int	letter;

	if (c == 'x')
		letter = 87;
	if (c == 'X')
		letter = 55;
	if (i >= 16)
	{
		ft_hex(i / 16, p, c);
		ft_hex(i % 16, p, c);
	}
	else if (i <= 9)
	{
		ft_putchar(i + 48);
		(*p)++;
	}
	else if (i <= 16)
	{
		ft_putchar(i + letter);
		(*p)++;
	}
}

void	ft_hex_p(unsigned long int i, int *p)
{
	if (i >= 16)
	{
		ft_hex_p(i / 16, p);
		ft_hex_p(i % 16, p);
	}
	else if (i <= 9)
	{
		ft_putchar(i + 48);
		(*p)++;
	}
	else if (i <= 16)
	{
		ft_putchar(i + 87);
		(*p)++;
	}
}
