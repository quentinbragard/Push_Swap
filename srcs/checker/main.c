/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 18:15:09 by qbragard          #+#    #+#             */
/*   Updated: 2019/05/28 10:38:48 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		return_error(t_stacks st)
{
	ft_putstr_fd("Error\n", 2);
	free(st.st_a);
	free(st.st_b);
	return (-1);
}

int		main(int ac, char **av)
{
	t_stacks	st;

	if (ac == 1)
		return (0);
	st = stacks_init(ac, av);
	if (st.len_a <= 0)
		return (return_error(st));
	if (double_checker(st.len_a, st.st_a) == -1)
		return (return_error(st));
	if (check_push_swap(st) == -1)
		return (return_error(st));
	order_checker(st.len_a, st.st_a);
	free(st.st_a);
	free(st.st_b);
	return (0);
}
