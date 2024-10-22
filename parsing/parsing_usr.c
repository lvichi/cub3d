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

int	get_usr(char *buffer, t_usr *usr)
{
    (void)buffer;
    (void)usr;
	return (0);
}

//#include <string.h>
//
//int	get_usr(char *buffer, t_usr *usr)
//{
//	int	i;
//	int	j;
//	int	start;
//
//	start = 0;
//	i = 0;
//	j = 0;
//	while (buffer[i])
//	{
//		// If the line starts with a number or space, start tracking position
//		if (!start && ((buffer[i] >= '0' && buffer[i] <= '9') || buffer[i] == ' '))
//			start = 1;
//		if (start && (buffer[i] == 'N' || buffer[i] == 'S' || buffer[i] == 'E' || buffer[i] == 'W'))
//		{
//			usr->posx = (float)j;
//			usr->posy = (float)i;
//			if (buffer[i] == 'N') { usr->dirx = 0; usr->diry = -1; }
//			else if (buffer[i] == 'S') { usr->dirx = 0; usr->diry = 1; }
//			else if (buffer[i] == 'E') { usr->dirx = 1; usr->diry = 0; }
//			else if (buffer[i] == 'W') { usr->dirx = -1; usr->diry = 0; }
//
//			return (0); // Position found
//		}
//		// line starts with a number or space, so track where we are in x and y
//		if (start && (buffer[i] != '\n'))
//			j += 1;
//		else
//			j = 0;
//		i++;
//	}
//	// Position not found
//	return (-1);
//}