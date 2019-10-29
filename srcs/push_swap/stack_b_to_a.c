/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 12:35:54 by qbragard          #+#    #+#             */
/*   Updated: 2019/05/24 15:22:47 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		to_send(int len)
{
	if (len == 5)
		return (2);
	if (len == 7)
		return (4);
	if (!(len % 2))
		return (len / 2 - 1);
	else
		return (len / 2);
}

int		operation_checker(char *str)
{
	if (!ft_strcmp(str, "sa"))
		return (0);
	if (!ft_strcmp(str, "sb"))
		return (1);
	if (!ft_strcmp(str, "ss"))
		return (2);
	if (!ft_strcmp(str, "pa"))
		return (3);
	if (!ft_strcmp(str, "pb"))
		return (4);
	if (!ft_strcmp(str, "ra"))
		return (5);
	if (!ft_strcmp(str, "rb"))
		return (6);
	if (!ft_strcmp(str, "rr"))
		return (7);
	if (!ft_strcmp(str, "rra"))
		return (8);
	if (!ft_strcmp(str, "rrb"))
		return (9);
	if (!ft_strcmp(str, "rrr"))
		return (10);
	return (-1);
}

void	operations(t_stacks *st, char **res, int n, ...)
{
	int		i;
	va_list	ap;
	void	(*f[11])(t_stacks *stacks, char **res);

	i = 0;
	f[0] = ft_sa;
	f[1] = ft_sb;
	f[2] = ft_ss;
	f[3] = ft_pa;
	f[4] = ft_pb;
	f[5] = ft_ra;
	f[6] = ft_rb;
	f[7] = ft_rr;
	f[8] = ft_rra;
	f[9] = ft_rrb;
	f[10] = ft_rrr;
	va_start(ap, n);
	while (i++ < n)
		f[operation_checker(va_arg(ap, char *))](st, res);
	va_end(ap);
}

int		highest_half_push_b_to_a(t_stacks *st, char **res)
{
	int	indice[5];

	indice[0] = 0;
	indice[1] = 0;
	indice[2] = median_rank(st->len_b, st->st_b);
	indice[3] = st->len_b;
	indice[4] = to_send(st->len_b);
	while (indice[0] < indice[3] && indice[1] < indice[4])
	{
		if (st->st_b[0] == st->st_a[st->len_a - 1] + 1)
		{
			operations(st, res, 2, "pa", "ra");
			indice[0]++;
		}
		if (st->st_b[0] > indice[2])
		{
			ft_pa(st, res);
			indice[1]++;
		}
		else
			ft_rb(st, res);
		indice[0]++;
	}
	return (indice[1]);
}
