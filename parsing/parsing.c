/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:33:02 by lvichi            #+#    #+#             */
/*   Updated: 2024/10/18 16:33:02 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int parsing(char *file, t_map *map, t_usr *usr);
int get_data(char *buffer, t_map *map, t_usr *usr);
int get_textures(char *buffer, t_map *map);
int get_map(char *buffer, t_map *map);

int parsing(char *file, t_map *map, t_usr *usr)
{
	int fd;
	char buffer[map_size_max];

	fd = open(file, O_RDONLY);
	if (fd < 0) {
		write(2, "Error\nFile not found or incorrect "
				 "permissions to read.\n", 55);
		return (1);
	}
	if (read(fd, buffer, map_size_max) < 0)
	{
		close(fd);
		write(2, "Error\nFailed to read file.\n", 27);
		return (1);
	}
	close(fd);
    if (get_data(buffer, map, usr))
        return (1);
    return (0);
}

int get_data(char *buffer, t_map *map, t_usr *usr)
{
	if (get_ceiling_floor_color(buffer, map))
	{
		write(2, "Error\nFailed to get ceiling and floor color.\n", 43);
		return (1);
	}
	if (get_textures(buffer, map))
	{
		write(2, "Error\nFailed to get textures.\n", 31);
		return (1);
	}
	if (get_usr(buffer, usr))
	{
		write(2, "Error\nFailed to get user position.\n", 27);
		return (1);
	}
	if (get_map(buffer, map))
	{
		write(2, "Error\nFailed to get map.\n", 26);
		return (1);
	}
	return (0);
}

int get_textures(char *buffer, t_map *map)
{
	// get north texture
	// get south texture
	// get east texture
	// get west texture
	(void)buffer;
	(void)map;
	return (0);
}

int get_map(char *buffer, t_map *map)
{
	// get map
	(void)buffer;
	(void)map;
	return (0);
}
