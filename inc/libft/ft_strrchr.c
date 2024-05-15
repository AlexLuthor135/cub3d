/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:33:08 by alappas           #+#    #+#             */
/*   Updated: 2024/04/14 01:42:31 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)

{
	int		i;
	char	*s1;

	s1 = (char *) s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s1[i] == ((char) c))
		{
			return (&s1[i]);
		}
		i--;
	}
	return (0);
}
