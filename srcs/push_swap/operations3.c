/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:55:15 by qbragard          #+#    #+#             */
/*   Updated: 2019/05/29 10:47:19 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stacks *st, char **res)
{
	int		tmp;
	int		j;
	char	*tmp2;

	if (st->len_a > 0)
	{
		tmp = st->st_a[0];
		j = -1;
		while (++j < st->len_a - 1)
			st->st_a[j] = st->st_a[j + 1];
		st->st_a[st->len_a - 1] = tmp;
	}
	tmp2 = *res;
	*res = ft_strjoin(*res, "ra\n");
	free(tmp2);
}

void	ft_rb(t_stacks *st, char **res)
{
	int		tmp;
	int		j;
	char	*tmp2;

	if (st->len_b > 0)
	{
		tmp = st->st_b[0];
		j = -1;
		while (++j < st->len_b - 1)
			st->st_b[j] = st->st_b[j + 1];
		st->st_b[st->len_b - 1] = tmp;
	}
	tmp2 = *res;
	*res = ft_strjoin(*res, "rb\n");
	free(tmp2);
}

void	ft_rr(t_stacks *st, char **res)
{
	int		tmp;
	int		j;
	char	*tmp2;

	if (st->len_a > 0)
	{
		tmp = st->st_a[0];
		j = -1;
		while (++j < st->len_a - 1)
			st->st_a[j] = st->st_a[j + 1];
		st->st_a[st->len_a - 1] = tmp;
	}
	if (st->len_b > 0)
	{
		tmp = st->st_b[0];
		j = -1;
		while (++j < st->len_b - 1)
			st->st_b[j] = st->st_b[j + 1];
		st->st_b[st->len_b - 1] = tmp;
	}
	tmp2 = *res;
	*res = ft_strjoin(*res, "rr\n");
	free(tmp2);
}

void	ft_rra(t_stacks *st, char **res)
{
	int		tmp;
	int		j;
	char	*tmp2;

	if (st->len_a > 0)
	{
		tmp = st->st_a[st->len_a - 1];
		j = st->len_a;
		while (--j > 0)
			st->st_a[j] = st->st_a[j - 1];
		st->st_a[0] = tmp;
	}
	tmp2 = *res;
	*res = ft_strjoin(*res, "rra\n");
	free(tmp2);
}

void	ft_rrb(t_stacks *st, char **res)
{
	int		tmp;
	int		j;
	char	*tmp2;

	if (st->len_b > 0)
	{
		tmp = st->st_b[st->len_b - 1];
		j = st->len_b;
		while (--j > 0)
			st->st_b[j] = st->st_b[j - 1];
		st->st_b[0] = tmp;
	}
	tmp2 = *res;
	*res = ft_strjoin(*res, "rrb\n");
	free(tmp2);
}
