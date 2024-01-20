/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:11:24 by alappas           #+#    #+#             */
/*   Updated: 2023/05/18 16:41:47 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)

{
	size_t	i;
	char	*array;

	i = 0;
	array = malloc(count * size);
	if (count * size > SIZE_MAX)
		return (NULL);
	if (array == NULL)
		return (0);
	ft_bzero(array, size * count);
	return (array);
}
