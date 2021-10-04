/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 09:33:50 by akurz             #+#    #+#             */
/*   Updated: 2021/09/30 16:15:41 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_flag
{
	int	flagC;
	int	flagE;
	int	flagP;
	int	flag1;
	int	flag0;
	int	x;
	int	strlen;
}			t_flag;

typedef struct s_mlx_vars
{
	void	*mlx;
	void	*mlx_win;
	char	**map;
	int		rows;
	int		columns;
	int		x_pos_P;
	int		y_pos_P;
}			t_vars;

typedef struct s_movement
{
	void	*img_floor;
	char	*floor_path;
	void	*img_angel;
	char	*angel_path;
	int		img_width;
	int		img_height;
	int		exit_flag;
}			t_move;

char	*get_next_line(int fd);

/* Puts map into an 2D array and checks if the content is valid. */
/* Checks, if the map is formatted correctly:
- rectangular
- surrounded by walls */
char	**create_map(char **argv, int *rows, int *columns);

/* Iterates through the 2D array and puts the corresponding image
for each character to the map. */
void	create_images(t_vars *vars);

/* Checks, that there is 1 E, 1 P and at least 1 C.
Checks for valid characters in map. */
void	check_map_content(char *join);

/* Checks, that map extension is (.ber) */
void	check_maptype(char **argv);

/* Closes program if (esc) is pressed and handles the movement */
int		key_hook(int keycode, t_vars *vars);

/*
1. For each move check if the player would get on the exit. If he would
	get on it, without having collected all (C) nothing happens!
	If else he collected everything and gets on the exit, he wins!
2. If he is not about to move in the exit or a wall,
	the folowing steps happpen.
	- The img of the player changes into a floor, before the upcoming move.
	- If he collects a collectable, the C will became a 0 on the **map.
	- The postion of the player changes, depending on the move.
	- New player image gets created at the new position.
	- Move count goes up.
*/
void	movement(t_move *mv, t_vars *vars, int keycode, int amountC);
int		check_up_exit(t_vars *vars, int amountC);
int		check_down_exit(t_vars *vars, int amountC);
int		check_left_exit(t_vars *vars, int amountC);
int		check_right_exit(t_vars *vars, int amountC);

/* If the player clicks the red X at top left of the window the game ends. */
int		close_window(void);
void	put_orbit(void *mlx, void *mlx_win, int *x, int *y);
char	*ft_joinline(char *join, char *line);

#endif