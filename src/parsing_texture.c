/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by lvichi            #+#    #+#             */
/*   Updated: 2024/10/22 18:48:36 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	get_textures(t_parsing *parsing_data);
int	load_texture(char *file, t_parsing *p_data, char *type);

int	get_textures(t_parsing *p_data)
{
	char	**buffer_split;

	buffer_split = p_data->buffer_split;
	while (*buffer_split)
	{
		if (ft_strncmp(*buffer_split, "NO ", 3) == 0)
			if (p_data->map->north.ptr
				|| load_texture(*buffer_split + 3, p_data, "north"))
				return (1);
		if (ft_strncmp(*buffer_split, "SO ", 3) == 0)
			if (p_data->map->south.ptr
				|| load_texture(*buffer_split + 3, p_data, "south"))
				return (1);
		if (ft_strncmp(*buffer_split, "WE ", 3) == 0)
			if (p_data->map->west.ptr
				|| load_texture(*buffer_split + 3, p_data, "west"))
				return (1);
		if (ft_strncmp(*buffer_split, "EA ", 3) == 0)
			if (p_data->map->east.ptr
				|| load_texture(*buffer_split + 3, p_data, "east"))
				return (1);
		buffer_split++;
	}
	return (0);
}

int	load_texture(char *file, t_parsing *p_data, char *type)
{
	void	*img_ptr;
	t_img	*img;
	int		width;
	int		height;

	img_ptr = mlx_xpm_file_to_image(p_data->mlx, file, &width, &height);
	if (!img_ptr)
		return (1);
	if (ft_strncmp(type, "north", 5) == 0)
		img = &p_data->map->north;
	else if (ft_strncmp(type, "south", 5) == 0)
		img = &p_data->map->south;
	else if (ft_strncmp(type, "east", 4) == 0)
		img = &p_data->map->east;
	else
		img = &p_data->map->west;
	img->ptr = img_ptr;
	img->width = width;
	img->height = height;
	return (0);
}
