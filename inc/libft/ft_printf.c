/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 18:03:34 by alappas           #+#    #+#             */
/*   Updated: 2024/04/14 01:02:07 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(uintptr_t v, int base)

{
	int	len;

	len = 0;
	while (v != 0)
	{
		len++;
		v /= base;
	}
	return (len);
}

int	ft_format(va_list args, char f)
{
	int	value;

	value = 0;
	if (f == 'c')
		value += write(1, &(char){(char)va_arg(args, int)}, 1);
	else if (f == 's')
		value += ft_printf_s(va_arg(args, char *));
	else if (f == 'p')
		value += ft_printf_p(va_arg(args, unsigned long long));
	else if (f == 'd' || f == 'i')
		value += ft_printf_d(va_arg(args, int));
	else if (f == 'u')
		value += ft_printf_undec(va_arg(args, unsigned int));
	else if (f == 'x')
		value += ft_printf_x(va_arg(args, unsigned int), 0);
	else if (f == 'X')
		value += ft_printf_x(va_arg(args, unsigned int), 32);
	else if (f == '%')
		value += write(1, "%", 1);
	return (value);
}

int	ft_printf(const char *s, ...)

{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start (args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			len += ft_format(args, s[i + 1]);
			i++;
		}
		else
			len += write(1, &s[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
