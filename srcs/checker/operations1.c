/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:03:10 by qbragard          #+#    #+#             */
/*   Updated: 2019/05/24 17:36:14 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sa_checker(t_stacks *st)
{
	if (st->len_a >= 2)
		ft_swap(&st->st_a[0], &st->st_a[1]);
}

void	ft_sb_checker(t_stacks *st)
{
	if (st->len_b >= 2)
		ft_swap(&st->st_b[0], &st->st_b[1]);
}

void	ft_ss_checker(t_stacks *st)
{
	ft_sa_checker(st);
	ft_sb_checker(st);
}

void	ft_rr_checker(t_stacks *st)
{
	ft_ra_checker(st);
	ft_rb_checker(st);
}

void	ft_rrr_checker(t_stacks *st)
{
	ft_rra_checker(st);
	ft_rrb_checker(st);
}
