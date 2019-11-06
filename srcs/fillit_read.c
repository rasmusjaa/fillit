/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:00:05 by npimenof          #+#    #+#             */
/*   Updated: 2019/11/06 13:30:23 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_bloc	*ft_create_bloc(char *bloc, char c)
{
	t_bloc	*temp;

	if (!(temp = (t_bloc *)malloc(sizeof(t_bloc))))
		return (NULL);
	temp->str = ft_strdup(bloc);
	temp->c = c + 1;
	free(bloc);
	temp->next = NULL;
	return (temp);
}

int				create_list(int fd, t_bloc **bloc_start)
{
	int		row;
	char	*tmp;
	char	*line;
	char	*bloc;
	t_bloc	*bloc_node;

	*bloc_start = ft_create_bloc((ft_strdup("Tervetuloa")), 'A' - 2);
	bloc_node = *bloc_start;
	row = 0;
	while ((ft_get_next_line(fd, &bloc) > 0))
	{
		row++;
		while ((row + 1) % 5 != 0)
		{
			ft_get_next_line(fd, &line);
			tmp = ft_strjoin(bloc, line);
			free(bloc);
			free(line);
			bloc = tmp;
			row++;
		}
		bloc_node->next = ft_create_bloc(bloc, bloc_node->c);
		bloc_node = bloc_node->next;
	}
	return (0);
}
