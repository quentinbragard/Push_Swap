/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 14:59:35 by qbragard          #+#    #+#             */
/*   Updated: 2019/05/25 20:00:56 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_tab_int(int len, int *tab)
{
	int i;

	if (!tab)
		return ;
	i = 0;
	while (i < len)
	{
		ft_putstr("tab[");
		ft_putnbr(i);
		ft_putstr("] = ");
		ft_putnbr(tab[i]);
		ft_putchar('\n');
		i++;
	}
}
