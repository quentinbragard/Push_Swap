/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 12:56:00 by qbragard          #+#    #+#             */
/*   Updated: 2019/05/29 10:45:27 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	double_checker(int len, int *tab)
{
	int i;
	int j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (tab[i] == tab[j] && i != j)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	under_six_push_swap(t_stacks *st, char **res)
{
	if (st->len_a == 2 && st->st_a[0] > st->st_a[1])
		ft_sa(st, res);
	else if (st->len_a == 3)
		sort_three_elements(st, res);
	else if (st->len_a == 4)
	{
		while (st->st_a[0] != min_finder(st->len_a, st->st_a))
			ft_ra(st, res);
		ft_pb(st, res);
		sort_three_elements(st, res);
		ft_pa(st, res);
	}
	else if (st->len_a == 5)
		sort_five_elements(st, res);
	ft_putstr(*res);
	free(st->st_a);
	free(st->st_b);
	free(*res);
	return (0);
}

int	return_push_swap(char *res, t_stacks st)
{
	int *tab;

	tab = stack_partition(&st, &res);
	push_swap(tab, &st, &res);
	optimise_result(&res);
	ft_putstr(res);
	free(tab);
	free(st.st_a);
	free(st.st_b);
	free(res);
	return (0);
}

int	main(int ac, char **av)
{
	t_stacks	st;
	char		*res;

	if (ac == 1)
		return (0);
	st = stacks_init(ac, av);
	if (st.len_a == -1)
	{
		ft_putstr_fd("Error\n", 2);
		free(st.st_a);
		free(st.st_b);
		return (-1);
	}
	res = ft_strdup("");
	if (st.len_a <= 5)
	{
		stack_transformation(&st);
		return (under_six_push_swap(&st, &res));
	}
	return (return_push_swap(res, st));
}
