/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:03:10 by qbragard          #+#    #+#             */
/*   Updated: 2019/05/29 10:45:53 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_down(int *len, int *tab)
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

void	push_up(int *len, int *tab)
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

void	ft_pa(t_stacks *st, char **res)
{
	char *tmp;

	if (st->len_b >= 1)
	{
		push_down(&st->len_a, st->st_a);
		st->st_a[0] = st->st_b[0];
		push_up(&st->len_b, st->st_b);
	}
	tmp = *res;
	*res = ft_strjoin(*res, "pa\n");
	free(tmp);
}

void	ft_pb(t_stacks *st, char **res)
{
	char *tmp;

	if (st->len_a >= 1)
	{
		push_down(&st->len_b, st->st_b);
		st->st_b[0] = st->st_a[0];
		push_up(&st->len_a, st->st_a);
	}
	tmp = *res;
	*res = ft_strjoin(*res, "pb\n");
	free(tmp);
}

void	ft_rrr(t_stacks *st, char **res)
{
	int		tmp;
	char	*tmp2;
	int		j;

	if (st->len_a > 0)
	{
		tmp = st->st_a[st->len_a - 1];
		j = st->len_a;
		while (--j > 0)
			st->st_a[j] = st->st_a[j - 1];
		st->st_a[0] = tmp;
	}
	if (st->len_b > 0)
	{
		tmp = st->st_b[st->len_b - 1];
		j = st->len_b;
		while (--j > 0)
			st->st_b[j] = st->st_b[j - 1];
		st->st_b[0] = tmp;
	}
	tmp2 = *res;
	*res = ft_strjoin(*res, "rrr\n");
	free(tmp2);
}
