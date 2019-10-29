/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:27:37 by qbragard          #+#    #+#             */
/*   Updated: 2019/05/24 16:27:39 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_ra_checker(t_stacks *st)
{
	int tmp;
	int j;

	if (st->len_a > 0)
	{
		tmp = st->st_a[0];
		j = -1;
		while (++j < st->len_a - 1)
			st->st_a[j] = st->st_a[j + 1];
		st->st_a[st->len_a - 1] = tmp;
	}
}

void	ft_rb_checker(t_stacks *st)
{
	int tmp;
	int j;

	if (st->len_b > 0)
	{
		tmp = st->st_b[0];
		j = -1;
		while (++j < st->len_b - 1)
			st->st_b[j] = st->st_b[j + 1];
		st->st_b[st->len_b - 1] = tmp;
	}
}

void	ft_rra_checker(t_stacks *st)
{
	int tmp;
	int j;

	if (st->len_a > 0)
	{
		tmp = st->st_a[st->len_a - 1];
		j = st->len_a;
		while (--j > 0)
			st->st_a[j] = st->st_a[j - 1];
		st->st_a[0] = tmp;
	}
}

void	ft_rrb_checker(t_stacks *st)
{
	int tmp;
	int j;

	if (st->len_b > 0)
	{
		tmp = st->st_b[st->len_b - 1];
		j = st->len_b;
		while (--j > 0)
			st->st_b[j] = st->st_b[j - 1];
		st->st_b[0] = tmp;
	}
}
