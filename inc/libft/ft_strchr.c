/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:05:21 by alappas           #+#    #+#             */
/*   Updated: 2023/05/16 17:36:00 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)

{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != ((char) c))
		i++;
	if (s[i] == ((char) c))
		return ((char *)s + i);
	return (NULL);
}
