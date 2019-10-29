/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 10:45:09 by qbragard          #+#    #+#             */
/*   Updated: 2019/07/17 10:06:08 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewer.h"

void			*sdl_errors(char const *message)
{
	ft_putstr_fd("Error ", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(SDL_GetError(), 2);
	ft_putstr_fd(".\n", 2);
	SDL_Quit();
	return (NULL);
}

SDL_Window		*viz_init(SDL_Renderer **ren)
{
	SDL_Window *win;

	win = NULL;
	if (SDL_Init(SDL_INIT_EVERYTHING))
		return (sdl_errors("SDL_Init"));
	if (!(win = SDL_CreateWindow("Push_Swap", SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED,
					WIDTH, HEIGHT, SDL_WINDOW_SHOWN)))
		return (sdl_errors("window initialisation"));
	if (!(*ren = SDL_CreateRenderer(win, -1,
					SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
	{
		SDL_DestroyWindow(win);
		return (sdl_errors("renderer initialisation"));
	}
	return (win);
}

SDL_Texture		*draw_stack_a(SDL_Renderer *ren,
		t_stacks st, int size, int *total)
{
	SDL_Texture		*stack_a;
	SDL_Rect		point[st.len_a];
	SDL_Rect		position;
	int				i;

	i = -1;
	if (!(stack_a = SDL_CreateTexture(ren, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_TARGET, (WIDTH / 2), HEIGHT)))
		return (sdl_errors("texture stack_a initialisation"));
	position.x = 0;
	position.y = 0;
	SDL_SetRenderDrawColor(ren, 255, 255, 0, 255);
	SDL_SetRenderTarget(ren, stack_a);
	while (++i < st.len_a)
	{
		create_bar(i, size, point);
		point[i].w = rank(st.st_a[i], total, size) * bar_length(size);
		point[i].h = HEIGHT / (size * 2);
		draw_bar(ren, point[i], st.st_a, i);
	}
	SDL_SetRenderTarget(ren, NULL);
	SDL_QueryTexture(stack_a, NULL, NULL, &position.w, &position.h);
	SDL_RenderCopy(ren, stack_a, NULL, &position);
	return (stack_a);
}

SDL_Texture		*draw_stack_b(SDL_Renderer *ren,
		t_stacks st, int size, int *total)
{
	SDL_Texture		*stack_b;
	SDL_Rect		point[st.len_b];
	SDL_Rect		position;
	int				i;

	i = -1;
	if (!(stack_b = SDL_CreateTexture(ren, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_TARGET, (WIDTH / 2), HEIGHT)))
		return (sdl_errors("texture stack_b initialisation"));
	position.x = WIDTH / 2;
	position.y = 0;
	SDL_SetRenderDrawColor(ren, 255, 255, 0, 255);
	SDL_SetRenderTarget(ren, stack_b);
	while (++i < st.len_b)
	{
		create_bar(i, size, point);
		point[i].w = rank(st.st_b[i], total, size) * bar_length(size);
		point[i].h = HEIGHT / (size * 2);
		draw_bar(ren, point[i], st.st_b, i);
	}
	SDL_SetRenderTarget(ren, NULL);
	SDL_QueryTexture(stack_b, NULL, NULL, &position.w, &position.h);
	SDL_RenderCopy(ren, stack_b, NULL, &position);
	return (stack_b);
}

int				main(int ac, char **av)
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	t_stacks		st;
	int				running;
	int				*total;

	ren = NULL;
	running = -1;
	st = stacks_init(ac, av);
	if (!(total = (int *)malloc(sizeof(int) * st.len_a + 1)))
		return (-1);
	total[st.len_a] = st.len_a;
	while (++running < st.len_a)
		total[running] = st.st_a[running];
	running = -1;
	if (!(win = viz_init(&ren)))
		return (-1);
	while ((running = check_event(running)))
	{
		if (!order_checker(st.len_a, st.st_a))
			running = view_push_swap(st, ren, total[st.len_a], total);
		else
			draw_end(st, total[st.len_a], ren, total);
	}
	return (end_of_viz(ren, win, total));
}
