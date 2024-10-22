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

int     ft_strlen(char *s);
char    *ft_strchr(char *s, int c);
void    ft_memmove(char *dest, const void *src, int n);
void    *ft_memset(void *str, int c, size_t n);
void    remove_first_line(char *buffer);

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
