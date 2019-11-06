/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 10:26:36 by npimenof          #+#    #+#             */
/*   Updated: 2019/11/06 13:30:34 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// char		*new_grid(int nb)
// {
// 	int		i;
// 	int		j;
// 	char	*grid;

// 	i = 0;
// 	grid = (char *)malloc(sizeof(char) * (nb * nb + nb + 1));
// 	while (i < (nb * nb + nb))
// 	{
// 		j = 0;
// 		while (j < nb && i < nb * nb + nb)
// 		{
// 			grid[i] = '.';
// 			i++;
// 			j++;
// 		}
// 		grid[i] = '\n';
// 		i++;
// 	}
// 	grid[i] = 0;
// 	return (grid);
// }

// int			test_bloc(int i, int size, char *grid, t_bloc *elem)
// {
// 	if (i + (elem->x)[3] + ((elem->y)[3] * (size + 1)) > size * (size + 1))
// 		return (-1);
// 	if (i % (size + 1) + (elem->x)[3] > size)
// 		return (1);
// 	if (grid[i + (elem->x)[0] + ((elem->y)[0] * (size + 1))] != '.')
// 		return (1);
// 	if (grid[i + (elem->x)[1] + ((elem->y)[1] * (size + 1))] != '.')
// 		return (1);
// 	if (grid[i + (elem->x)[2] + ((elem->y)[2] * (size + 1))] != '.')
// 		return (1);
// 	if (grid[i + (elem->x)[3] + ((elem->y)[3] * (size + 1))] != '.')
// 		return (1);
// 	return (0);
// }

// void		place_bloc_on_grid(int g_index, char *grid, t_bloc *elem, int size)
// {
// 	int		i;
// 	char	c;

// 	i = 0;
// 	c = elem->c;
// 	if (grid[g_index + (elem->x)[i] + ((elem->y)[i] * (size + 1))] != '.')
// 		c = '.';
// 	while (i < 4)
// 	{
// 		grid[g_index + (elem->x)[i] + ((elem->y)[i] * (size + 1))] = c;
// 		i++;
// 	}
// }

// int			put_bloc(char *grid, t_bloc *elem, int grid_size)
// {
// 	int		i;
// 	int		ret;

// 	i = -1;
// 	while (grid[++i])
// 	{
// 		while (grid[i + (elem->x)[0]] != '.' && grid[i])
// 			i++;
// 		if ((ret = test_bloc(i, grid_size, grid, elem)) == 0)
// 		{
// 			if (elem->next == NULL)
// 			{
// 				place_bloc_on_grid(i, grid, elem, grid_size);
// 				return (0);
// 			}
// 			place_bloc_on_grid(i, grid, elem, grid_size);
// 			if (!put_bloc(grid, elem->next, grid_size) && elem->next != NULL)
// 				return (0);
// 			else
// 				place_bloc_on_grid(i, grid, elem, grid_size);
// 		}
// 		if (ret == -1)
// 			return (1);
// 	}
// 	return (1);
// }

// int			ft_pow(int n)
// {
// 	return (n * n);
// }

// int			ft_sqrt(int n)
// {
// 	int		r;

// 	r = 0;
// 	if (n < 0)
// 		return (0);
// 	while (n > ft_pow(r))
// 		r++;
// 	return (r);
// }

// char		*solve(int blocs, t_bloc *start)
// {
// 	int		min;
// 	int		max;
// 	char	*grid;

// 	min = ft_sqrt(blocs * 4);
// 	max = blocs * 4;
// 	while (min < max)
// 	{
// 		grid = new_grid(min);
// 		if (put_bloc(grid, start->next, min) == 0)
// 			return (grid);
// 		free(grid);
// 		grid = NULL;
// 		min++;
// 	}
// 	return (0);
// }

int			count_blocs(t_bloc *elem)
{
	int		blocs;

	blocs = 0;
	while (elem->next != NULL)
	{
		elem = elem->next;
		blocs++;
	}
	return (blocs);
}

// void		bloc_origo(t_bloc *elem)
// {
// 	int		i;

// 	(elem->origo_xy)[0] = 3;
// 	(elem->origo_xy)[1] = 3;
// 	i = 0;
// 	while (i < 4)
// 	{
// 		if ((elem->x[i]) < (elem->origo_xy)[0])
// 			(elem->origo_xy)[0] = (elem->x[i]);
// 		if ((elem->y[i]) < (elem->origo_xy)[1])
// 			(elem->origo_xy)[1] = (elem->y[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < 4)
// 	{
// 		(elem->x)[i] = (elem->x)[i] - (elem->origo_xy)[0];
// 		(elem->y)[i] = (elem->y)[i] - (elem->origo_xy)[1];
// 		i++;
// 	}
// }

// int			neighbours(int i, char c, char *str)
// {
// 	int		total;

// 	total = 0;
// 	if (i - 4 >= 0 && (str[i - 4] == '#' || str[i - 4] == c))
// 		total++;
// 	if (i + 4 <= 15 && (str[i + 4] == '#' || str[i + 4] == c))
// 		total++;
// 	if (i % 4 == 0)
// 		if (i + 1 <= 15)
// 			if (str[i + 1] == '#' || str[i + 1] == c)
// 				total++;
// 	if (i % 4 == 3)
// 		if (i - 1 <= 15)
// 			if (str[i - 1] == '#' || str[i - 1] == c)
// 				total++;
// 	if (i % 4 == 1 || i % 4 == 2)
// 	{
// 		if (i + 1 <= 15)
// 			if (str[i + 1] == '#' || str[i + 1] == c)
// 				total++;
// 		if (i - 1 <= 15)
// 			if (str[i - 1] == '#' || str[i - 1] == c)
// 				total++;
// 	}
// 	return (total);
// }

t_temp		*set_values(void)
{
	t_temp	*val;

	val = malloc(sizeof(t_temp));
	val->i = 0;
	val->dot = 0;
	val->hash1 = 0;
	val->hash2 = 0;
	val->j = 0;
	return (val);
}

// int			validate_bloc(t_bloc *elem, t_temp *val)
// {
// 	while ((elem->str)[val->i])
// 	{
// 		if ((elem->str)[val->i] == '.')
// 			val->dot++;
// 		if (((elem->str)[val->i] == '#' || (elem->str)[val->i] == elem->c) &&
// 				neighbours(val->i, elem->c, elem->str) > 0)
// 		{
// 			if (val->j == 5)
// 				return (1);
// 			elem->x[val->j] = val->i % 4;
// 			elem->y[val->j] = val->i / 4;
// 			val->j++;
// 			val->hash1++;
// 		}
// 		if (((elem->str)[val->i] == '#' || (elem->str)[val->i] == elem->c) &&
// 				neighbours(val->i, elem->c, elem->str) > 1)
// 			val->hash2++;
// 		val->i++;
// 	}
// 	if (val->i == 16 && val->dot == 12 && val->hash1 == 4 && val->hash2 >= 1)
// 	{
// 		bloc_origo(elem);
// 		return (0);
// 	}	
// 	return (1);
// }

int			ft_blociter(t_bloc *lst, int (*f)(t_bloc *elem, t_temp *val))
{
	t_bloc	*tmp;
	t_temp	*val;

	val = set_values();
	if (lst)
	{
		tmp = lst;
		while (tmp)
		{
			f(tmp, val);
			tmp = tmp->next;
		}
	}
	free(val);
	return (0);
}

// int			ft_blociter(t_bloc *lst, int (*f)(t_bloc *elem))
// {
// 	t_bloc	*tmp;

// 	if (lst)
// 	{
// 		tmp = lst;
// 		while (tmp)
// 		{
// 			f(tmp);
// 			tmp = tmp->next;
// 		}
// 	}
// 	return (0);
// }

// t_bloc		*ft_create_bloc(char *bloc, char c)
// {
// 	t_bloc	*temp;

// 	if (!(temp = (t_bloc *)malloc(sizeof(t_bloc))))
// 		return (NULL);
// 	temp->str = ft_strdup(bloc);
// 	temp->c = c + 1;
// 	free(bloc);
// 	temp->next = NULL;
// 	return (temp);
// }

// int			create_list(int fd, t_bloc **bloc_start)
// {
// 	int		row;
// 	char	*tmp;
// 	char	*line;
// 	char	*bloc;
// 	t_bloc	*bloc_node;

// 	*bloc_start = ft_create_bloc((ft_strdup("Tervetuloa")), 'A' - 2);
// 	bloc_node = *bloc_start;
// 	row = 0;
// 	while ((ft_get_next_line(fd, &bloc) > 0))// KORJAA YLIMAARAINEN NEWLINE
// 	{
// 		row++;
// 		while ((row + 1) % 5 != 0)
// 		{
// 			ft_get_next_line(fd, &line);
// 			tmp = ft_strjoin(bloc, line);
// 			free(bloc);
// 			free(line);
// 			bloc = tmp;
// 			row++;
// 		}
// 		bloc_node->next = ft_create_bloc(bloc, bloc_node->c);
// 		bloc_node = bloc_node->next;
// 	}
// 	return (0);
// }

void		del_blocs(t_bloc **start)
{
	t_bloc	*tmp;

	while (*start)
	{
		tmp = *start;
		*start = (*start)->next;
		free(tmp->str);
		tmp->str = NULL;
		free(tmp);
		tmp = NULL;
	}
}

int			returns(char *str)
{
	ft_putendl(str);
	return (1);
}

int			main(int ac, char **av)
{
	int		fd;
	t_bloc	*bloc_start;
	char	*result;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
			return (returns("error"));
		else
			create_list(fd, &bloc_start);
		ft_blociter(bloc_start->next, validate_bloc);
		// ft_blociter(bloc_start, bloc_origo);
		result = solve(count_blocs(bloc_start), bloc_start);
		del_blocs(&bloc_start);
		ft_putstr(result);
		free(result);
		close(fd);
	}
	else
		return (returns("usage: ./fillit [input_file]"));
	// while (1);
	return (0);
}
