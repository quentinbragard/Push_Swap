/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:27:14 by qbragard          #+#    #+#             */
/*   Updated: 2019/05/24 16:27:31 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	push_down_checker(int *len, int *tab)
{
	int i;

	i = *len - 1;
	while (i >= 0)
	{
		tab[i + 1] = tab[i];
		i--;
	}
	*len = *len + 1;
}

void	push_up_checker(int *len, int *tab)
{
	int i;

	i = 0;
	while (i < *len - 1)
	{
		tab[i] = tab[i + 1];
		i++;
	}
	*len = *len - 1;
}

void	ft_pa_checker(t_stacks *st)
{
	if (st->len_b >= 1)
	{
		push_down_checker(&st->len_a, st->st_a);
		st->st_a[0] = st->st_b[0];
		push_up_checker(&st->len_b, st->st_b);
	}
}

void	ft_pb_checker(t_stacks *st)
{
	if (st->len_a >= 1)
	{
		push_down_checker(&st->len_b, st->st_b);
		st->st_b[0] = st->st_a[0];
		push_up_checker(&st->len_a, st->st_a);
	}
}
