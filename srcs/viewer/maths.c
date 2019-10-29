/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:31:53 by qbragard          #+#    #+#             */
/*   Updated: 2019/07/16 16:44:43 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "viewer.h"

int	abs(int x)
{
	return (x < 0 ? -x : x);
}

int	bar_length(int len)
{
	int length;

	length = 0;
	while (len * length < (WIDTH / 4) - 20)
		length++;
	return (length);
}

int	rank(int nb, int *tab, int len)
{
	int i;
	int	count;

	i = -1;
	count = 1;
	while (++i < len)
		if (tab[i] < nb)
			count++;
	return (count);
}
