/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakataso <dakataso@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:53:01 by dakataso          #+#    #+#             */
/*   Updated: 2023/10/24 13:53:14 by dakataso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_start,
		fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_start,
		fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_start);
	free(fractal->mlx_start);
	exit(EXIT_SUCCESS);
}

static int	handle_space(t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "mandelbrot", 10))
		fractal->name = "julia";
	else if (!ft_strncmp(fractal->name, "julia", 5))
		fractal->name = "tricorn";
	else if (!ft_strncmp(fractal->name, "tricorn", 7))
		fractal->name = "burning_ship";
	else if (!ft_strncmp(fractal->name, "burning_ship", 12))
		fractal->name = "mandelbrot";
	fractal_render(fractal);
	return (0);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	if (keysym == XK_Left)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_equal || keysym == XK_KP_Add)
		fractal->iterations_definition += 10;
	else if (keysym == XK_minus || keysym == XK_KP_Subtract)
		fractal->iterations_definition -= 10;
	else if (keysym == XK_space)
		return (handle_space(fractal));
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == Button5)
		fractal->zoom *= 1.05;
	else if (button == Button4)
		fractal->zoom *= 0.95;
	else if (button == Button1)
	{
		fractal->julia_x = (scaling(x, -2, 2, WIDTH)
				* fractal->zoom) + fractal->shift_x;
		fractal->julia_y = (scaling(y, -2, 2, WIDTH)
				* fractal->zoom) + fractal->shift_y;
	}
	fractal_render(fractal);
	return (0);
}
