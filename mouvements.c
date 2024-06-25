/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvements.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:48:23 by iarrar            #+#    #+#             */
/*   Updated: 2024/06/25 11:00:46 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	move_left(t_data *data)
{
	if (data->map[data->player.posy][data->player.posx - 1] == 'M')
		ft_ciao(data);
	else if (data->map[data->player.posy][data->player.posx - 1] != '1')
	{
		data->map[data->player.posy][data->player.posx] = '0';
		data->map[data->exit.posy][data->exit.posx] = 'E';
		data->map[data->player.posy][data->player.posx - 1] = 'P';
		data->player.posx--;
		data->count ++;
		return (1);
	}
	return (0);
}

int	move_right(t_data *data)
{
	if (data->map[data->player.posy][data->player.posx + 1] == 'M')
		ft_ciao(data);
	else if (data->map[data->player.posy][data->player.posx + 1] != '1')
	{
		data->map[data->player.posy][data->player.posx] = '0';
		data->map[data->exit.posy][data->exit.posx] = 'E';
		data->map[data->player.posy][data->player.posx + 1] = 'P';
		data->player.posx++;
		data->count ++;
		return (1);
	}
	return (0);
}

int	move_up(t_data *data)
{
	if (data->map[data->player.posy - 1][data->player.posx] == 'M')
		ft_ciao(data);
	else if (data->map[data->player.posy - 1][data->player.posx] != '1')
	{
		data->map[data->player.posy][data->player.posx] = '0';
		data->map[data->exit.posy][data->exit.posx] = 'E';
		data->map[data->player.posy - 1][data->player.posx] = 'P';
		data->player.posy--;
		data->count ++;
		return (1);
	}
	return (0);
}

int	move_down(t_data *data)
{
	if (data->map[data->player.posy + 1][data->player.posx] == 'M')
		ft_ciao(data);
	if (data->map[data->player.posy + 1][data->player.posx] != '1')
	{
		data->map[data->player.posy][data->player.posx] = '0';
		data->map[data->exit.posy][data->exit.posx] = 'E';
		data->map[data->player.posy + 1][data->player.posx] = 'P';
		data->player.posy++;
		data->count ++;
		return (1);
	}
	return (0);
}
