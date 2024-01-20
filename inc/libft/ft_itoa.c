/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 19:58:28 by alappas           #+#    #+#             */
/*   Updated: 2023/05/26 01:22:30 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(int n)

{
	int	i;

	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_sign(int n)

{
	int	sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	return (sign);
}

char	*ft_limit(int n)

{
	char	*str1;

	str1 = NULL;
	if (n == INT_MIN)
		str1 = ft_strdup("-2147483648");
	else
		str1 = (ft_strdup("0"));
	return (str1);
}

char	*ft_itoa(int n)

{
	int		len;
	int		sign;
	char	*str;

	len = 0;
	if (n == INT_MIN || n == 0)
		return (ft_limit(n));
	len = ft_len(n);
	sign = ft_sign(n);
	if (n < 0)
		len = len + 1;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (n != 0)
	{
		str[--len] = (char)((n % 10) * sign + '0');
		n /= 10;
	}
	len--;
	if (sign == -1)
		str[len] = '-';
	return (str);
}
