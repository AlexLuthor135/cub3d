/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:25:33 by alappas           #+#    #+#             */
/*   Updated: 2023/05/19 14:56:25 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)

{
	size_t			i;
	unsigned char	*s1_s;
	unsigned char	*s2_s;

	i = 0;
	s1_s = (unsigned char *) s1;
	s2_s = (unsigned char *) s2;
	while (i < n)
	{
		if (s1_s[i] != s2_s[i])
			return (s1_s[i] - s2_s[i]);
		i++;
	}
	return (0);
}
