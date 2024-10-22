/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ceiling_floor_color.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:44:53 by lvichi            #+#    #+#             */
/*   Updated: 2024/10/19 17:44:53 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int get_ceiling_floor_color(char *buffer, t_map *map);
int parse_int(char *line);
int parse_color(char *line);

int get_ceiling_floor_color(char *buffer, t_map *map)
{
	char	line[1024];
	int		i = 0;
	size_t	line_pos = 0;
	int		valid_f = 0;
	int		valid_c = 0;

	while (buffer[i] != '\0')
    {
		if (buffer[i] != '\n' && line_pos < sizeof(line) - 1)
			line[line_pos++] = buffer[i];
		else
        {
			line[line_pos] = '\0';
			line_pos = 0;
			if (line[0] == 'F' && ++valid_f)
            {
                map->floor_color = parse_color(&line[2]);
                remove_first_line(line);
            }
            if (line[0] == 'C' && ++valid_c)
            {
                map->ceil_color = parse_color(&line[2]);
                remove_first_line(line);
            }
		}
		i++;
	}
	if (valid_f != 1 || valid_c != 1)
		return (1);
	return (0);
}

int parse_int(char *line)
{
	int res;

    res = 0;
	while((*line) >= '0' && (*line) <= '9')
	{
		res = res*10 + (*line - '0');
		line++;
	}
	return res;
}

int parse_color(char *line)
{
    int r;
    int g;
    int b;
    int rgb;

    r = parse_int(line);
	line++;
	g = parse_int(line);
	line++;
	b = parse_int(line);
    rgb = ((0xFF & 0xff) << 24) | ((r & 0xff) << 16) | ((g & 0xff) << 8) | (b & 0xff);
	return (rgb);
}
