/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_usr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 18:30:34 by lvichi            #+#    #+#             */
/*   Updated: 2024/10/19 18:30:34 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_usr(t_parsing *p_data);
void	get_user_info(t_parsing *p_data, int y, int x);
void	set_user_dir_pl(t_parsing *p_data, char c);

int	get_usr(t_parsing *p_data)
{
	char	**map_temp;
	int		y;
	int		x;

	map_temp = p_data->map_temp;
	y = -1;
	while (map_temp[++y])
	{
		x = -1;
		while (map_temp[y][++x])
		{
			if (ft_strchr(USER_POS, map_temp[y][x]))
			{
				if (p_data->usr->posx != 0)
					return (1);
				get_user_info(p_data, y, x);
			}
		}
	}
	if (p_data->usr->posx == 0)
		return (1);
	return (0);
}

void	get_user_info(t_parsing *p_data, int y, int x)
{
	int	i;

	p_data->usr->posx = x + 0.5;
	p_data->usr->posy = y + 0.5;
	i = -1;
	while (USER_POS[++i])
	{
		if (USER_POS[i] == p_data->map_temp[y][x])
			set_user_dir_pl(p_data, USER_POS[i]);
	}
	p_data->map_temp[y][x] = MOVE_AREA[0];
}

void	set_user_dir_pl(t_parsing *p_data, char c)
{
	if (c == 'N')
	{
		p_data->usr->diry = -1;
		p_data->usr->plx = PLY_CONST;
	}
	else if (c == 'S')
	{
		p_data->usr->diry = 1;
		p_data->usr->plx = -PLY_CONST;
	}
	else if (c == 'E')
	{
		p_data->usr->dirx = 1;
		p_data->usr->ply = PLY_CONST;
	}
	else if (c == 'W')
	{
		p_data->usr->dirx = -1;
		p_data->usr->ply = -PLY_CONST;
	}
}
