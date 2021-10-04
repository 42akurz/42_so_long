/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:01:37 by akurz             #+#    #+#             */
/*   Updated: 2021/09/30 14:34:07 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	check_the_flags(t_flag *flag)
{
	if (flag->flagC == 0 || flag->flagE == 0 || flag->flagP == 0
		|| flag->flag1 == 0 || flag->flag0 == 0)
	{
		ft_putstr_fd("ERROR\nMissing elements on map!\n", 2);
		exit(0);
	}
}

void	check_wrong_char_on_map(char *join, int x)
{
	char	c;

	c = join[x];
	if (c != 'C' && c != 'P' && c != 'E' && c != '0' && c != '1' && c != '\n')
	{
		ft_putstr_fd("ERROR\nFalse elements on map!\n", 2);
		exit(0);
	}
}

void	flagcheck_C_P_E_1_0(t_flag *flag, char *join)
{
	if (join[flag->x] == 'C')
		flag->flagC = 1;
	if (join[flag->x] == 'E')
	{
		if (flag->flagE == 1)
		{
			ft_putstr_fd("ERROR\nToo many exits on map!\n", 2);
			exit(0);
		}
		flag->flagE = 1;
	}
	if (join[flag->x] == 'P')
	{
		if (flag->flagP == 1)
		{
			ft_putstr_fd("ERROR\nToo many players on map!\n", 2);
			exit(0);
		}
		flag->flagP = 1;
	}
	if (join[flag->x] == '1')
		flag->flag1 = 1;
	if (join[flag->x] == '0')
		flag->flag0 = 1;
}

void	check_map_content(char *join)
{
	t_flag	flag;

	flag.flag0 = 0;
	flag.flagE = 0;
	flag.flagP = 0;
	flag.flagC = 0;
	flag.flag1 = 0;
	flag.x = 0;
	flag.strlen = ft_strlen(join);
	while (flag.x < flag.strlen)
	{
		check_wrong_char_on_map(join, flag.x);
		flagcheck_C_P_E_1_0(&flag, join);
		flag.x++;
	}
	check_the_flags(&flag);
}
