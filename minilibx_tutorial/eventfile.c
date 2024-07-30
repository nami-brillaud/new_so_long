/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eventfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:59:59 by nfujisak          #+#    #+#             */
/*   Updated: 2024/07/04 19:44:48 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mine_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

int	end(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int print_hello(int keycode)
{
	if (keycode == W) //no error handling for now
		ft_printf("Hello\n");
	return (0);
}

int main(void)
{
	t_vars vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 700, 680, "This is a window");
	mlx_key_hook(vars.win, print_hello, NULL);
	mlx_hook(vars.win, 2, 0, end, &vars);
	mlx_loop(vars.mlx);
}
