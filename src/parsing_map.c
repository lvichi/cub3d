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

#include "parsing.h"

int	get_map(t_parsing *p_data);
int	get_map_dimensions(t_parsing *p_data);

int	get_map(t_parsing *p_data)
{
	if (get_map_dimensions(p_data))
		return (1);
	return (0);
	//debug
	printf("map_end: %d\n", p_data->map_end);
	printf("map_start: %d\n\n", p_data->map_start);
}

int	get_map_dimensions(t_parsing *p_data)
{
	int		num_lines;

	num_lines = 0;
	while (p_data->buffer_split[num_lines] != NULL)
		num_lines++;
	p_data->map_end = num_lines - 1;
	while (p_data->map_end >= 0
		&& ft_strlen(p_data->buffer_split[p_data->map_end]) == 0)
		p_data->map_end--;
	p_data->map->width = ft_strlen(p_data->buffer_split[p_data->map_end]);
	p_data->map_start = p_data->map_end;
	while (p_data->map_start >= 0
		&& ft_strlen(p_data->buffer_split[p_data->map_start]) > 0)
	{
		if (ft_strlen(p_data->buffer_split[p_data->map_start]) > p_data->map->width)
			p_data->map->width = ft_strlen(p_data->buffer_split[p_data->map_start]);
		p_data->map_start--;
	}
	p_data->map_start++;
	p_data->map->height = p_data->map_end - p_data->map_start + 1;
	return (0);
}
