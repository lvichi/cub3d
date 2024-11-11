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

int		parsing(char *file, t_map *map, t_usr *usr, t_mlx *mlx);
int		get_data(t_parsing *parsing_data);
int		write_error(int type, t_parsing *parsing_data);
void	parsing_free(t_parsing *parsing_data, int images);
int		convert_map(t_parsing *p_data);

int	parsing(char *file, t_map *map, t_usr *usr, t_mlx *mlx)
{
	t_parsing	*parsing_data;

	parsing_data = ft_calloc(1, sizeof(t_parsing));
	if (!parsing_data)
		return (write_error(7, parsing_data));
	parsing_data->map = map;
	parsing_data->usr = usr;
	parsing_data->mlx = mlx;
	parsing_data->fd = open(file, O_RDONLY);
	if (parsing_data->fd < 0)
		return (write_error(1, parsing_data));
	if (read(parsing_data->fd, parsing_data->buffer, MAP_SIZE_MAX) < 0)
		return (close(parsing_data->fd), write_error(2, parsing_data));
	close(parsing_data->fd);
	if (get_data(parsing_data))
		return (1);
	printf("buffer: \n%s\n", parsing_data->buffer);
	parsing_free(parsing_data, 0);
	return (0);
}

int	get_data(t_parsing *parsing_data)
{
	parsing_data->buffer_split = ft_split(parsing_data->buffer, '\n');
	if (!parsing_data->buffer_split)
		return (write_error(7, parsing_data));
	if (get_ceiling_floor_color(parsing_data))
		return (write_error(3, parsing_data));
	if (get_textures(parsing_data))
		return (write_error(4, parsing_data));
	if (get_map(parsing_data))
		return (write_error(5, parsing_data));
	if (get_usr(parsing_data))
		return (write_error(6, parsing_data));
	if (convert_map(parsing_data))
		return (write_error(7, parsing_data));
	return (0);
}

int	write_error(int type, t_parsing *parsing_data)
{
	parsing_free(parsing_data, 1);
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
		write(2, "Failed to allocate memory.\n", 27);
	return (1);
}

void	parsing_free(t_parsing *p_data, int images)
{
	int	i;

	i = -1;
	if (!p_data)
		return ;
	while (p_data->buffer_split && p_data->buffer_split[++i])
		free(p_data->buffer_split[i]);
	free(p_data->buffer_split);
	i = -1;
	while (p_data->map_temp && p_data->map_temp[++i])
		free(p_data->map_temp[i]);
	free(p_data->map_temp);
	if (p_data->map->north.ptr && images)
		mlx_destroy_image(p_data->mlx, p_data->map->north.ptr);
	if (p_data->map->south.ptr && images)
		mlx_destroy_image(p_data->mlx, p_data->map->south.ptr);
	if (p_data->map->east.ptr && images)
		mlx_destroy_image(p_data->mlx, p_data->map->east.ptr);
	if (p_data->map->west.ptr && images)
		mlx_destroy_image(p_data->mlx, p_data->map->west.ptr);
	if (p_data->mlx && images)
		mlx_destroy_display(p_data->mlx);
	if (p_data->mlx && images)
		free(p_data->mlx);
	free(p_data);
}

int	convert_map(t_parsing *p_data)
{
	int	i;
	int	j;
	int	length;

	length = p_data->map->width * p_data->map->height;
	p_data->map->data = (int *)ft_calloc(length, sizeof(int));
	if (!p_data->map->data)
		return (1);
	i = -1;
	while (p_data->map_temp && p_data->map_temp[++i])
	{
		j = -1;
		while (p_data->map_temp[i][++j])
			if (p_data->map_temp[i][j] == WALL[0])
				p_data->map->data[i * p_data->map->width + j] = 1;
	}
	return (0);
}
