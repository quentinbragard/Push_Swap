/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:54:27 by qbragard          #+#    #+#             */
/*   Updated: 2019/05/29 10:46:05 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stacks *st, char **res)
{
	char	*tmp;

	if (st->len_a >= 2)
	{
		ft_swap(&st->st_a[0], &st->st_a[1]);
		tmp = *res;
		*res = ft_strjoin(*res, "sa\n");
		free(tmp);
	}
}

void	ft_sb(t_stacks *st, char **res)
{
	char *tmp;

	if (st->len_b >= 2)
	{
		ft_swap(&st->st_b[0], &st->st_b[1]);
		tmp = *res;
		*res = ft_strjoin(*res, "sb\n");
		free(tmp);
	}
}

void	ft_ss(t_stacks *st, char **res)
{
	char *tmp;

	if (st->len_a >= 2)
		ft_swap(&st->st_a[0], &st->st_a[1]);
	if (st->len_b >= 2)
		ft_swap(&st->st_b[0], &st->st_b[1]);
	tmp = *res;
	*res = ft_strjoin(*res, "ss\n");
	free(tmp);
}

int		min_finder(int len, int *tab)
{
	int i;
	int min;

	i = 0;
	min = tab[i];
	while (i < len)
	{
		if (tab[i] < min)
			min = tab[i];
		i++;
	}
	return (min);
}

int		median_rank(int len, int *tab)
{
	int min;

	min = min_finder(len, tab);
	return ((min + (min + len)) / 2);
}
