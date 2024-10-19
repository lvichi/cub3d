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
	t_map   map;
	t_usr	usr;

	if (argc == 2)
		if (parsing(argv[1], &map, &usr))
			return (1);
	if (argc != 2)
		write(2, "Error\nInvalid number of arguments.\n", 36);

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

	return (0);
}
