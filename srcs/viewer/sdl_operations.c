/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:14:32 by qbragard          #+#    #+#             */
/*   Updated: 2019/07/16 16:44:05 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewer.h"

void		create_bar(int i, int size, SDL_Rect *point)
{
	point[i].x = WIDTH / 8;
	point[i].y = (HEIGHT / 4) - (size / 2 + 1) * (HEIGHT / (size * 2))
		+ (i * (HEIGHT / (size * 2))) + (HEIGHT / (size * 2) * (size / 2) + 1);
}

void		draw_bar(SDL_Renderer *ren, SDL_Rect point, int *tab, int i)
{
	if (tab[i] < 0)
		SDL_SetRenderDrawColor(ren, 255, 10, 0, 100);
	else
		SDL_SetRenderDrawColor(ren, 0, 10, 255, 100);
	SDL_RenderFillRect(ren, &point);
	SDL_RenderDrawRect(ren, &point);
}

SDL_Texture	*place_graph(SDL_Renderer *ren,
		SDL_Texture *stack, SDL_Rect position)
{
	SDL_SetRenderTarget(ren, NULL);
	SDL_QueryTexture(stack, NULL, NULL, &position.w, &position.h);
	SDL_RenderCopy(ren, stack, NULL, &position);
	return (stack);
}

void		draw_end(t_stacks st, int size, SDL_Renderer *ren, int *total)
{
	SDL_Texture	*stack_a;
	SDL_Texture	*stack_b;

	stack_a = draw_stack_a(ren, st, size, total);
	stack_b = NULL;
	SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
	SDL_RenderDrawLine(ren, WIDTH / 2, 0, WIDTH / 2, HEIGHT);
	SDL_RenderPresent(ren);
	destroy_stacks(stack_a, stack_b);
}

int			check_event(int running)
{
	SDL_Event event;

	if (!running)
		return (0);
	while (SDL_PollEvent(&event))
	{
		if ((SDL_QUIT == event.type) || (SDL_KEYDOWN == event.type
					&& SDL_SCANCODE_ESCAPE == event.key.keysym.scancode))
			return (0);
	}
	return (1);
}
