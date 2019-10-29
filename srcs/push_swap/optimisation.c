/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimisation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 13:16:13 by qbragard          #+#    #+#             */
/*   Updated: 2019/05/29 10:58:30 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		change_res_rr(int i, char *previous, char *current, char **res)
{
	int j;

	if (!ft_strcmp(previous, "ra") && !ft_strcmp(current, "rb") && (j = 2))
	{
		(*res)[i + 1] = 'r';
		(*res)[i + 2] = '\n';
		while ((*res)[i + ++j + 3])
			(*res)[i + j] = (*res)[i + j + 3];
		(*res)[i + j] = '\0';
		return (1);
	}
	if (!ft_strcmp(previous, "rb") && !ft_strcmp(current, "ra") && (j = 2))
	{
		(*res)[i + 1] = 'r';
		(*res)[i + 2] = '\n';
		while ((*res)[i + ++j + 3])
			(*res)[i + j] = (*res)[i + j + 3];
		(*res)[i + j] = '\0';
		return (1);
	}
	return (0);
}

int		change_res_ss(int i, char *previous, char *current, char **res)
{
	int j;

	if (!ft_strcmp(previous, "sa") && !ft_strcmp(current, "sb") && (j = 2))
	{
		(*res)[i + 1] = 's';
		(*res)[i + 2] = '\n';
		while ((*res)[i + ++j + 3])
			(*res)[i + j] = (*res)[i + j + 3];
		(*res)[i + j] = '\0';
		return (1);
	}
	if (!ft_strcmp(previous, "sb") && !ft_strcmp(current, "sa") && (j = 2))
	{
		(*res)[i + 1] = 's';
		(*res)[i + 2] = '\n';
		while ((*res)[i + ++j + 3])
			(*res)[i + j] = (*res)[i + j + 3];
		(*res)[i + j] = '\0';
		return (1);
	}
	return (0);
}

int		change_res_pp(int i, char *previous, char *current, char **res)
{
	int j;

	if (!ft_strcmp(previous, "pa") && !ft_strcmp(current, "pb") && (j = -1))
	{
		while ((*res)[i + ++j + 6])
			(*res)[i + j] = (*res)[i + j + 6];
		(*res)[i + j] = '\0';
		return (1);
	}
	if (!ft_strcmp(previous, "pb") && !ft_strcmp(current, "pa") && (j = -1))
	{
		while ((*res)[i + ++j + 6])
			(*res)[i + j] = (*res)[i + j + 6];
		(*res)[i + j] = '\0';
		return (1);
	}
	return (0);
}

void	optimise_result(char **res)
{
	int		i;
	int		j;
	int		k;
	char	p[4];
	char	c[4];

	i = 0;
	while ((*res)[i])
	{
		j = -1;
		while ((*res)[i + ++j] != '\n')
			p[j] = (*res)[i + j];
		p[j] = '\0';
		k = i + j + 1;
		j = -1;
		while ((*res)[i + ++j] != '\n')
			c[j] = (*res)[k + j];
		c[j] = '\0';
		if (!(change_res_ss(i, p, c, res) + change_res_rr(i,
						p, c, res) + change_res_pp(i, p, c, res)))
			i = k;
	}
}
