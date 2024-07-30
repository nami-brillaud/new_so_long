/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:52:43 by nfujisak          #+#    #+#             */
/*   Updated: 2024/07/30 14:02:40 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* get_next_line.c */
char	*handle_remains(char *stash, char *line);
char	*fetch_line(char *stash);
char	*read_file(int fd, char *stash);
char	*get_next_line(int fd);

/* get_next_line_utils.c */
char	*gnl_strjoin(char *stash, char *buffer);
char	*check_newline(char *stash);

#endif