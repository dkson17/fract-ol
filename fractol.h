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

# define WIDTH 800
# define HEIGHT 800

# define ITERATIONS 55

# define ERROR_MESSAGE \
"\t*Please enter* \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia with\
 or without 2 values\" or \n\t\"./fractol burning_ship\" or\n\t\"./fractol \
 tricorn\" \\n\t*For more details, please enter ./fractol Info*\n"

# define INFORMATION "\t*Welcome to my magic world of fractals!* \
\n\t*To switch between fractals, please press 'space'.* \
\n\t*To change colors, please press '+' or '-'.* \
\n\t*To move fractals \
inside the window, please use arrow keys.* \
\n\t*To change Julia \
fractal, please use the left mouse button.* \
\n\t*Enjoy your exploration! <3* \n"

# define BLACK       0x000000
# define WHITE       0xFFFFFF
# define RED         0xFF0000
# define GREEN       0x00FF00
# define BLUE        0x0000FF
# define PASTEL_PINK	0xFFB6C1
# define PASTE_BLUE	0xADD8E6
# define PASTE_PEACH	0xFFDAB9
# define PASTE_LAVANDER	0xE6E6FA
# define PASTE_MINT	0xBDFCC9
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
void		handle_pixel(int x, int y, t_fractal *fractal);
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
int			mandelbrot_set(t_fractal *fractal, double x, double y);
int			julia_set(t_fractal *fractal, double x, double y);
int			tricorn_set(t_fractal *fractal, double x, double y);
int			burning_ship(t_fractal *fractal, double x, double y);

#endif
