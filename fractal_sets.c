/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_sets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakataso <dakataso@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 12:11:20 by dakataso          #+#    #+#             */
/*   Updated: 2023/11/11 12:11:23 by dakataso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot_set(t_fractal *fractal, double x, double y)
{
	t_complex	z;
	t_complex	c;
	int			n;

	z.x = 0;
	z.y = 0;
	c.x = scaling(x, -2, 2, WIDTH) * fractal->zoom + fractal->shift_x;
	c.y = scaling(y, -2, 2, HEIGHT) * fractal->zoom + fractal->shift_y;
	n = 0;
	while (n < fractal->iterations_definition)
	{
		z = sum_complex(square_complex(z), c);
		if (z.x * z.x + z.y * z.y > fractal->escape_value)
			break ;
		n++;
	}
	return (n);
}

int	julia_set(t_fractal *fractal, double x, double y)
{
	t_complex	z;
	t_complex	c;
	int			n;

	z.x = scaling(x, -2, 2, WIDTH) * fractal->zoom + fractal->shift_x;
	z.y = scaling(y, -2, 2, HEIGHT) * fractal->zoom + fractal->shift_y;
	c.x = fractal->julia_x;
	c.y = fractal->julia_y;
	n = 0;
	while (n < fractal->iterations_definition)
	{
		z = sum_complex(square_complex(z), c);
		if (z.x * z.x + z.y * z.y > fractal->escape_value)
			break ;
		n++;
	}
	return (n);
}

int	burning_ship(t_fractal *fractal, double x, double y)
{
	t_complex	z;
	t_complex	c;
	t_complex	tmp;
	int			n;

	z.x = 0;
	z.y = 0;
	c.x = scaling(x, -2, 2, WIDTH) * fractal->zoom + fractal->shift_x;
	c.y = scaling(y, -2, 2, HEIGHT) * fractal->zoom + fractal->shift_y;
	n = 0; 
	while (n < fractal->iterations_definition)
	{
		tmp = z;
		z = sum_complex(square_complex(z), c);
		z.x = fabs(z.x);
		z.y = fabs(z.y);
		if ((z.x * z.x + z.y * z.y) > fractal->escape_value)
			break ;
		n++;
	}
	return (n);
}

int	tricorn_set(t_fractal *fractal, double x, double y)
{
	t_complex	z;
	t_complex	c;
	int			n;
	double		tmp;

	z.x = 0;
	z.y = 0;
	c.x = scaling(x, -2, 2, WIDTH) * fractal->zoom + fractal->shift_x;
	c.y = scaling(y, -2, 2, HEIGHT) * fractal->zoom + fractal->shift_y;
	n = 0;
	while (n < fractal->iterations_definition)
	{
		if (z.x * z.x + z.y * z.y > fractal->escape_value)
			break ;
		tmp = -2 * z.x * z.y + c.y;
		z.x = z.x * z.x - z.y * z.y + c.x;
		z.y = tmp;
		n++;
	}
	return (n);
}
