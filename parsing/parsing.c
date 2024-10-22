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
int     get_data(char *buffer, t_map *map, t_usr *usr);
void    write_error(int type);
void    *ft_memset(void *str, int c, size_t n);


int parsing(char *file, t_map *map, t_usr *usr)
{
	int fd;
	char buffer[MAP_SIZE_MAX];

    ft_memset(buffer, 0, MAP_SIZE_MAX);
    fd = open(file, O_RDONLY);
	if (fd < 0)
		return (write_error(1), 1);
	if (read(fd, buffer, MAP_SIZE_MAX) < 0)
		return (close(fd), write_error(2), 1);
	close(fd);
    if (get_data(buffer, map, usr))
        return (1);
    // DEBUG
    printf("buffer: \n%s\n", buffer);
    return (0);
}

int get_data(char *buffer, t_map *map, t_usr *usr)
{
	if (get_ceiling_floor_color(buffer, map))
		return (write_error(3), 1);
	if (get_textures(buffer, map))
		return (write_error(4), 1);
	if (get_map(buffer, map))
	    return (write_error(5), 1);
    if (get_usr(buffer, usr))
        return (write_error(6), 1);
    return (0);
}

void    write_error(int type)
{
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
}
