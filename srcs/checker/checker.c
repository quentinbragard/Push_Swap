/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:01:27 by qbragard          #+#    #+#             */
/*   Updated: 2019/05/29 15:48:18 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	operation_checker(char *str)
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

int	return_checker(char *line)
{
	free(line);
	return (-1);
}

int	check_push_swap(t_stacks st)
{
	void	(*f[11])(t_stacks *stacks);
	char	*line;
	int		gnl;

	f[0] = ft_sa_checker;
	f[1] = ft_sb_checker;
	f[2] = ft_ss_checker;
	f[3] = ft_pa_checker;
	f[4] = ft_pb_checker;
	f[5] = ft_ra_checker;
	f[6] = ft_rb_checker;
	f[7] = ft_rr_checker;
	f[8] = ft_rra_checker;
	f[9] = ft_rrb_checker;
	f[10] = ft_rrr_checker;
	while ((gnl = get_next_line(0, &line)))
	{
		if (gnl == 2)
			return (return_checker(line));
		if (operation_checker(line) == -1)
			return (return_checker(line));
		f[operation_checker(line)](&st);
		free(line);
	}
	return (0);
}

int	order_checker(int len, int *tab)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			ft_putstr("KO\n");
			return (0);
		}
		i++;
	}
	ft_putstr("OK\n");
	return (1);
}

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
