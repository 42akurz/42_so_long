/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:19:52 by akurz             #+#    #+#             */
/*   Updated: 2021/09/30 15:05:51 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	check_up_exit(t_vars *vars, int amountC)
{
	if (vars->map[vars->x_pos_P - 1][vars->y_pos_P] == 'E' && amountC != 0)
	{
		return (1);
	}
	if (vars->map[vars->x_pos_P - 1][vars->y_pos_P] == 'E' && amountC == 0)
	{
		ft_putstr_fd("YOU WON!\n", 1);
		exit(0);
	}
	return (0);
}

int	check_down_exit(t_vars *vars, int amountC)
{
	if (vars->map[vars->x_pos_P + 1][vars->y_pos_P] == 'E' && amountC != 0)
	{
		return (1);
	}
	if (vars->map[vars->x_pos_P + 1][vars->y_pos_P] == 'E' && amountC == 0)
	{
		ft_putstr_fd("YOU WON!\n", 1);
		exit(0);
	}
	return (0);
}

int	check_right_exit(t_vars *vars, int amountC)
{
	if (vars->map[vars->x_pos_P][vars->y_pos_P + 1] == 'E' && amountC != 0)
	{
		return (1);
	}
	if (vars->map[vars->x_pos_P][vars->y_pos_P + 1] == 'E' && amountC == 0)
	{
		ft_putstr_fd("YOU WON!\n", 1);
		exit(0);
	}
	return (0);
}

int	check_left_exit(t_vars *vars, int amountC)
{
	if (vars->map[vars->x_pos_P][vars->y_pos_P - 1] == 'E' && amountC != 0)
	{
		return (1);
	}
	if (vars->map[vars->x_pos_P][vars->y_pos_P - 1] == 'E' && amountC == 0)
	{
		ft_putstr_fd("YOU WON!\n", 1);
		exit(0);
	}
	return (0);
}
