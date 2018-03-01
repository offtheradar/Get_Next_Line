/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysibous <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 10:36:40 by ysibous           #+#    #+#             */
/*   Updated: 2018/03/01 11:41:49 by ysibous          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		**read_file(int fd)
{
	char	*str;
	char	*tmp;
	size_t	i;

	i = 0;
	str = malloc(sizeof(char) * 1);
	tmp = malloc(sizeof(char) * 1);
	while (read(fd, &str[i], BUFF_SIZE) == 1)
	{
		free(tmp);
		tmp = ft_strnew(i + 1);
		tmp = ft_strncpy(tmp, str, i + 1);
		free(str);
		str = ft_strnew(i + 1);
		str = ft_strncpy(str, tmp, i + 1);
		i++;
	}
	free(tmp);
	return (str);
}

static int		get_next_line_pos(t_file *file)
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
