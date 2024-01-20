/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:21:11 by alappas           #+#    #+#             */
/*   Updated: 2023/05/25 21:32:19 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))

{
	t_list	*param;

	if (lst && del)
	{
		while (*lst)
		{
			param = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = param;
		}
	}
}
