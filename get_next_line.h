/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 18:48:05 by ysibous           #+#    #+#             */
/*   Updated: 2018/02/28 20:41:05 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# include "libft.h"
# define GET_NEXT_LINE_H
# define BUFFER 4096

/*
** The t_file data type holds information on the file.
** line_content - holds the file info
** next_line_pos - holds the index of the next '\n' character
** fd is the file descriptor
*/

typedef struct	s_file
{
	char		*file_content;
	int			file_len;
	int			next_line_pos;
	int			fd;
}				t_file;

int				get_next_line(const int fd, char **line);
# endif
