/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 23:19:11 by emyilmaz          #+#    #+#             */
/*   Updated: 2022/08/23 18:06:20 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SLHEADER.h"

int	ft_mapcheck_char(t_data *data, int y, int x)
{
	while (data->mapstr[y])
	{
		x = 0;
		while (data->mapstr[y][x])
		{
			if (data->mapstr[y][x] == 'C')
				data->coin++;
			else if (data->mapstr[y][x] == 'P')
				data->player++;
			else if (data->mapstr[y][x] == 'E')
				data->exit++;
			x++;
		}
		y++;
	}
	if (data->coin >= 1 && data->player == 1 && data->exit >= 1)
		return (1);
	else
	{
		return (0);
		exit(1);
	}
	return (1);
}

int	ft_allcheck_char(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->coord_y)
	{
		x = 0;
		while (x < data->coord_x)
		{
			if (data->mapstr[y][x] == 'P' || data->mapstr[y][x] == 'E'
					|| data->mapstr[y][x] == 'C'
					|| data->mapstr[y][x] == '1' || data->mapstr[y][x] == '0')
				x++;
			else
			{
				return (0);
				exit(1);
			}
		}
		y++;
	}
	return (1);
}

int	ft_wallcheck(t_data *data)
{
	int	i;
	int	len;
	int	len2;

	len2 = data->coord_x - 1;
	len = data->coord_y - 1;
	i = 0;
	while (i < data->coord_x - 1)
	{
		if (data->mapstr[0][i] != '1' || data->mapstr[len][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < data->coord_y - 1)
	{
		if (data->mapstr[i][0] != '1' || data->mapstr[i][len2] != '1')
		{
			return (0);
			exit(1);
		}
		i++;
	}
	return (1);
}

int	ft_len_check(t_data *data)
{
	int	i;

	i = 0;
	if (!data->mapstr)
		return (0);
	while (i < data->coord_y)
	{
		if (ft_strlen(data->mapstr[0]) != ft_strlen(data->mapstr[i]))
		{
			return (0);
			exit(1);
		}
		i++;
	}
	return (1);
}

int	ft_map_control(t_data *data)
{
	data->coin = 0;
	data->exit = 0;
	data->player = 0;
	if (!ft_len_check(data))
		ft_putstr_color_fd(ANSI_YELLOW, "Map length wrong\n", 1);
	else if (!ft_mapcheck_char(data, 0, 0))
		ft_putstr_color_fd(ANSI_YELLOW, "number of item wrong\n", 1);
	else if (!ft_allcheck_char(data))
		ft_putstr_color_fd(ANSI_YELLOW, "invalid item\n", 1);
	else if (!ft_wallcheck(data))
		ft_putstr_color_fd(ANSI_YELLOW, "wall error\n", 1);
	data->coin = 0;
	data->exit = 0;
	data->player = 0;
	if (ft_len_check(data) && ft_mapcheck_char(data, 0, 0)
		&& ft_allcheck_char(data) && ft_wallcheck(data))
		return (1);
	else
		return (0);
}
