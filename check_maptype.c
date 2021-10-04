/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maptype.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 14:51:13 by akurz             #+#    #+#             */
/*   Updated: 2021/09/30 14:37:10 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	check_maptype(char **argv)
{
	int	x;

	x = ft_strlen(argv[1]);
	x -= 1;
	if (argv[1][x] != 'r')
	{
		ft_putstr_fd("ERROR\nNot a valid map!\n", 2);
		exit(0);
	}
	if (argv[1][x - 1] != 'e')
	{
		ft_putstr_fd("ERROR\nNot a valid map!\n", 2);
		exit(0);
	}
	if (argv[1][x - 2] != 'b')
	{
		ft_putstr_fd("ERROR\nNot a valid map!\n", 2);
		exit(0);
	}
	if (argv[1][x - 3] != '.')
	{
		ft_putstr_fd("ERROR\nNot a valid map!\n", 2);
		exit(0);
	}
}

int	close_window(void)
{
	exit(0);
}

void	put_orbit(void *mlx, void *mlx_win, int *x, int *y)
{
	void	*img;
	int		img_width;
	int		img_height;
	char	*path;

	path = "./img/3_orbit.xpm";
	img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	mlx_put_image_to_window(mlx, mlx_win, img, (*y) * 32, (*x) * 32);
}

char	*ft_joinline(char *join, char *line)
{
	char	*temp;

	temp = ft_strjoin(join, line);
	free(join);
	free(line);
	join = temp;
	return (join);
}
