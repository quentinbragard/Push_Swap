/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 10:44:00 by qbragard          #+#    #+#             */
/*   Updated: 2019/07/16 17:23:20 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIEWER_H
# define VIEWER_H
# define HEIGHT 1000
# define WIDTH 1200
# define SPEED 50
# include <SDL2/SDL.h>
# include "libft.h"
# include "push_swap.h"
# include "checker.h"

void			ft_sa_viewer(t_stacks *st);
void			ft_sb_viewer(t_stacks *st);
void			ft_ss_viewer(t_stacks *st);
void			ft_pa_viewer(t_stacks *st);
void			ft_pb_viewer(t_stacks *st);
void			ft_ra_viewer(t_stacks *st);
void			ft_rb_viewer(t_stacks *st);
void			ft_rr_viewer(t_stacks *st);
void			ft_rra_viewer(t_stacks *st);
void			ft_rrb_viewer(t_stacks *st);
void			ft_rrr_viewer(t_stacks *st);
void			create_bar(int i, int size, SDL_Rect *point);
void			draw_bar(SDL_Renderer *ren, SDL_Rect point,
		int *tab, int i);
void			draw_end(t_stacks st, int size, SDL_Renderer *ren, int *total);
SDL_Texture		*draw_stack_a(SDL_Renderer *ren, t_stacks st, int size,
		int *total);
SDL_Texture		*draw_stack_b(SDL_Renderer *ren, t_stacks st, int size,
		int *total);
SDL_Texture		*place_graph(SDL_Renderer *ren, SDL_Texture *stack,
		SDL_Rect position);
int				view_push_swap(t_stacks st, SDL_Renderer *ren, int size,
		int *total);
int				order_checker(int len, int *tab);
int				bar_length(int len);
int				rank(int nb, int *tab, int len);
int				check_event(int running);
int				first_check(int gnl, char *line);
int				operation_viewer(char *str);
int				return_viewer(char *line);
void			stack_next_step(t_stacks *st, char *line);
int				destroy_stacks(SDL_Texture *stack_a, SDL_Texture *stack_b);
void			print_separation(SDL_Renderer *ren);
int				end_of_viz(SDL_Renderer *ren, SDL_Window *win, int *total);
#endif
