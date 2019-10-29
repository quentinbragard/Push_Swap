/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:51:58 by qbragard          #+#    #+#             */
/*   Updated: 2019/05/29 11:01:05 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "checker.h"
# include <stdarg.h>

void		trio_sort(int *tab, char **res);
void		stack_transformation(t_stacks *st);
int			median_rank(int len, int	*tab);
void		quick_sort(int *tab, int low, int high);
void		n_top_push_a_to_b(int n, t_stacks *st, char **res);
void		n_top_push_a_to_b_reverse(int n, t_stacks *st, char **res);
int			lowest_half_push_a_to_b(t_stacks *st, char **res);
int			highest_half_push_a_to_b(t_stacks *st, char **res);
int			highest_half_push_b_to_a(t_stacks *st, char **res);
int			lowest_half_push_b_to_a(t_stacks *st, char **res);
int			sorting(t_stacks *st, char **res);
void		trio_sorting(t_stacks *st, char **res);
void		trio_sorting_reverse(t_stacks *st, char **res);
int			*stack_partition(t_stacks *st, char **res);
int			*stack_partition_reverse(t_stacks *st, char **res);
int			n_sort_in_a_with_b(int n, t_stacks *st, char **res);
void		push_swap(int *tab, t_stacks *st, char **res);
void		push_swap_reverse(int *tab, t_stacks *st, char **res);
void		send_n_from_a_to_b(int *tab, t_stacks *st, char **res);
void		send_n_from_a_to_b_reverse(int *tab, t_stacks *st, char **res);
t_stacks	stacks_init(int ac, char **av);
int			pivot_rank(int len, int *tab);
int			to_send(int len);
int			min_finder(int len, int *tab);
void		operations(t_stacks *st, char **res, int n, ...);
void		ft_sa(t_stacks *st, char **res);
void		ft_sb(t_stacks *st, char **res);
void		ft_ss(t_stacks *st, char **res);
void		ft_pa(t_stacks *st, char **res);
void		ft_pb(t_stacks *st, char **res);
void		ft_ra(t_stacks *st, char **res);
void		ft_rb(t_stacks *st, char **res);
void		ft_rr(t_stacks *st, char **res);
void		ft_rra(t_stacks *st, char **res);
void		ft_rrb(t_stacks *st, char **res);
void		ft_rrr(t_stacks *st, char **res);
int			double_checker(int len, int *tab);
void		sort_three_elements(t_stacks *st, char **res);
void		sort_five_elements(t_stacks *st, char **res);
void		optimise_result(char **res);
void		trio_sorting_1(t_stacks *st, char **res);
void		trio_sorting_2(t_stacks *st, char **res);
void		trio_sorting_3(t_stacks *st, char **res);
int			sorting_reverse(t_stacks *st, char **res);
void		two_stack_sorting(t_stacks *st, char **res);

#endif
