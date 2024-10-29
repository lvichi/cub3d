/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvichi <lvichi@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 01:00:00 by lvichi            #+#    #+#             */
/*   Updated: 2024/10/22 20:03:08 by lvichi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;

	size = nmemb * size;
	ret = malloc(size);
	if (!ret)
		return (NULL);
	while (size)
		((char *)ret)[--size] = 0;
	return (ret);
}

int ft_strlen(char *s)
{
    int length;

    length = 0;
    while (*s != '\0')
    {
        s++;
        length++;
    }
    return length;
}

char    *ft_strchr(char *s, int c)
{
    while (*s != '\0')
    {
        if (*s == c)
            return s;
        s++;
    }
    return NULL;
}

void ft_memmove(char *dest, const void *src, int n)
{
    char    *dest_ptr;
    char    *src_ptr;

    dest_ptr = (char*)dest;
    src_ptr = (char*)src;
    if (dest_ptr <= src_ptr || dest_ptr >= (src_ptr + n))
        while (n--)
            *dest_ptr++ = *src_ptr++;
    else
    {
        dest_ptr += n;
        src_ptr += n;
        while (n--)
            *--dest_ptr = *--src_ptr;
    }
}

void    *ft_memset(void *str, int c, size_t n)
{
    unsigned char   *ptr = str;

    while(n-- > 0)
        *ptr++ = (unsigned char)c;
    return str;
}

void remove_first_line(char *buffer)
{
    char    *line_end;
    int     remainder_length;

    line_end = ft_strchr(buffer, '\n');
    if (line_end != NULL)
    {
        remainder_length = ft_strlen(line_end + 1);
        ft_memmove(buffer, line_end + 1, remainder_length + 1);
    }
    else
        buffer[0] = '\0';
}

void	parsing_free(t_parsing *parsing_data)
{
	int i;

	i = 0;
	if (!parsing_data)
		return ;
	while (parsing_data->buffer_split && parsing_data->buffer_split[i])
	{
		free(parsing_data->buffer_split[i]);
		i++;
	}
	free(parsing_data->buffer_split);
	free(parsing_data);
}

char	**ft_split(char *str, char c)
{
	int		i;
	int		j;
	int		k;
	char 	**str_split;

	i = -1;
	j = -1;
	k = 0;
	str_split = ft_calloc(ft_strlen(str) + 1, sizeof(char *));
	while (str_split && str[++i])
	{
		if (str[i] == c || str[i + 1] == '\0')
		{
			str_split[++j] = ft_calloc(i - k + 2, sizeof(char));
			if (!str_split[j])
				return (ft_array_free(str_split), NULL);
			if (str[i + 1] == '\0' && str[i] != c)
				ft_memmove(str_split[j], str + k, i - k + 1);
			else
				ft_memmove(str_split[j], str + k, i - k);
			k = i + 1;
		}
	}
	return (str_split);
}

void	ft_array_free(char **array)
{
	int i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
