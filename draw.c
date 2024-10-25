/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:30:51 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/10/25 12:04:40 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(int x, int y, int color);
void	draw_vertical_line(int x, int ystart, int yend, int color);

void	put_pixel(int x, int y, int color)
{
	t_img	*img;
	char	*dst;

	img = &g()->frame;
	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
	{
		dst = img->data + (y * img->sl + x * (img->bpp / 8));
		*(int *)dst = color;
	}
}

void	draw_vertical_line(int x, int ystart, int yend, int color)
{
	t_img	*win;

	win = &g()->frame;
	if (ystart > yend)
	{
		ystart ^= yend;
		yend ^= ystart;
		ystart ^= yend;
	}
	if (ystart < 0)
		ystart = 0;
	else if (ystart >= win->height)
		ystart = win->height;
	if (yend < 0)
		yend = 0;
	else if (yend >= win->height)
		yend = win->height;
	while (ystart < yend)
		put_pixel(x, ystart++, color);
}
