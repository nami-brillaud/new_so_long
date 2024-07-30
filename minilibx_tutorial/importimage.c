/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   importimage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:26:16 by nfujisak          #+#    #+#             */
/*   Updated: 2024/07/08 16:06:16 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
	void	*mlx;
	void	*mlx_window;
	void	*img;
	char	*relative_path = "textures/test.xpm";
	int		img_width;
	int		img_height;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 700, 680, "This is a window");
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	
	int num_x_repeats = (700 / img_width) + 1;
	int num_y_repeats = (680 / img_height) + 1;

	int y = 0;
	while (y < num_y_repeats)
	{
		int x = 0;
		while(x < num_x_repeats)
		{
        	int tex_x = x * img_width;
        	int tex_y = y * img_height;
        	mlx_put_image_to_window(mlx, mlx_window, img, tex_x, tex_y);
			x++;
		}
		y++;
    }
	mlx_loop(mlx);
	return (0);
}

