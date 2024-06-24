/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:31:39 by iarrar            #+#    #+#             */
/*   Updated: 2024/06/24 17:12:55 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_choose_img(char c, t_data *data, int x, int y)
{
	int mask_x, mask_y, sensitivity;

	mask_x = data->player.posx - x;
	mask_y = data->player.posy - y;

	// modify this data for steps sensitivity
	int nb_steps = 80;
	
	sensitivity = (rand() % nb_steps - data->count)  + 1;
	if (sensitivity < 3)
		sensitivity = 1;

	if (c == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player.sprite.mlx_img, ft_crdn(x, data), ft_crdn(y, data));
	else if ((mask_x >= sensitivity * -1 && mask_x <= sensitivity) && (mask_y >= sensitivity * -1 && mask_y <= sensitivity)) // mask condition
	{
		if (c == '1')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->wall.sprite.mlx_img, ft_crdn(x, data), ft_crdn(y, data));
		else if (c == '0')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->font.sprite.mlx_img, ft_crdn(x, data), ft_crdn(y, data));
		else if (c == 'C')
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->cookie.sprite.mlx_img, ft_crdn(x, data), ft_crdn(y, data));
		else if (c == 'E')
		{
			if (ft_cookiz(data->map) != 0)
				mlx_put_image_to_window(data->mlx_ptr,
					data->win_ptr, data->exit_close.sprite.mlx_img,
					ft_crdn(x, data), ft_crdn(y, data));
			else
				mlx_put_image_to_window(data->mlx_ptr,
					data->win_ptr, data->exit_open.sprite.mlx_img, ft_crdn(x, data),
					ft_crdn(y, data));
		}
	}
	else // no mask
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->black.sprite.mlx_img, ft_crdn(x, data), ft_crdn(y, data));
	}
}

int	check_elements(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] != '1' && map[j][i] != '0' && map[j][i] != 'E'
				&& map[j][i] != 'C' && map[j][i] != 'P')
			{
				ft_putstr_fd("Element non compatible sur la carte\n", 2);
				return (504);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	ft_ciao(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data->str);
	ft_freetabtab(data->map);
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_init_all(t_data *data)
{
	ft_dimension(data);
	data->count = 0;
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_width,
			data->win_height,
			"So_long window!");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (1);
	}
	if (ft_errmsg(data->map) == 0)
	{
		data->player = ft_searstruct(data->map, 'P');
		data->exit = ft_searstruct(data->map, 'E');
	}
	return (0);
}
