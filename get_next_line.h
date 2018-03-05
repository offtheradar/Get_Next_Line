/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:48:05 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/01 16:00:34 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# include "libft.h"
# define GET_NEXT_LINE_H
# define BUFFER 4096
# define MAX_FD 4867

/*
** The t_file data type holds information on the file.
** line_content - holds the file info
** next_line_pos - holds the index of the next '\n' character
** fd is the file descriptor
*/

static int		read_file(int fd, char **file_holder);

int				get_next_line(const int fd, char **line);
# endif
