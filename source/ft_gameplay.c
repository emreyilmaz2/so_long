/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gameplay.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 01:15:23 by emyilmaz          #+#    #+#             */
/*   Updated: 2022/08/23 20:56:45 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SLHEADER.h"

static int	keypress(int keycode, t_data *data)
{
	data->kontrol = 1;
	if (keycode == ESC || keycode == Q)
	{
		write(1, "\033[1;34m\n--THE END--", 23);
		exit_game(data);
	}
	keyprocessing(keycode, data);
	if (data->kontrol == 1)
	{
		ft_putstr_color_fd(ANSI_YELLOW, "\rMoves: ", 1);
		ft_putstr_fd(ANSI_GREEN, 1);
		ft_printnbr(data->moves);
	}
	return (0);
}

void	gameplay(t_data *data)
{
	mlx_hook(data->win, 2, 0, keypress, data);
	mlx_hook(data->win, 17, 0, exit_game, data);
	mlx_hook(data->win, 12, 0, map_draw, data);
}
