/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 16:44:50 by qbragard          #+#    #+#             */
/*   Updated: 2019/07/16 17:44:15 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_format_checker(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'
					&& str[i] != '+' && str[i] != '-')
				return (-1);
			if (str[i] == '+' || str[i] == '-')
			{
				if (str[i + 1] == '+' || str[i + 1] == '-')
					return (-1);
			}
		}
		i++;
	}
	return (ft_count_words(str, ' '));
}

long		ft_atoi_advanced(char **str)
{
	int					u;
	long				result;

	u = 1;
	result = 0;
	while (**str == ' ' || **str == '\f' || **str == '\n' || **str
			== '\r' || **str == '\t' || **str == '\v')
		(*str)++;
	if ((**str == '+') || (**str == '-'))
	{
		if (**str == '-')
			u = -1;
		(*str)++;
	}
	while (**str > 47 && **str < 58)
	{
		result = result * 10 + (**str - 48);
		(*str)++;
	}
	if (u * result > 2147483647 || u * result < -2147483648)
		return (-2147483649);
	return (u * result);
}

int			arg_counter(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		if (ft_format_checker(av[i]) == -1)
			return (-1);
		j = j + ft_format_checker(av[i]);
		i++;
	}
	return (j);
}

int			*stack_a_init(int ac, char **av)
{
	int		i[2];
	char	*tmp;
	char	*tmp2;
	int		*stack_a;
	long	error;

	if (!(stack_a = malloc(sizeof(int) * (arg_counter(ac, av) + 1))))
		return (stack_a);
	i[0] = 1;
	i[1] = 0;
	while (i[0] < ac)
	{
		tmp = ft_strtrim(av[i[0]]);
		tmp2 = tmp;
		while (i[1] < arg_counter(ac, av) && *tmp)
		{
			error = ft_atoi_advanced(&tmp);
			stack_a[i[1]] = error;
			stack_a[arg_counter(ac, av)] = (error == -2147483649 ? -1 : 0);
			i[1]++;
		}
		free(tmp2);
		i[0]++;
	}
	return (stack_a);
}

t_stacks	stacks_init(int ac, char **av)
{
	t_stacks	st;

	st.st_a = NULL;
	st.len_a = -1;
	st.st_b = NULL;
	st.len_b = 0;
	if (arg_counter(ac, av) == -1)
		return (st);
	st.st_a = stack_a_init(ac, av);
	if (st.st_a[arg_counter(ac, av)] == -1)
		return (st);
	st.len_a = arg_counter(ac, av);
	if (double_checker(st.len_a, st.st_a) == -1)
		st.len_a = -1;
	if (!(st.st_b = malloc(sizeof(t_stacks) * arg_counter(ac, av))))
		return (st);
	st.len_b = 0;
	return (st);
}
