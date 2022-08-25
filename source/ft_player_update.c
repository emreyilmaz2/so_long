/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_update.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 23:18:55 by emyilmaz          #+#    #+#             */
/*   Updated: 2022/08/23 18:20:22 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SLHEADER.h"

void	player_w(t_data *data)
{
	if (data->mapstr[data->player_y][data->player_x] == 'E' && data->coin == 0)
	{
		mlx_clear_window(data->mlx, data->win);
		data->mapstr[data->player_y + 1][data->player_x] = '0';
		data->moves++;
		map_draw(data, 2);
		ft_putstr_color_fd(ANSI_GREEN, "\nFINISHED:)", 1);
		exit(0);
	}
	else if (data->mapstr[data->player_y][data->player_x] == '1'
			|| data->mapstr[data->player_y][data->player_x] == 'E')
	{
		data->player_y += 1;
		data->kontrol = 0;
	}
	else
	{
		mlx_clear_window(data->mlx, data->win);
		if (data->mapstr[data->player_y][data->player_x] == 'C')
			data->coin -= 1;
		data->mapstr[data->player_y][data->player_x] = 'P';
		data->mapstr[data->player_y + 1][data->player_x] = '0';
		data->moves++;
		map_draw(data, 2);
	}
}

void	player_s(t_data *data)
{
	if (data->mapstr[data->player_y][data->player_x] == 'E' && data->coin == 0)
	{
		mlx_clear_window(data->mlx, data->win);
		data->mapstr[data->player_y - 1][data->player_x] = '0';
		data->moves++;
		map_draw(data, 2);
		ft_putstr_color_fd(ANSI_GREEN, "FINISHED:)", 1);
		exit(0);
	}
	else if (data->mapstr[data->player_y][data->player_x] == '1'
		|| data->mapstr[data->player_y][data->player_x] == 'E')
	{
		data->player_y -= 1;
		data->kontrol = 0;
	}
	else
	{
		mlx_clear_window(data->mlx, data->win);
		if (data->mapstr[data->player_y][data->player_x] == 'C')
			data->coin -= 1;
		data->mapstr[data->player_y][data->player_x] = 'P';
		data->mapstr[data->player_y - 1][data->player_x] = '0';
		data->moves++;
		map_draw(data, 2);
	}
}

void	player_d(t_data *data)
{
	if (data->mapstr[data->player_y][data->player_x] == 'E' && data->coin == 0)
	{
		mlx_clear_window(data->mlx, data->win);
		data->mapstr[data->player_y][data->player_x - 1] = '0';
		data->moves++;
		map_draw(data, 3);
		ft_putstr_color_fd(ANSI_GREEN, "\nFINISHED:)", 1);
		exit(0);
	}
	else if (data->mapstr[data->player_y][data->player_x] == '1'
		|| data->mapstr[data->player_y][data->player_x] == 'E')
	{
		data->player_x -= 1;
		data->kontrol = 0;
	}
	else
	{
		mlx_clear_window(data->mlx, data->win);
		if (data->mapstr[data->player_y][data->player_x] == 'C')
			data->coin -= 1;
		data->mapstr[data->player_y][data->player_x] = 'P';
		data->mapstr[data->player_y][data->player_x - 1] = '0';
		data->moves++;
		map_draw(data, 3);
	}
}

void	player_a(t_data *data)
{
	if (data->mapstr[data->player_y][data->player_x] == 'E' && data->coin == 0)
	{
		mlx_clear_window(data->mlx, data->win);
		data->mapstr[data->player_y][data->player_x + 1] = '0';
		data->moves++;
		map_draw(data, 1);
		ft_putstr_color_fd(ANSI_GREEN, "\nFINISHED:)", 1);
		exit(0);
	}
	else if (data->mapstr[data->player_y][data->player_x] == '1'
		|| data->mapstr[data->player_y][data->player_x] == 'E')
	{
		data->kontrol = 0;
		data->player_x += 1;
	}
	else
	{
		mlx_clear_window(data->mlx, data->win);
		if (data->mapstr[data->player_y][data->player_x] == 'C')
			data->coin -= 1;
		data->mapstr[data->player_y][data->player_x] = 'P';
		data->mapstr[data->player_y][data->player_x + 1] = '0';
		data->moves++;
		map_draw(data, 1);
	}
}
