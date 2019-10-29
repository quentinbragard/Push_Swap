/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 11:20:15 by qbragard          #+#    #+#             */
/*   Updated: 2019/05/29 10:59:12 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_elements(t_stacks *st, char **res)
{
	if (st->st_a[0] > st->st_a[1] && st->st_a[0] > st->st_a[2])
	{
		ft_ra(st, res);
		if (st->st_a[0] > st->st_a[1])
			ft_sa(st, res);
	}
	else if (st->st_a[0] < st->st_a[1] && st->st_a[0] < st->st_a[2])
	{
		if (st->st_a[1] > st->st_a[2])
			operations(st, res, 3, "ra", "sa", "rra");
	}
	else
	{
		if (st->st_a[1] < st->st_a[2])
			ft_sa(st, res);
		else
			ft_rra(st, res);
	}
}

void	sort_five_elements(t_stacks *st, char **res)
{
	int i;

	i = 0;
	while (st->len_b < 2)
	{
		if (st->st_a[0] < 2)
			ft_pb(st, res);
		else if (st->st_a[4] < 2)
			operations(st, res, 2, "rra", "pb");
		else
			ft_ra(st, res);
	}
	if (st->st_a[0] == 4)
		ft_ra(st, res);
	else if (st->st_a[1] == 4)
		ft_rra(st, res);
	if (st->st_a[0] > st->st_a[1])
		ft_sa(st, res);
	if (st->st_b[0] < st->st_b[1])
		ft_sb(st, res);
	operations(st, res, 2, "pa", "pa");
}
