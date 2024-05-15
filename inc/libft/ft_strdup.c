/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:43:26 by alappas           #+#    #+#             */
/*   Updated: 2023/05/19 16:52:17 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)

{
	char	*array;
	int		i;

	i = 0;
	array = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!array)
		return (NULL);
	while (*s1)
		array[i++] = *s1++;
	array[i] = '\0';
	return (array);
}
