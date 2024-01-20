/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:50:41 by alappas           #+#    #+#             */
/*   Updated: 2023/05/19 14:46:41 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *str, size_t dstsize)

{
	size_t	len;

	len = 0;
	if (dstsize == 0 && *str)
	{
		while (*str != '\0')
		{
			str++;
			len++;
		}
		return (len);
	}
	while (*(str + len) && --dstsize)
		*dst++ = *(str + len++);
	*dst = '\0';
	while (*(str + len))
		len++;
	return (len);
}
