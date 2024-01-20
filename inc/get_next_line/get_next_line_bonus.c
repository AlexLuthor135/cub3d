/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:07:29 by alappas           #+#    #+#             */
/*   Updated: 2023/08/01 03:10:39 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <string.h>

void	clean_list(t_line **list)

{
	int		i;
	int		j;
	t_line	*new_node;
	t_line	*last_node;
	char	*buf;

	if (list == NULL)
		return ;
	last_node = ft_listlast(*list);
	i = 0;
	j = 0;
	while (last_node->str[i] && last_node->str[i] != '\n')
		i++;
	buf = malloc(BUFFER_SIZE + 1);
	new_node = malloc(sizeof(t_line));
	if (buf == NULL || new_node == NULL)
		return ;
	while (last_node->str[i] && last_node->str[++i])
		buf[j++] = last_node->str[i];
	buf[j] = '\0';
	new_node->str = buf;
	new_node->next = NULL;
	dealloc(list, new_node, buf);
}

char	*ft_line(t_line *list)

{
	int		len;
	char	*next_str;

	if (list == NULL)
		return (NULL);
	len = str_len(list);
	next_str = malloc(len + 1);
	if (next_str == NULL)
		return (NULL);
	ft_str_cpy(list, next_str);
	return (next_str);
}

void	add_str(t_line **list, char *buf)

{
	t_line	*new_node;
	t_line	*last_node;

	if (list == NULL)
		return ;
	last_node = ft_listlast(*list);
	new_node = malloc(sizeof(t_line));
	if (new_node == NULL)
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->str = buf;
	new_node->next = NULL;
}

void	create_list(t_line **list, int fd)

{
	int		char_read;
	char	*buf;

	while (!find_n(*list) || fd < 0)
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return ;
		char_read = read(fd, buf, BUFFER_SIZE);
		if (!char_read)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		add_str(list, buf);
	}
}

char	*get_next_line(int fd)

{
	static t_line	*list[OPEN_MAX];
	char			*next_line;
	t_line			*param;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		if (list[fd])
		{
			param = (list[fd])->next;
			if ((list[fd]))
			{
				free((list[fd])->str);
				free((list[fd]));
			}
			list[fd] = param;
		}
		return (NULL);
	}
	create_list(&list[fd], fd);
	if (list[fd] == NULL)
		return (NULL);
	next_line = ft_line(list[fd]);
	clean_list(&list[fd]);
	return (next_line);
}
