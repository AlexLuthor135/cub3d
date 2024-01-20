/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:33:01 by alappas           #+#    #+#             */
/*   Updated: 2023/05/16 17:34:45 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)

{
	size_t	i;
	char	*s2;
	char	letter;

	letter = c;
	i = 0;
	s2 = (char *) s;
	while (i < n)
	{
		if (s2[i] == letter)
		{
			return (&(s2[i]));
		}
		i++;
	}
	return (NULL);
}
