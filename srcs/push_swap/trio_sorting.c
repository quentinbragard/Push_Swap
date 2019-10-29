/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trio_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 19:01:55 by qbragard          #+#    #+#             */
/*   Updated: 2019/05/24 15:22:58 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	trio_sorting_1(t_stacks *st, char **res)
{
	if (st->st_b[1] < st->st_b[2])
		operations(st, res, 2, "sb", "rrb");
	else
		ft_rb(st, res);
	operations(st, res, 3, "pa", "pa", "pa");
}

void	trio_sorting_2(t_stacks *st, char **res)
{
	if (st->st_b[1] < st->st_b[2])
		ft_rrb(st, res);
	else
		ft_sb(st, res);
	operations(st, res, 3, "pa", "pa", "pa");
}

void	trio_sorting_3(t_stacks *st, char **res)
{
	ft_pa(st, res);
	if (st->st_b[0] > st->st_b[1])
		operations(st, res, 2, "pa", "pa");
	else
		operations(st, res, 3, "sb", "pa", "pa");
}

void	trio_sorting(t_stacks *st, char **res)
{
	int i;

	i = 0;
	if (st->st_b[0] > st->st_b[1] && st->st_b[0] > st->st_b[2])
		trio_sorting_3(st, res);
	else if (st->st_b[0] < st->st_b[1] && st->st_b[0] < st->st_b[2])
		trio_sorting_1(st, res);
	else
		trio_sorting_2(st, res);
	while (i++ < 3)
		ft_ra(st, res);
}

int		sorting(t_stacks *st, char **res)
{
	if (st->len_b == 1)
	{
		operations(st, res, 2, "pa", "ra");
		return (1);
	}
	if (st->len_b == 2)
	{
		if (st->st_b[0] < st->st_b[1])
			ft_sb(st, res);
		operations(st, res, 4, "pa", "pa", "ra", "ra");
		return (2);
	}
	trio_sorting(st, res);
	return (3);
}
