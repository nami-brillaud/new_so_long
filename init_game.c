/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:44:12 by nfujisak          #+#    #+#             */
/*   Updated: 2024/07/15 16:44:29 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Function to initialize map (put it in another file afterwards)
void	init_game(t_game *game)
{
	game->map.rcdiff = 0;
	game->map.p = 0;
	game->map.c = 0;
	game->map.e = 0;
	game->map.x = 0;
}