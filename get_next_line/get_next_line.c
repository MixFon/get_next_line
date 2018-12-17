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
	int		rea;
	char	buf[BUFF_SIZE + 1];
	char	*cop;
	char	*temp;

	cop = ft_strnew(1);
	line = NULL;
	while((rea = read(fd, buf, BUFF_SIZE)))
	{
		buf[rea] = '\0';
		temp = ft_strnjoin(cop, buf);
		free(cop);
		cop = ft_strdup(temp);
		free(temp);
		if(ft_strchr(buf, '\n'))
		{
			
			break ;
		}
	}
		ft_putchar('\n');
		ft_putstr(cop);
		ft_putchar('\n');

	return (0);
	
}
