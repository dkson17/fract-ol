/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakataso <dakataso@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:55:22 by dakataso          #+#    #+#             */
/*   Updated: 2023/10/11 10:55:26 by dakataso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*Calculate the offset in bytes to the target pixel in the image buffer. 
Set the color of the pixel at the calculated offset*/

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	handle_pix_bonus(int x, int y, t_fractal *fractal)
{
	int	b;
	int	tr;
	int	color;

	color = 0;
	if (fractal->name && !ft_strncmp(fractal->name, "burning_ship", 12))
	{
		b = burning_ship(fractal, x, y);
		color = scaling(b, PASTEL_PINK, BLACK, fractal->iterations_definition);
	}
	else if (fractal->name && !ft_strncmp(fractal->name, "tricorn", 7))
	{
		tr = tricorn_set(fractal, x, y);
		color = scaling(tr, LIME_SHOCK, PASTEL_PINK, \
			fractal->iterations_definition);
	}
	my_pixel_put(x, y, &fractal->img, color);
}

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	int	m;
	int	j;
	int	color;

	color = 0;
	if (fractal->name && !ft_strncmp(fractal->name, "mandelbrot", 10))
	{
		m = mandelbrot_set(fractal, x, y);
		color = scaling(m, RED, BLACK, fractal->iterations_definition);
		my_pixel_put(x, y, &fractal->img, color);
	}
	else if (fractal->name && !ft_strncmp(fractal->name, "julia", 5))
	{
		j = julia_set(fractal, x, y);
		color = scaling(j, BLUE, HOT_PINK, fractal->iterations_definition);
		my_pixel_put(x, y, &fractal->img, color);
	}
	else
		handle_pix_bonus(x, y, fractal);
}

void	fractal_render(t_fractal *fractal)
{
	int		x;
	int		y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handle_pixel(x, y, fractal);
	}
	mlx_put_image_to_window(fractal->mlx_start, fractal->mlx_window,
		fractal->img.img_ptr, 0, 0);
}
