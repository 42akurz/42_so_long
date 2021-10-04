/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 11:51:37 by akurz             #+#    #+#             */
/*   Updated: 2021/09/30 14:36:52 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	put_wall(void *mlx, void *mlx_win, int *x, int *y)
{
	void	*img;
	int		img_width;
	int		img_height;
	char	*path;

	path = "./img/3_wall.xpm";
	img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, (*y) * 32, (*x) * 32);
}

void	put_gold(void *mlx, void *mlx_win, int *x, int *y)
{
	void	*img;
	int		img_width;
	int		img_height;
	char	*path;

	path = "./img/3_gold.xpm";
	img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, (*y) * 32, (*x) * 32);
}

void	put_floor(void *mlx, void *mlx_win, int *x, int *y)
{
	void	*img;
	int		img_width;
	int		img_height;
	char	*path;

	path = "./img/3_floor.xpm";
	img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, (*y) * 32, (*x) * 32);
}

void	put_angel(void *mlx, void *mlx_win, int *x, int *y)
{
	void	*img;
	int		img_width;
	int		img_height;
	char	*path;

	path = "./img/3_angel.xpm";
	img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, (*y) * 32, (*x) * 32);
}

void	create_images(t_vars *vars)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < vars->rows)
	{
		while (y < vars->columns)
		{
			put_floor(vars->mlx, vars->mlx_win, &x, &y);
			if (vars->map[x][y] == '1')
				put_wall(vars->mlx, vars->mlx_win, &x, &y);
			if (vars->map[x][y] == 'C')
				put_gold(vars->mlx, vars->mlx_win, &x, &y);
			if (vars->map[x][y] == 'P')
				put_angel(vars->mlx, vars->mlx_win, &x, &y);
			if (vars->map[x][y] == 'E')
				put_orbit(vars->mlx, vars->mlx_win, &x, &y);
			y++;
		}
		y = 0;
		x++;
	}
}
