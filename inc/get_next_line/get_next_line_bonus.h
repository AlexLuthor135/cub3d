/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alappas <alappas@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:06:09 by alappas           #+#    #+#             */
/*   Updated: 2023/08/01 03:08:58 by alappas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_line
{
	char			*str;
	struct s_line	*next;
}	t_line;

t_line	*ft_listlast(t_line *lst);
char	*ft_line(t_line *list);
int		find_n(t_line *list);
void	ft_str_cpy(t_line *list, char *string);
int		str_len(t_line *list);
void	dealloc(t_line **list, t_line *new_node, char *buf);
char	*get_next_line(int fd);
void	clean_list(t_line **list);
void	add_str(t_line **list, char *buf);

#endif