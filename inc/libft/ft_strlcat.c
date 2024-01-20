/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 10:51:24 by alappas           #+#    #+#             */
/*   Updated: 2023/05/25 20:31:13 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)

{
	size_t	len;
	size_t	slen;
	size_t	dsize;
	size_t	qsize;

	len = 0;
	slen = ft_strlen(src);
	dsize = dstsize;
	while (*dst && dstsize > 0)
	{
		dst++;
		len++;
		dstsize--;
	}
	qsize = dsize - len;
	while (*src && qsize > 1)
	{
		*dst++ = *src++;
		qsize--;
	}
	if (qsize == 1 || *src == 0)
		*dst = '\0';
	return (len + slen);
}
