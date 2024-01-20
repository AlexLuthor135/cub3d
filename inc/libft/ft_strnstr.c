/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:59:54 by alappas           #+#    #+#             */
/*   Updated: 2023/05/27 13:23:54 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)

{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char *) haystack);
	while (*haystack && j < len)
	{
		if (*haystack == *needle)
		{
			i = 0;
			while (haystack[i] && needle[i] && j + i < len)
			{
				if (haystack[i] != needle[i])
					break ;
				i++;
			}
			if (needle[i] == '\0')
				return ((char *) haystack);
		}
		haystack += 1;
		j++;
	}
	return (0);
}
