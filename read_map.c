/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:42:55 by nfujisak          #+#    #+#             */
/*   Updated: 2024/07/31 19:23:42 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// To print char **s
#include <stdio.h>

void	print_map(char **map)
{
	if (map == NULL)
	{
		printf("Map is NULL\n");
		return ;
	}
	for (int i = 0; map[i] == NULL; i++)
	{
		printf("%s\n", map[i]);
		printf("what\n");
	}
}

int	read_map(char *file, t_game *game)
{
	int		fd;
	char	*block;
	char	*line;
	char	*save;

	fd = open(file, O_RDONLY);
	block = ft_strdup("");
	line = get_next_line(fd);
	if (fd == -1 || ber_check(file) || ft_strlen(line) < 5) // should this be here?
		return (NO);
	while (line)
	{
		save = ft_strjoin(block, line);
		free(block);
		free(line);
		block = save;
		line = get_next_line(fd);
	}
	close(fd);
	ft_printf("blok \n%s\n", block);
	game->map.map = ft_split(block, '\n');
	game->map.mapcopy = ft_split(block, '\n');
	free(save);
	free(line);
	return (OK);
}

// At this point, both map.map and mapcopy are leaking,
// 	as we haven't finished using them yet.
// // Don't forget to free them after the flood fill or after making graphics.
