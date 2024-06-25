/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 21:24:31 by iarrar            #+#    #+#             */
/*   Updated: 2024/06/25 10:57:00 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_crdn(int x, t_data *data)
{
	data->dimension = 128;
	return (x * data->dimension);
}

void	ft_dimension(t_data *data)
{
	data->dimension = 128;
	data->win_height = ft_tabtabstrlen(data->map) * data->dimension;
	data->win_width = ft_strlen(data->map[0]) * data->dimension;
	data->map_height = ft_tabtabstrlen(data->map);
	data->map_width = ft_strlen(data->map[0]);
}

void	ft_init_img(t_data *data)
{
	int	img_height;
	int	img_width;

	data->black.sprite.mlx_img = mlx_xpm_file_to_image
		(data->mlx_ptr, "./img/black.xpm", &img_height, &img_width);

	data->enemy.sprite.mlx_img = mlx_xpm_file_to_image
		(data->mlx_ptr, "./img/loup.xpm", &img_height, &img_width);

	data->player_2.sprite.mlx_img = mlx_xpm_file_to_image
		(data->mlx_ptr, "./img/mouton.xpm", &img_height, &img_width);
	
	data->player.sprite.mlx_img = mlx_xpm_file_to_image
		(data->mlx_ptr, "./img/right_boo.xpm", &img_height, &img_width);
		
	data->wall.sprite.mlx_img = mlx_xpm_file_to_image
		(data->mlx_ptr, "./img/rideau.xpm", &img_height, &img_width);
		
	data->font.sprite.mlx_img = mlx_xpm_file_to_image
		(data->mlx_ptr, "./img/floor.xpm", &img_height, &img_width);
		
	data->exit_open.sprite.mlx_img = mlx_xpm_file_to_image
		(data->mlx_ptr, "./img/exit_open.xpm", &img_height, &img_width);
		
	data->exit_close.sprite.mlx_img = mlx_xpm_file_to_image
		(data->mlx_ptr, "./img/exit_close.xpm", &img_height, &img_width);
		
	data->cookie.sprite.mlx_img = mlx_xpm_file_to_image
		(data->mlx_ptr, "./img/licorn.xpm", &img_height, &img_width);
}

void	put_image(t_data *data)
{
	int	x;
	int	y;

	/*
	X X X
	X P X
	X X X
	
	*/

	x = 0;
	y = 0;
	ft_init_img(data);
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			ft_choose_img(data->map[y][x], data, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	free_image(data);
}

void	free_image(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->player.sprite.mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->cookie.sprite.mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->wall.sprite.mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->font.sprite.mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->exit_open.sprite.mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->exit_close.sprite.mlx_img);
}
