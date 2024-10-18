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

#include "cub3d.h"

int parsing(char *file)
{
    int fd;
    char *line;

    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        write(2, "Error\nFile not found or incorrect permissions to read.\n", 21);
        return (0);
    }
    while (get_next_line(fd, &line))
    {
        printf("%s\n", line);
        free(line);
    }
    free(line);
    close(fd);
    return (1);
}


int main(int argc, char **argv)
{
    if (argc == 2)
    {
        if (!parsing(argv[1]))
            return (1);
    }
    else
        write(2, "Error\nInvalid number of arguments.\n", 36);
    return (0);
}
