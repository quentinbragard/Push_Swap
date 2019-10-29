/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:55:28 by qbragard          #+#    #+#             */
/*   Updated: 2019/05/29 10:59:42 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_stack_sorting(t_stacks *st, char **res)
{
	if (st->st_a[0] < st->st_a[1] && st->st_a[0] < st->st_a[2])
		if (st->st_a[1] < st->st_a[2])
			operations(st, res, 3, "ra", "ra", "ra");
		else
			operations(st, res, 4, "ra", "sa", "ra", "ra");
	else if (st->st_a[0] > st->st_a[1] && st->st_a[0] > st->st_a[2])
		if (st->st_a[1] > st->st_a[2])
			operations(st, res, 6, "pb", "sa", "ra", "ra", "pa", "ra");
		else
			operations(st, res, 5, "pb", "ra", "ra", "pa", "ra");
	else if (st->st_a[0] > st->st_a[1] && st->st_a[0] < st->st_a[2])
		operations(st, res, 4, "sa", "ra", "ra", "ra");
	else if (st->st_a[0] < st->st_a[1] && st->st_a[0] > st->st_a[2])
		operations(st, res, 6, "pb", "sa", "ra", "pa", "ra", "ra");
}

int		lowest_half_push_a_to_b(t_stacks *st, char **res)
{
	int	i;
	int	j;
	int	median;
	int	size;

	i = 0;
	j = 0;
	size = st->len_a;
	median = median_rank(st->len_a, st->st_a);
	while (i < size && j < size / 2)
	{
		if (st->st_a[0] < median)
		{
			ft_pb(st, res);
			j++;
		}
		else
			ft_ra(st, res);
	}
	return (size - j);
}

void	send_n_from_a_to_b(int *tab, t_stacks *st, char **res)
{
	int	i;

	i = tab[tab[0] - 1];
	if (i == 1)
		ft_ra(st, res);
	else if (i == 2)
	{
		if (st->st_a[0] > st->st_a[1])
			ft_sa(st, res);
		operations(st, res, 2, "ra", "ra");
	}
	else if (i == 3)
		two_stack_sorting(st, res);
	else
	{
		while (i-- > 0)
		{
			if (st->st_a[0] == st->st_a[st->len_a - 1] + 1)
				ft_ra(st, res);
			else
				(st->st_a[1] == st->st_a[st->len_a - 1] + 1) ? operations(st,
						res, 2, "sa", "ra") : ft_pb(st, res);
		}
	}
	tab[0]--;
}
