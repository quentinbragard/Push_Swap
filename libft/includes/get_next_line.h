/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 20:49:15 by qbragard          #+#    #+#             */
/*   Updated: 2019/05/28 10:14:07 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define BUFF_SIZE 1

typedef struct			s_list_gnl
{
	char				*content;
	int					file_des;
	struct s_list_gnl	*next;
}						t_list_gnl;

int						get_next_line(const int fd, char **line);
int						read_line(int fd, t_list_gnl *list, char **line);
int						return_gnl(int fd, t_list_gnl *tmp, t_list_gnl *list,
		char **line);

#endif
