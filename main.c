/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakataso <dakataso@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:10:45 by dakataso          #+#    #+#             */
/*   Updated: 2023/10/03 11:11:18 by dakataso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	julia_set_params(t_fractal *fractal, int ac, char **av)
{
	if (ac == 4)
	{
		fractal->julia_x = atodbl(av[2]);
		fractal->julia_y = atodbl(av[3]);
	}
	else
	{
		fractal->julia_x = -0.7;
		fractal->julia_y = 0.27015;
	}
}

static void	exit_error(void)
{
	ft_putstr(ERROR_MESSAGE);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (ac >= 2 && av[1] != NULL)
	{
		if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
			|| (!ft_strncmp(av[1], "julia", 5))
			|| (!ft_strncmp(av[1], "burning_ship", 12))
			|| (!ft_strncmp(av[1], "tricorn", 7)))
		{
			fractal.name = av[1];
			julia_set_params(&fractal, ac, av);
			fractal_init(&fractal);
			fractal_render(&fractal);
			mlx_loop(fractal.mlx_start);
		}
		else if (ac == 2 && !ft_strncmp(av[1], "Info", 4))
			ft_putstr(INFORMATION);
		else
			exit_error();
	}
	else
		exit_error();
}
