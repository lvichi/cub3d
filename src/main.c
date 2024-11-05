/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:50:20 by lvichi            #+#    #+#             */
/*   Updated: 2024/10/19 17:50:20 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int main(int argc, char **argv)
{
	t_map   map = {0};
	t_usr	usr = {0};
	t_mlx	*mlx = 0;

	if (argc != 2)
		return (1);

	mlx = mlx_init();
	if (!mlx)
		return (1);
	if (parsing(argv[1], &map, &usr, mlx))
	{
		mlx_destroy_display(mlx);
		free(mlx);
		return (1);
	}


	printf("Ceiling color: A=%d, R=%d, G=%d, B=%d\n",
		   (map.ceil_color >> 24) & 0xFF,
		   (map.ceil_color >> 16) & 0xFF,
		   (map.ceil_color >> 8) & 0xFF,
		   map.ceil_color & 0xFF);

	printf("Floor color: A=%d, R=%d, G=%d, B=%d\n",
		   (map.floor_color >> 24) & 0xFF,
		   (map.floor_color >> 16) & 0xFF,
		   (map.floor_color >> 8) & 0xFF,
		   map.floor_color & 0xFF);

	printf("Map size: %dx%d\n", map.width, map.height);

	void *win = mlx_new_window(mlx, 800, 600, "Cub3D");
	sleep(1);
	mlx_put_image_to_window(mlx, win, map.north.ptr, 200, 200);
	sleep(1);
	mlx_put_image_to_window(mlx, win, map.south.ptr, 200, 200);
	sleep(1);
	mlx_put_image_to_window(mlx, win, map.east.ptr, 200, 200);
	sleep(1);
	mlx_put_image_to_window(mlx, win, map.west.ptr, 200, 200);
	sleep(1);

	mlx_destroy_window(mlx, win);
	mlx_destroy_image(mlx, map.north.ptr);
	mlx_destroy_image(mlx, map.south.ptr);
	mlx_destroy_image(mlx, map.east.ptr);
	mlx_destroy_image(mlx, map.west.ptr);
	mlx_destroy_display(mlx);
	free(mlx);
	return (0);
}
