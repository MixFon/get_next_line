/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widraugr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:51:39 by widraugr          #+#    #+#             */
/*   Updated: 2018/12/21 18:48:27 by widraugr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

int main(void)
{
	int i;
	int j;
	int op;
	int opMain;
	char *arr;
	
	i = -1;
	j = 0;
	arr = NULL;
	op = open("test1", O_RDONLY);
	opMain = open("test2", O_RDONLY);
	/*while (j++ < 8)
	{
		i = get_next_line(op, &arr);
		ft_putstr(arr);
		ft_putnbr(i);
		ft_putstr("\n");
		free(arr);
	}*/
	i = 1;
	/*while (get_next_line(op, &arr))
	{
		ft_putstr(arr);
		//ft_putnbr(i);
		ft_putstr("\n");
		free(arr);
	}*/
	while (j++ < 6)
	{
		i = get_next_line(op, &arr);
		ft_putstr(arr);
		ft_putstr("\n");
		free(arr);
	
		i = get_next_line(opMain, &arr);
		ft_putstr(arr);
		ft_putstr("\n");
		free(arr);
	
	}
	close(opMain);
	if (close(op) == -1)
	{
		ft_putstr("close error");
		return (1);
	}
	return (0);
}
