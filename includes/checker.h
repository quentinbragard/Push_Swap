/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:07:07 by qbragard          #+#    #+#             */
/*   Updated: 2019/05/28 10:44:34 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct	s_stacks
{
	int			*st_a;
	int			*st_b;
	int			len_a;
	int			len_b;
}				t_stacks;

int				operation_checker(char *str);
int				check_push_swap(t_stacks st);
int				order_checker(int len, int *tab);
void			ft_sa_checker(t_stacks *st);
void			ft_sb_checker(t_stacks *st);
void			ft_ss_checker(t_stacks *st);
void			ft_pa_checker(t_stacks *st);
void			ft_pb_checker(t_stacks *st);
void			ft_ra_checker(t_stacks *st);
void			ft_rb_checker(t_stacks *st);
void			ft_rr_checker(t_stacks *st);
void			ft_rra_checker(t_stacks *st);
void			ft_rrb_checker(t_stacks *st);
void			ft_rrr_checker(t_stacks *st);
long			ft_atoi_advanced(char **str);
int				ft_format_checker(char *str);
int				*stack_a_init(int ac, char **av);
t_stacks		stacks_init(int ac, char **av);
int				double_checker(int len, int *tab);

#endif
