/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 13:32:42 by alappas           #+#    #+#             */
/*   Updated: 2024/04/14 01:02:14 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_s(char *string)

{
	int	index;

	index = 0;
	if (!string)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (string[index] != '\0')
	{
		write(1, &string[index], 1);
		index++;
	}
	return (index);
}

int	ft_printf_d(int n)
{
	int	dlen;

	dlen = 0;
	if (n == -2147483648)
	{
		write(1, &(char){'-'}, 1);
		write(1, &(char){'2'}, 1);
		dlen += ft_printf_d(147483648) + 2;
	}
	else if (n < 0)
	{
		write(1, &(char){'-'}, 1);
		n = -n;
		dlen += ft_printf_d(n) + 1;
	}
	else if (n > 9)
	{
		dlen += ft_printf_d(n / 10);
		dlen += ft_printf_d(n % 10);
	}
	else
		dlen += write(1, &(char){n + 48}, 1);
	return (dlen);
}

int	ft_printf_p(unsigned long long ptr)
{
	int	len;

	len = 0;
	if (ptr == 0)
		return (write (1, "(nil)", 5));
	len += write (1, "0x", 2);
	len += ft_printf_x(ptr, 0);
	return (len);
}

int	ft_printf_x(unsigned long long v, int ascii)
{
	int	xlen;

	xlen = 0;
	if (v == 0)
		return (write(1, &(char){'0'}, 1));
	if (v >= 16)
	{
		xlen += ft_printf_x(v / 16, ascii);
		xlen += ft_printf_x(v % 16, ascii);
	}
	else
	{
		if (v <= 9)
			write(1, &(char){(v + '0')}, 1);
		else
			write(1, &(char){(v - 10 + ('a' - ascii))}, 1);
		xlen++;
	}
	return (xlen);
}

int	ft_printf_undec(unsigned int n)

{
	int	len;

	len = 0;
	if (n >= 10)
	{
		len += ft_printf_undec ((n / 10));
		len += ft_printf_undec (n % 10);
	}
	else if (n < 10)
		len += write(1, &(char){n + 48}, 1);
	return (len);
}
