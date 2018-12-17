/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:51:39 by widraugr          #+#    #+#             */
/*   Updated: 2018/12/13 15:47:56 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

int main(void)
{
	int i;
	int op;
	char **arr;

	i = 0;
	arr = NULL;
	if ((op = open("txt", O_RDONLY)) == -1)
	{
		write(2, "File name missing.\n", 19);
		return (1);
	}
	i = get_next_line(op, arr);
	i = get_next_line(op, arr);
	i = get_next_line(op, arr);
	if (close(op) == -1)
	{
		ft_putstr("close error");
		return (1);
	}
	return (0);
}
