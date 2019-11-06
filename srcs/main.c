/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <npimenof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 10:26:36 by npimenof          #+#    #+#             */
/*   Updated: 2019/11/06 16:58:38 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

int			ft_blociter(t_bloc *lst, int (*f)(t_bloc *elem, t_temp *val))
{
	t_bloc	*tmp;
	t_temp	*val;

	val = NULL;
	if (lst)
	{
		tmp = lst;
		while (tmp)
		{
			val = set_values();
			f(tmp, val);
			free(val);
			val = NULL;
			tmp = tmp->next;
		}
	}
	return (0);
}

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
	int		blocs;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
			return (returns("error"));
		else
			create_list(fd, &bloc_start);
		ft_blociter(bloc_start->next, validate_bloc);
		ft_putendl("validated");
		if ((blocs = count_blocs(bloc_start)) < 1 || blocs > 26)
			return (returns("error"));
		ft_putnbr(blocs);
		ft_putendl(" blocks");
		result = solve(blocs, bloc_start);
		ft_putendl("solved");
		del_blocs(&bloc_start);
		ft_putstr(result);
		free(result);
		close(fd);
	}
	else
		return (returns("usage: ./fillit [ input_file ]"));
	// while (1);
	return (0);
}
