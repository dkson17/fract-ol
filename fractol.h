/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dakataso <dakataso@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:20:44 by dakataso          #+#    #+#             */
/*   Updated: 2023/09/27 13:25:37 by dakataso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <mlx.h>
# include <math.h>

# define WIDTH 600
# define HEIGHT 600

# define ITERATIONS 2500

# define ERROR_MESSAGE \
"Please enter \n\t\"./fractol mandelbrot\" or \n\t\"./fractol \
julia <value_1> <value_2>\"\n"

# define BLACK       0x000000
# define WHITE       0xFFFFFF
# define RED         0xFF0000
# define GREEN       0x00FF00
# define BLUE        0x0000FF
# define MAGENTA_BURST   0xFF00FF
# define LIME_SHOCK      0xCCFF00
# define NEON_ORANGE     0xFF6600
# define PSYCHEDELIC_PURPLE 0x660066
# define AQUA_DREAM      0x33CCCC
# define HOT_PINK        0xFF66B2
# define ELECTRIC_BLUE   0x0066FF
# define LAVA_RED        0xFF3300
# define HONEY		 0XFFD700

typedef struct s_complex
{
	double	x;
	double	y;
}		t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}		t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_start;
	void	*mlx_window;
	t_img	img;
	double	escape_value;
	int		iterations_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}		t_fractal;

t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putstr(char *s);
double		atodbl(char *s);
void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
int			close_handler(t_fractal *fractal);
int			key_handler(int keysym, t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			julia_track(int x, int y, t_fractal *fractal);
double		scaling(double unscaled_num, double new_min, 
				double new_max, double old_max);

#endif
