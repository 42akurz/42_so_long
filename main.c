/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:21:08 by akurz             #+#    #+#             */
/*   Updated: 2021/09/30 15:10:28 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	check_errors(int argc, char **argv)
{
	if (argv[1] == NULL)
	{
		ft_putstr_fd("ERROR\nMissing map\n", 2);
		exit(0);
	}
	if (argc != 2)
	{
		ft_putstr_fd("ERROR\nMore or less then 2 arguments!\n", 2);
		exit(0);
	}
	if (ft_strlen(argv[1]) <= 4)
	{
		ft_putstr_fd("ERROR\nNot a valid map!\n", 2);
		exit(0);
	}
	check_maptype(argv);
}

void	check_map_sides(char **map, int *rows, int *columns)
{
	int	x;

	x = 0;
	while (x < (*rows) - 1)
	{
		if (map[x][0] != '1' || map[x][(*columns) - 1] != '1')
		{
			ft_putstr_fd("ERROR\nNot a closed map!\n", 2);
			exit(0);
		}
		x++;
	}
}

void	check_map(char **map, int *rows, int *columns)
{
	int	x;
	int	y;

	x = 0;
	while (x < (*rows) - 1)
	{
		if (((int)ft_strlen(map[x]) - 1) != *columns)
		{
			ft_putstr_fd("ERROR\nNot a rectengular map!\n", 2);
			exit(0);
		}
		x++;
	}
	y = 0;
	while (map[0][y] != '\n' && map[x][y] != '\n')
	{
		if (map[0][y] != '1' || map[x][y] != '1')
		{
			ft_putstr_fd("ERROR\nNot a closed map!\n", 2);
			exit(0);
		}
		y++;
	}
	check_map_sides(map, rows, columns);
}

char	**create_map(char **argv, int *rows, int *columns)
{
	char	**map;
	int		fd;
	char	*join;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	join = get_next_line(fd);
	(*rows) = 1;
	while (join != NULL)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		join = ft_joinline(join, line);
		(*rows) += 1;
	}
	check_map_content(join);
	map = ft_split(join, '\n', columns);
	free(join);
	check_map(map, rows, columns);
	close(fd);
	return (map);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	check_errors(argc, argv);
	vars.mlx = mlx_init();
	vars.map = create_map(argv, &vars.rows, &vars.columns);
	vars.mlx_win = mlx_new_window(vars.mlx, vars.columns * 32, vars.rows * 32,
			"gold angel");
	create_images(&vars);
	mlx_key_hook(vars.mlx_win, key_hook, &vars);
	mlx_hook(vars.mlx_win, 17, (1L << 17), close_window, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

/*
1. Check for valid input.
2. initiallize mlx.
3. Put the map in 2D array and check if it is rule conform.
	(rectangle, closed, valid chars, etc)
4. Create window in matching size to the map.
5. Fill the window with images.
6. key hooks to move the character.
7. mlx hook: event when clicking the red X on the window.
8. mlx loop: recreate the window after each move!
*/