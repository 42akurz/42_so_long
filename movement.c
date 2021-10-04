/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 10:46:17 by akurz             #+#    #+#             */
/*   Updated: 2021/09/30 15:02:18 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	move_left(t_move *mv, t_vars *vars, int *count, int amountC)
{
	if (!(vars->map[vars->x_pos_P][vars->y_pos_P - 1] == '1'))
	{
		mv->exit_flag = check_left_exit(vars, amountC);
		if (mv->exit_flag == 0)
		{
			mlx_put_image_to_window(vars->mlx, vars->mlx_win, mv->img_floor,
				vars->y_pos_P * 32, vars->x_pos_P * 32);
			vars->map[vars->x_pos_P][vars->y_pos_P] = '0';
			vars->y_pos_P--;
			vars->map[vars->x_pos_P][vars->y_pos_P] = 'P';
			mlx_put_image_to_window(vars->mlx, vars->mlx_win, mv->img_angel,
				vars->y_pos_P * 32, vars->x_pos_P * 32);
			*count += 1;
		}
		mv->exit_flag = 0;
	}
}

void	move_right(t_move *mv, t_vars *vars, int *count, int amountC)
{
	mv->angel_path = "./img/reverse.xpm";
	mv->img_angel = mlx_xpm_file_to_image(vars->mlx, mv->angel_path,
			&mv->img_width, &mv->img_height);
	if (!(vars->map[vars->x_pos_P][vars->y_pos_P + 1] == '1'))
	{
		mv->exit_flag = check_right_exit(vars, amountC);
		if (mv->exit_flag == 0)
		{
			mlx_put_image_to_window(vars->mlx, vars->mlx_win, mv->img_floor,
				vars->y_pos_P * 32, vars->x_pos_P * 32);
			vars->map[vars->x_pos_P][vars->y_pos_P] = '0';
			vars->y_pos_P++;
			vars->map[vars->x_pos_P][vars->y_pos_P] = 'P';
			mlx_put_image_to_window(vars->mlx, vars->mlx_win, mv->img_angel,
				vars->y_pos_P * 32, vars->x_pos_P * 32);
			*count += 1;
		}
		mv->exit_flag = 0;
	}
}

void	move_down(t_move *mv, t_vars *vars, int *count, int amountC)
{
	if (!(vars->map[vars->x_pos_P + 1][vars->y_pos_P] == '1'))
	{
		mv->exit_flag = check_down_exit(vars, amountC);
		if (mv->exit_flag == 0)
		{
			mlx_put_image_to_window(vars->mlx, vars->mlx_win, mv->img_floor,
				vars->y_pos_P * 32, vars->x_pos_P * 32);
			vars->map[vars->x_pos_P][vars->y_pos_P] = '0';
			vars->x_pos_P++;
			vars->map[vars->x_pos_P][vars->y_pos_P] = 'P';
			mlx_put_image_to_window(vars->mlx, vars->mlx_win, mv->img_angel,
				vars->y_pos_P * 32, vars->x_pos_P * 32);
			*count += 1;
		}
		mv->exit_flag = 0;
	}
}

void	move_up(t_move *mv, t_vars *vars, int *count, int amountC)
{
	if (!(vars->map[vars->x_pos_P - 1][vars->y_pos_P] == '1'))
	{
		mv->exit_flag = check_up_exit(vars, amountC);
		if (mv->exit_flag == 0)
		{
			mlx_put_image_to_window(vars->mlx, vars->mlx_win, mv->img_floor,
				vars->y_pos_P * 32, vars->x_pos_P * 32);
			vars->map[vars->x_pos_P][vars->y_pos_P] = '0';
			vars->x_pos_P--;
			vars->map[vars->x_pos_P][vars->y_pos_P] = 'P';
			mlx_put_image_to_window(vars->mlx, vars->mlx_win, mv->img_angel,
				vars->y_pos_P * 32, vars->x_pos_P * 32);
			*count += 1;
		}
		mv->exit_flag = 0;
	}
}

void	movement(t_move *mv, t_vars *vars, int keycode, int amountC)
{
	static int	count;

	if (keycode == 0)
		move_left(mv, vars, &count, amountC);
	if (keycode == 2)
		move_right(mv, vars, &count, amountC);
	if (keycode == 1)
		move_down(mv, vars, &count, amountC);
	if (keycode == 13)
		move_up(mv, vars, &count, amountC);
	printf("%d\n", count);
}
