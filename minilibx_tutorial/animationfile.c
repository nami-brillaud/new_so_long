/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animationfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 20:14:36 by nfujisak          #+#    #+#             */
/*   Updated: 2024/07/04 20:41:52 by nfujisak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mine_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

//Where is data.win being created ?? 


int render_next_frame(void *param)
{
    t_data *data = (t_data *)param;
    int x, y;
    int color;

    // Clear the window
    mlx_clear_window(data->mlx, data->win);

    // Calculate color transition from blue to red
    int r = 0;
    int g = 0;
    int b = 255 - data->animation_step; // Start with blue (0, 0, 255) and decrease blue component

    // Ensure color bounds
    if (b < 0) b = 0;
    if (b > 255) b = 255;

    color = (r << 16) | (g << 8) | b; // Create color in RGB format

    // Draw the square
    for (x = 300; x < 300 + data->square_size; x++) {
        for (y = 200; y < 200 + data->square_size; y++) {
            mine_pixel_put(data, x, y, color);
        }
    }

    // Update animation step
    data->animation_step++;
    if (data->animation_step > 255) {
        data->animation_step = 0; // Reset animation step if it exceeds 255
    }

    // Put the image to the window
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);

    return 0;
}

void initialize(t_data *data)
{
    data->mlx = mlx_init();

    data->win = mlx_new_window(data->mlx, 800, 600, "Color Changing Square");

    data->img = mlx_new_image(data->mlx, 800, 600);

    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);

    data->square_size = 200; // Size of the square
    data->animation_step = 0; // Animation step counter
}

int main(void)
{
    t_data data;

    // Initialize MiniLibX and setup
    initialize(&data);

    // Set the loop hook for rendering
    mlx_loop_hook(data.mlx, render_next_frame, &data);

    // Start the MiniLibX event loop
    mlx_loop(data.mlx);

    return 0;
}
