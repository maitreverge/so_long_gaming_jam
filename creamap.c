/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creamap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flverge <flverge@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 19:06:24 by iarrar            #+#    #+#             */
/*   Updated: 2024/06/25 11:14:13 by flverge          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

#define BUFFER_SIZE 5000

int	ft_searchar(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

t_player	ft_searstruct(char **map, char c)
{
	t_player	cacahuete;

	cacahuete.posx = -1;
	cacahuete.posy = 0;
	while (cacahuete.posx == -1)
	{
		cacahuete.posx = ft_searchar(map[cacahuete.posy], c);
		cacahuete.posy++;
	}
	cacahuete.posy--;
	return (cacahuete);
}

void	ft_freetabtab(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int inputHardcore(int keysym, t_data *data)
{
	int random[4] = {XK_Left, XK_Down, XK_Up, XK_Right};

	for (int i = 0; i < 4; i++) {
        int randomIndex = rand() % 4;
        char temp = random[i];
        random[i] = random[randomIndex];
        random[randomIndex] = temp;
	}
	
	if (keysym == random[0])
		move_left(data);
	else if (keysym == random[1])
		move_down(data);
	else if (keysym == random[2])
		move_up(data);
	else if (keysym == random[3])
		move_right(data);
	put_image(data);
	ft_printf("\033[H\033[J");
	ft_printf("total moves = %d\n", data->count);
	if (ft_endgame(data) == 1 || keysym == XK_Escape)
	{
		if (ft_endgame(data) == 1)
		{
			ft_printf("!!! YOU WIN !!!\nCongatulations !\n");
			ft_printf("map cleared in %d moves\n", data->count);
		}
		ft_ciao(data);
	}
	return (0);
}

int	handle_input(int keysym, t_data *data)
{
	/*
	#define XK_Left                          0xff51 
#define XK_Up                            0xff52 
#define XK_Right                         0xff53 
#define XK_Down                          0xff54 
	*/
	if (g_HARDCORE)
		inputHardcore(keysym, data);
	else
	{
		if (keysym == XK_Left)
			move_left(data);
		else if (keysym == XK_Down)
			move_down(data);
		else if (keysym == XK_Up)
			move_up(data);
		else if (keysym == XK_Right)
			move_right(data);
		put_image(data);
		ft_printf("\033[H\033[J");
		ft_printf("total moves = %d\n", data->count);
		if (ft_endgame(data) == 1 || keysym == XK_Escape)
		{
			if (ft_endgame(data) == 1)
			{
				ft_printf("!!! YOU WIN !!!\nCongatulations !\n");
				ft_printf("map cleared in %d moves\n", data->count);
			}
			ft_ciao(data);
		}
	}
	return (0);
}

int	get_map(char *str, t_data *data)
{
	int		ret;
	int		total_len;
	char	*buf;

	buf = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	ret = read(open(str, O_RDONLY), buf, BUFFER_SIZE);
	total_len = ret;
	if (ret == -1)
	{
		ft_putstr_fd("Invalid map name\n", 2);
		free(buf);
		return (0);
	}
	if (ret == 0)
	{
		free(buf);
		return (0);
	}
	data->str = ft_strdup(buf);
	free(buf);
	if (data->str)
		data->map = ft_split(data->str, '\n');
	else
		free(data->str);
	return (total_len);
}

