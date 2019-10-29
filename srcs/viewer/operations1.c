/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:03:10 by qbragard          #+#    #+#             */
/*   Updated: 2019/07/15 13:44:28 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewer.h"

void	ft_sa_viewer(t_stacks *st)
{
	if (st->len_a >= 2)
		ft_swap(&st->st_a[0], &st->st_a[1]);
}

void	ft_sb_viewer(t_stacks *st)
{
	if (st->len_b >= 2)
		ft_swap(&st->st_b[0], &st->st_b[1]);
}

void	ft_ss_viewer(t_stacks *st)
{
	ft_sa_viewer(st);
	ft_sb_viewer(st);
}

void	ft_rr_viewer(t_stacks *st)
{
	ft_ra_viewer(st);
	ft_rb_viewer(st);
}

void	ft_rrr_viewer(t_stacks *st)
{
	ft_rra_viewer(st);
	ft_rrb_viewer(st);
}
