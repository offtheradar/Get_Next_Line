/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 10:36:40 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/01 16:00:41 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		**read_file(int fd, char **file_holder)
{
	char	*tmp;
	int		read_ret_val;
	size_t	i;

	i = 0;
	tmp = malloc(sizeof(char) * BUFF_SIZE);
	while ((read_ret_val = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		if (file_holder[fd])
			file_holder[fd] = ft_strjoin(file_holder[fd], tmp);
		else
			file_holder[fd] = ft_strdup(tmp);
		ft_strclr(tmp);
	}
	free(tmp);
	if (read_ret_val < 0)
		return (-1);
	return (0);
}

static int		fetch_next_line_pos(t_file *file)
{
	size_t start;
	size_t i;

	i = 0;
	start = file->beginning_of_line_pos;
	while ((file->content)[start + i] != '\n')
		i++;
	return (i);
}

static t_file	**create_or_find_t_file(t_list **lst, int fd)
{
	t_list	*tmp;
	t_file	*file;

	tmp = *lst;
	while (tmp)
	{
		if ((t_file *)((tmp->content)->fd) == fd)
			return ((t_file *)(tmp->content));
		tmp = tmp->next;
	}
	tmp->content = read_file(fd);
	tmp->beginning_of_line_pos = 0;
	tmp->next_line_pos = get_next_line_pos(tmp);
	tmp->fd = fd;
}

int				get_next_line(const int fd, char **line)
{
	static	t_list;

	if (fd < 0 || !line || BUFF_SIZE < 0)
		return (-1);
}
