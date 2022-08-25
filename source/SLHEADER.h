/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SLHEADER.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 01:49:58 by emyilmaz          #+#    #+#             */
/*   Updated: 2022/08/23 20:55:04 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SLHEADER_H
# define SLHEADER_H
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include "../mlx/mlx.h"
# include "../ft_printf/ft_printf.h"
# include "../gnl_fake/get_next_line.h"

typedef struct s_data
{
	char	**mapstr;
	int		coord_x;
	int		coord_y;
	int		coin;
	int		player;
	int		exit;
	void	*mlx;
	void	*image;
	int		x;
	int		y;
	int		player_x;
	int		player_y;
	void	*img_backg;
	void	*img_wall;
	void	*img_player;
	void	*img_player2;
	void	*img_collect;
	void	*img_exit;
	void	*win;
	int		img_w;
	int		img_h;
	int		moves;
	int		kontrol;
	int		c;

}	t_data;

# define A 0
# define S 1
# define D 2
# define W 13
# define ESC 53
# define Q 12
# define UP 126
# define DOWN 125
# define RIGHT 124
# define LEFT 123
# define PIXEL 40

int		ft_get_mapsx(char *str);
int		ft_get_mapsy(char *str);
int		ft_map_control(t_data *data);
int		ft_wallcheck(t_data *data);
int		ft_allcheck_char(t_data *data);
int		ft_mapcheck_char(t_data *data, int y, int x);
int		keyprocessing(int keyevent, t_data *data);
int		loop(t_data *data);
int		setup(t_data *data, char *path);
int		control(t_data *data, char *path);
int		map_draw(t_data *game, int a);
int		exit_game(t_data *game);

void	gameplay(t_data *game);
void	ft_charcheck(t_data *data);
void	update(t_data *data);
void	ft_create_matrix(t_data *data, char *str, int x, int y);
void	draw(t_data *data);
void	map_init(t_data *data);
void	img_draw(t_data *game, void *image, int x, int y);
void	player_w(t_data *data);
void	player_s(t_data *data);
void	player_d(t_data *data);
void	player_a(t_data *data);
void	free_map(t_data *data);

#endif
