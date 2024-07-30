/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:54:16 by nfujisak          #+#    #+#             */
/*   Updated: 2024/07/30 14:02:30 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strjoin(char *stash, char *buffer)
{
	char	*save;
	int		i;
	int		j;

	if (!stash && !buffer)
		return (NULL);
	if (!stash)
		stash = ft_calloc(1, sizeof(char));
	if (!stash)
		return (free(buffer), NULL);
	save = ft_calloc(ft_strlen(stash) + ft_strlen(buffer) + 1, sizeof(char));
	if (!save)
		return (free(stash), free(buffer), NULL);
	i = -1;
	while (stash[++i])
		save[i] = stash[i];
	j = -1;
	while (buffer[++j])
		save[i++] = buffer[j];
	save[i] = '\0';
	return (free(stash), free(buffer), save);
}

char	*check_newline(char *stash)
{
	int	i;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (&stash[i]);
		i++;
	}
	return (NULL);
}

// void	remove_newline(char *line)
// {
// 	int	len;

// 	len = ft_strlen(line);
// 	if (len > 0 && line[len - 1] == '\n')
// 		line[len - 1] = '\0';
// }
