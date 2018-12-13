/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:49:45 by widraugr          #+#    #+#             */
/*   Updated: 2018/12/13 15:48:34 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	int		op;
	int		rea;
	char	buf[BUFF_SIZE + 1];

	if ((op = open(fd, O_RDONLY)) == -1)
	{
		write(2, "File name missing.\n", 19);
		return (1);
	}
	rea = read(op, buf, BUFF_SIZE);
	buf[rea] = '\0';
	ft_putstr(buf);
	if (close(op) == -1)
	{
		ft_putstr("close error");
		return (1);
	}
	return (0);
	
}
