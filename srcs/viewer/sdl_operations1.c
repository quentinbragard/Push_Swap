/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL_operations1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:14:32 by qbragard          #+#    #+#             */
/*   Updated: 2019/07/16 16:49:04 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewer.h"

int		first_check(int gnl, char *line)
{
	if (gnl == 2)
		return (return_viewer(line));
	if (operation_viewer(line) == -1)
		return (return_viewer(line));
	return (0);
}

void	stack_next_step(t_stacks *st, char *line)
{
	void	(*f[11])(t_stacks *stacks);

	f[0] = ft_sa_viewer;
	f[1] = ft_sb_viewer;
	f[2] = ft_ss_viewer;
	f[3] = ft_pa_viewer;
	f[4] = ft_pb_viewer;
	f[5] = ft_ra_viewer;
	f[6] = ft_rb_viewer;
	f[7] = ft_rr_viewer;
	f[8] = ft_rra_viewer;
	f[9] = ft_rrb_viewer;
	f[10] = ft_rrr_viewer;
	f[operation_viewer(line)](st);
}

int		destroy_stacks(SDL_Texture *stack_a, SDL_Texture *stack_b)
{
	SDL_DestroyTexture(stack_a);
	SDL_DestroyTexture(stack_b);
	return (1);
}

void	print_separation(SDL_Renderer *ren)
{
	SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
	SDL_RenderDrawLine(ren, WIDTH / 2, 0, WIDTH / 2, HEIGHT);
}

int		end_of_viz(SDL_Renderer *ren, SDL_Window *win, int *total)
{
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(win);
	SDL_Quit();
	free(total);
	return (0);
}
