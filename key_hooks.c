/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 11:00:53 by akurz             #+#    #+#             */
/*   Updated: 2021/09/30 15:01:31 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	get_collectable_amount(t_vars *vars)
{
	int	x;
	int	y;
	int	amountC;

	amountC = 0;
	x = 0;
	y = 0;
	while (x < vars->rows)
	{
		while (y < vars->columns)
		{
			if (vars->map[x][y] == 'C')
				amountC++;
			y++;
		}
		y = 0;
		x++;
	}
	return (amountC);
}

void	get_player_pos(t_vars *vars)
{
	vars->x_pos_P = 0;
	vars->y_pos_P = 0;
	while (vars->x_pos_P < vars->rows)
	{
		while (vars->y_pos_P < vars->columns)
		{
			if (vars->map[vars->x_pos_P][vars->y_pos_P] == 'P')
				return ;
			vars->y_pos_P++;
		}
		vars->y_pos_P = 0;
		vars->x_pos_P++;
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	t_move		mv;
	int			amountC;

	mv.floor_path = "./img/3_floor.xpm";
	mv.img_floor = mlx_xpm_file_to_image(vars->mlx, mv.floor_path,
			&mv.img_width, &mv.img_height);
	mv.angel_path = "./img/3_angel.xpm";
	mv.img_angel = mlx_xpm_file_to_image(vars->mlx, mv.angel_path,
			&mv.img_width, &mv.img_height);
	amountC = get_collectable_amount(vars);
	get_player_pos(vars);
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(0);
	}
	movement(&mv, vars, keycode, amountC);
	return (0);
}
