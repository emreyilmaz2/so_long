/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_coordinate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 00:56:04 by emyilmaz          #+#    #+#             */
/*   Updated: 2022/08/23 01:13:48 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SLHEADER.h"

int	ft_get_mapsx(char *str)
{
	int			fd;
	int			counter;
	int			byte;
	char		p;

	byte = 1;
	fd = open(str, O_RDONLY);
	counter = 0;
	while (byte != 0)
	{
		byte = read(fd, &p, 1);
		if (p == '\n')
			break ;
		counter++;
	}
	return (counter);
}

int	ft_get_mapsy(char *str)
{
	int			fd;
	int			counter;
	int			byte;
	char		c;

	byte = 1;
	counter = 0;
	fd = open(str, O_RDONLY);
	while (byte != 0)
	{
		byte = read(fd, &c, 1);
		if (c == '\n')
			counter++;
		else if (c == '\0')
			break ;
	}
	close(fd);
	return (counter - 1);
}
