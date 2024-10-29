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

int     parsing(char *file, t_map *map, t_usr *usr);
int 	get_data(t_parsing *buffer, t_map *map, t_usr *usr);
int		write_error(int type, t_parsing *parsing_data);


int parsing(char *file, t_map *map, t_usr *usr)
{
	t_parsing	*parsing_data;

	parsing_data = ft_calloc(1, sizeof(t_parsing));
	if (!parsing_data)
		return (write_error(7, parsing_data));
	parsing_data->fd = open(file, O_RDONLY);
	if (parsing_data->fd < 0)
		return (write_error(1, parsing_data));
	if (read(parsing_data->fd, parsing_data->buffer, MAP_SIZE_MAX) < 0)
		return (close(parsing_data->fd), write_error(2, parsing_data));
	close(parsing_data->fd);
    if (get_data(parsing_data, map, usr))
        return (1);
    printf("buffer: \n%s\n", parsing_data->buffer);      // DEBUG
	parsing_free(parsing_data);
    return (0);
}

int 	get_data(t_parsing *parsing_data, t_map *map, t_usr *usr)
{
	parsing_data->buffer_split = ft_split(parsing_data->buffer, '\n');
	if (!parsing_data->buffer_split)
		return (write_error(7, parsing_data));

//    // DEBUG
//	int i = 0;
//	while (parsing_data->buffer_split[i])
//	{
//		printf("buffer_split[%d]: %s\n", i, parsing_data->buffer_split[i]);
//		i++;
//	}
//	// DEBUG

	if (get_ceiling_floor_color(parsing_data, map))
		return (write_error(3, parsing_data));
	if (get_textures(parsing_data->buffer, map))
		return (write_error(4, parsing_data));
	if (get_map(parsing_data->buffer, map))
	    return (write_error(5, parsing_data));
    if (get_usr(parsing_data->buffer, usr))
        return (write_error(6, parsing_data));
    return (0);
}

int    write_error(int type, t_parsing *parsing_data)
{
	parsing_free(parsing_data);
	write(2, "Error\n", 6);
    if (type == 1)
        write(2, "File not found or incorrect "
                 "permissions to read.\n", 49);
    else if (type == 2)
        write(2, "Failed to read file.\n", 21);
    else if (type == 3)
        write(2, "Failed to get ceiling and floor color.\n", 39);
    else if (type == 4)
        write(2, "Failed to get textures.\n", 24);
    else if (type == 5)
        write(2, "Failed to get map.\n", 19);
    else if (type == 6)
        write(2, "Failed to get user position.\n", 29);
	else if (type == 7)
		write(2, "Failed to allocate memory.\n", 28);
	else if (type == 8)
		write(2, "Invalid number of arguments.\n", 29);
	return (1);
}
