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
# include <stdio.h> // printf         ## DEBUG DELETE ##
# include <fcntl.h> // open
# include <unistd.h> // read, close
# include <stdlib.h> // malloc, free
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
	int	*data;
	int	width;
	int	height;
	int	ceil_color;
	int	floor_color;
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

typedef struct s_parsing
{
	int		fd;
	char	buffer[MAP_SIZE_MAX];
	char	**buffer_split;
	int 	ceiling_color;
	int 	floor_color;
} t_parsing;

// parsing.c
int     parsing(char *file, t_map *map, t_usr *usr);
int 	get_data(t_parsing *buffer, t_map *map, t_usr *usr);
int		write_error(int type, t_parsing *parsing_data);
void    *ft_memset(void *str, int c, size_t n);

// parsing_ceiling_floor_color.c
int 	get_ceiling_floor_color(t_parsing *parsing_data, t_map *map);
int     parse_int(char *line);
int     parse_color(char *line);

// parsing_texture.c
int     get_textures(char *buffer, t_map *map);

// parsing_map.c
int     get_map(char *buffer, t_map *map);

// parsing_usr.c
int     get_usr(char *buffer, t_usr *usr);

// parsing_utils.c
void	*ft_calloc(size_t nmemb, size_t size);
int     ft_strlen(char *s);
char    *ft_strchr(char *s, int c);
void    ft_memmove(char *dest, const void *src, int n);
void    *ft_memset(void *str, int c, size_t n);
void    remove_first_line(char *buffer);
void	parsing_free(t_parsing *parsing_data);
char	**ft_split(char *str, char c);
void	ft_array_free(char **array);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
