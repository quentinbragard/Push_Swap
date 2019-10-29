/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:45:46 by qbragard          #+#    #+#             */
/*   Updated: 2019/07/17 10:01:28 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewer.h"

int	operation_viewer(char *str)
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

int	return_viewer(char *line)
{
	free(line);
	return (-1);
}

int	view_push_swap(t_stacks st, SDL_Renderer *ren, int size, int *total)
{
	char			*line;
	int				gnl;
	SDL_Texture		*stack_a;
	SDL_Texture		*stack_b;
	SDL_Event		event;

	while ((gnl = get_next_line(0, &line)))
	{
		while (SDL_PollEvent(&event))
			if ((SDL_QUIT == event.type) || (SDL_KEYDOWN == event.type
						&& SDL_SCANCODE_ESCAPE == event.key.keysym.scancode))
				return (0);
		if (first_check(gnl, line))
			return (-1);
		stack_next_step(&st, line);
		stack_a = draw_stack_a(ren, st, size, total);
		stack_b = draw_stack_b(ren, st, size, total);
		print_separation(ren);
		SDL_RenderPresent(ren);
		SDL_Delay(SPEED);
		free(line);
	}
	return (destroy_stacks(stack_a, stack_b));
}

int	order_checker(int len, int *tab)
{
	int i;

	i = 0;
	while (i < len - 1)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
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
