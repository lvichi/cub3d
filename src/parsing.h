/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:47:46 by lvichi            #+#    #+#             */
/*   Updated: 2024/10/19 17:47:46 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include <stdio.h> 						// printf      ## DEBUG DELETE ##
# include <fcntl.h> 						// open
# include <unistd.h> 						// read, close
# include <stdlib.h> 						// malloc, free
# include "../minilibx-linux/mlx.h"        // mlx_*

# define MAP_SIZE_MAX 1048576

typedef struct s_img	t_img;
struct s_img
{
	void	*ptr;
	int		width;
	int		height;
	char	*data;
	int		bpp;
	int		sl;
	int		endian;
};

typedef struct s_map	t_map;
struct s_map
{
	int		*data;
	int		width;
	int		height;
	int		ceil_color;
	int		floor_color;
	t_img	north;
	t_img	south;
	t_img	east;
	t_img	west;
};

typedef struct s_usr	t_usr;
struct s_usr
{
	float	posx;
	float	posy;
	float	dirx;
	float	diry;
	float	plx;
	float	ply;
};

typedef struct s_mlx	t_mlx;
struct s_mlx
{
	void	*ptr;
	void	*win;
	int		width;
	int		height;
	char	*title;
};

typedef struct s_parsing
{
	t_map	*map;
	t_usr	*usr;
	t_mlx	*mlx;
	int		fd;
	char	buffer[MAP_SIZE_MAX];
	char	**buffer_split;
	int		ceiling_color;
	int		floor_color;
	char	**map_temp;
	int		map_start;
	int		map_end;
}	t_parsing;

// parsing.c
int		parsing(char *file, t_map *map, t_usr *usr, t_mlx *mlx);
int		get_data(t_parsing *parsing_data);
int		write_error(int type, t_parsing *parsing_data);
void	parsing_free(t_parsing *parsing_data, int images);

// parsing_ceiling_floor_color.c
int		get_ceiling_floor_color(t_parsing *parsing_data);
int		parse_int(char *line);
int		parse_color(char *line);

// parsing_texture.c
int		get_textures(t_parsing *parsing_data);
int		load_texture(char *file, t_parsing *p_data, char *type);
int		check_line(char *buffer_split, t_parsing *p_data);

// parsing_map.c
int		get_map(t_parsing *p_data);

// parsing_usr.c
int		get_usr(t_parsing *parsing_data);

// parsing_utils.c
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strlen(char *s);
char	*ft_strchr(char *s, int c);
void	ft_memmove(char *dest, const void *src, int n);
void	*ft_memset(void *str, int c, size_t n);

// parsing_utils2.c
void	remove_first_line(char *buffer);
char	**ft_split(char *str, char c);
void	ft_array_free(char **array);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strstr(char const *s1, char const *s2);

#endif
