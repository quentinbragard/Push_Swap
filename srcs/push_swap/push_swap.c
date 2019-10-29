/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 15:36:49 by qbragard          #+#    #+#             */
/*   Updated: 2019/05/24 15:32:52 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		partition(int *tab, int low, int high)
{
	int pivot;
	int i;
	int j;

	pivot = tab[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (tab[j] < pivot)
		{
			i++;
			ft_swap(&tab[i], &tab[j]);
		}
		j++;
	}
	ft_swap(&tab[i + 1], &tab[high]);
	return (i + 1);
}

void	quick_sort(int *tab, int low, int high)
{
	int i;

	if (low < high)
	{
		i = partition(tab, low, high);
		quick_sort(tab, low, i - 1);
		quick_sort(tab, i + 1, high);
	}
}

void	stack_transformation(t_stacks *st)
{
	int		i;
	int		j;
	int		*tab;

	if (!(tab = malloc(sizeof(int) * st->len_a)))
		return ;
	i = -1;
	while (++i < st->len_a)
		tab[i] = st->st_a[i];
	quick_sort(tab, 0, st->len_a - 1);
	i = 0;
	j = 0;
	while (i < st->len_a)
	{
		if (st->st_a[i] == tab[j])
		{
			st->st_a[i] = j;
			i++;
			j = -1;
		}
		j++;
	}
	free(tab);
}

int		*stack_partition(t_stacks *st, char **res)
{
	int		*tab;
	int		i;
	int		begin;

	begin = 0;
	if (!(tab = malloc(sizeof(int) * st->len_a)))
		return (tab);
	i = 1;
	stack_transformation(st);
	tab[i++] = lowest_half_push_a_to_b(st, res);
	while (st->len_b > 3)
	{
		if (st->st_b[0] == begin && st->len_b > 3 && begin++ > -1)
			operations(st, res, 2, "pa", "ra");
		else if (st->st_b[1] == begin && st->len_b > 3 && begin++ > -1)
			operations(st, res, 3, "sb", "pa", "ra");
		else
			tab[i++] = highest_half_push_b_to_a(st, res);
	}
	tab[0] = i;
	return (tab);
}

void	push_swap(int *tab, t_stacks *st, char **res)
{
	while (st->st_a[0] != 0 || tab[0] != 1 || st->len_b > 0)
	{
		if (st->len_b == 0)
			send_n_from_a_to_b(tab, st, res);
		else if (st->len_b <= 3)
			sorting(st, res);
		else
		{
			tab[tab[0]] = highest_half_push_b_to_a(st, res);
			tab[0]++;
		}
	}
}
