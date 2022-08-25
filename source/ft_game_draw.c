/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 01:22:03 by emyilmaz          #+#    #+#             */
/*   Updated: 2022/08/23 19:57:14 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SLHEADER.h"

void	img_draw(t_data *game, void *image, int x, int y)
{
	mlx_put_image_to_window
		(game->mlx, game->win, image, x * 40, y * 40);
}

static void	player_draw(t_data *game, void *image, int x, int y)
{
	game->player_x = x;
	game->player_y = y;
	img_draw(game, image, x, y);
}

static void	exit_draw(t_data *game, int x, int y)
{
	if (game->coin == 0)
	{
		mlx_destroy_image(game->mlx, game->img_exit);
		game->img_exit = mlx_xpm_file_to_image
			(game->mlx, "./assets/exit22.xpm", &game->img_w, &game->img_h);
	}
	img_draw(game, game->img_exit, x, y);
}

int	map_draw(t_data *game, int a)
{
	int	y;
	int	x;

	y = -1;
	while (game->mapstr[++y])
	{
		x = -1;
		while (game->mapstr[y][++x])
		{
			if (game->mapstr[y][x] == '1')
				img_draw(game, game->img_wall, x, y);
			else if (game->mapstr[y][x] == '0')
				img_draw(game, game->img_backg, x, y);
			else if (game->mapstr[y][x] == 'P' && a == 3)
				player_draw(game, game->img_player, x, y);
			else if (game->mapstr[y][x] == 'P' && (a == 1 || a == 2))
				player_draw(game, game->img_player2, x, y);
			else if (game->mapstr[y][x] == 'C')
				img_draw(game, game->img_collect, x, y);
			else if (game->mapstr[y][x] == 'E')
				exit_draw(game, x, y);
		}
	}
	return (0);
}
