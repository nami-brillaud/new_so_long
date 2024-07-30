/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   samplefile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:36:57 by nfujisak          #+#    #+#             */
/*   Updated: 2024/07/04 18:33:39 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mine_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// void	draw_line(t_data *data, int xstart, int xend, int ystart, int yend, int color)
// {
	
// }

// /* WHITE CIRCLE */
// void	draw_circle(t_data *data, int center_x, int center_y, int radius)
// {
// 	int x = radius;
// 	int y = 0;
// 	int err = 0; //what is this?

// 	while (x >= y) //while the radius is larger than 0
// 	{
// 		mine_pixel_put(data, center_x + x, center_y + y, 0xFFFFFF);
// 		mine_pixel_put(data, center_x + y, center_y + x, 0xFFFFFF);
// 		mine_pixel_put(data, center_x - y, center_y + x, 0xFFFFFF);
//     	mine_pixel_put(data, center_x - x, center_y + y, 0xFFFFFF);
//     	mine_pixel_put(data, center_x - x, center_y - y, 0xFFFFFF);
//     	mine_pixel_put(data, center_x - y, center_y - x, 0xFFFFFF);
//    		mine_pixel_put(data, center_x + y, center_y - x, 0xFFFFFF);
//     	mine_pixel_put(data, center_x + x, center_y - y, 0xFFFFFF);

// 		 if (err <= 0)
//     	{
//         	y += 1;
//         	err += 2*y + 1;
//     	}

//     	if (err > 0)
//    		{
//         	x -= 1;
//        		err -= 2*x + 1;
//     	}	
// 	}
// }

// int main(void)
// {
// 	void	*mlx;
// 	void	*mlx_window;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_window = mlx_new_window(mlx, 700, 680, "This is a window");
// 	img.img = mlx_new_image(mlx, 700, 680);
// 	img.addr= mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// 	draw_circle(&img, 350, 350, 50);
// 	mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
// 	mlx_loop(mlx);
// 	return (0);
// }

/* BLUE RECTANGLE */
int main(void)
{
	void	*mlx;
	void	*mlx_window;
	t_data	img;

	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 700, 680, "This is a window");
	img.img = mlx_new_image(mlx, 700, 680);
	img.addr= mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	int x = 0;
	int y = 0;
	while (x < 500)
	{	
		y = 0;
		while (y < 500)
		{
			mine_pixel_put(&img, x, y, 0xFFA500);
			y++;
		}
		x++;
		
	}
	mlx_put_image_to_window(mlx, mlx_window, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}