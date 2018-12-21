/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:49:45 by widraugr          #+#    #+#             */
/*   Updated: 2018/12/21 18:48:21 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_newlst	*ft_crealst(t_newlst *lst, const int fd)
{
	if (!lst)
	{
		if (!(lst = (t_newlst *)malloc(sizeof(t_newlst))))
			return (NULL);
		lst->fd = fd;
		lst->tail = ft_strnew(0);
		lst->next = NULL;
	}
	return (lst);
}

static t_newlst	*ft_iterlst(t_newlst *lst, const int fd)
{
	t_newlst	*iter;

	iter = NULL;
	iter = lst;
	while (iter)
	{
		if (iter->fd == fd)
			return (iter);
		iter = iter->next;
	}
	if (!iter)
		iter = ft_crealst(iter, fd);
	if (lst && lst != iter)
		lst->next = iter;
	return (iter);
}

static int		ft_cuttail(t_newlst *lst, char **line)
{
	char	*temp;
	int		num;

	num = ft_strcl(lst->tail, '\n');
	*line = ft_strnjoin("", lst->tail);
	temp = ft_strdup(lst->tail);
	lst->tail = ft_strsub(temp, num + 1, ft_strlen(lst->tail) - num);
	ft_strdel(&temp);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_newlst *lst;
	char			*buf;
	char			*temp;
	long			rea;
	long			num;

	buf = NULL;
	if (fd < 0 || !line || !(*line = ft_strnew(0)) || BUFF_SIZE < 1 || read(fd, 0, 0) < 0)
		return (-1);
	lst = ft_iterlst(lst, fd);
	if (lst->tail && ft_strchr(lst->tail, '\n'))
		return (ft_cuttail(lst, line));
	*line = ft_strnjoin(*line, lst->tail);
	//ft_strdel(&lst->tail);
	if (!(buf = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	while ((rea = read(lst->fd, buf, BUFF_SIZE)))
	{
		buf[rea] = '\0';
		temp = ft_strnjoin(*line, buf);
		ft_strdel(line);
		*line = ft_strdup(temp);
		ft_strdel(&temp);
		if (ft_strchr(buf, '\n'))
		{
			num = ft_strcl(buf, '\n');
			lst->tail = ft_strsub(buf, num + 1, BUFF_SIZE - num);
			ft_strdel(&buf);
			return (1);
		}
		if (rea < BUFF_SIZE)
			return (1);
	}
		return (0);
}
