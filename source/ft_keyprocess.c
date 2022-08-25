/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyprocess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emyilmaz <emyilmaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 00:54:29 by emyilmaz          #+#    #+#             */
/*   Updated: 2022/08/23 16:58:47 by emyilmaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SLHEADER.h"

int	keyprocessing(int keyevent, t_data *data)
{
	if (keyevent == W || keyevent == UP)
	{
		data->player_y -= 1;
		player_w(data);
	}
	else if (keyevent == A || keyevent == LEFT)
	{
		data->player_x -= 1;
		player_a(data);
	}
	else if (keyevent == D || keyevent == RIGHT)
	{
		data->player_x += 1;
		player_d(data);
	}
	else if (keyevent == S || keyevent == DOWN)
	{
		data->player_y += 1;
		player_s(data);
	}
	return (1);
}
