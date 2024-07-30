/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:42:55 by nfujisak          #+#    #+#             */
/*   Updated: 2024/07/30 14:02:06 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// To print char **s
// #include <stdio.h>
// void	print_map(char **map)
// {
// 	if (map == NULL)
// 	{
// 		printf("Map is NULL\n");
// 		return ;
// 	}
// 	for (int i = 0; map[i] != NULL; i++)
// 	{
// 		printf("%s\n", map[i]);
// 	}
// }

void	read_map(char *file, t_game *game)// probs change your file to argv later on
{
	int fd;
	char *block;
	char *line;
	char *save;

	fd = open(file, O_RDONLY);
	block = ft_strdup("");
	line = get_next_line(fd);
	if (fd == -1 || ber_check(file)) // should this be here?
		ft_printf("Error: invalid file!\n");
	while (line)
	{
		save = ft_strjoin(block, line);
		free(block);
		free(line);
		block = save;
		line = get_next_line(fd);
	}
	free(save);
	free(line);
	close(fd);
	game->map.map = ft_split(block, '\n');
	game->map.mapcopy = ft_split(block, '\n');
}

// At this point, both map.map and mapcopy are leaking, as we haven't finished using them yet.
// Don't forget to free them after the flood fill or after making graphics.
