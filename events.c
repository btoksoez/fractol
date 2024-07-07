/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:02:45 by btoksoez          #+#    #+#             */
/*   Updated: 2024/05/22 10:24:53 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom(t_fractal *f, double zoom)
{
	double	width;
	double	height;

	width = f->max_r - f->min_r;
	height = f->max_i - f->min_i;
	f->min_r = f->min_r + (width - zoom * width) / 2;
	f->max_r = f->max_r - (width - zoom * width) / 2;
	f->min_i = f->min_i + (height - zoom * height) / 2;
	f->max_i = f->max_i - (height - zoom * height) / 2;
}

static void	move(t_fractal *f, double distance, char direction)
{
	double	center_r;
	double	center_i;

	center_r = f->max_r - f->min_r;
	center_i = f->max_i - f->min_i;
	if (direction == 'L')
	{
		f->max_r -= center_r * distance;
		f->min_r -= center_r * distance;
	}
	if (direction == 'R')
	{
		f->max_r += center_r * distance;
		f->min_r += center_r * distance;
	}
	if (direction == 'U')
	{
		f->max_i += center_i * distance;
		f->min_i += center_i * distance;
	}
	if (direction == 'D')
	{
		f->max_i -= center_i * distance;
		f->min_i -= center_i * distance;
	}
}

int	key_press(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_window(fractal);
	if (keysym == XK_equal)
		fractal->max_iter += 10;
	if (keysym == XK_minus)
	{
		if (fractal->max_iter > 10)
			fractal->max_iter -= 10;
		else
			fractal->max_iter = 10;
	}
	if (keysym == XK_Left)
		move(fractal, 0.1, 'L');
	if (keysym == XK_Right)
		move(fractal, 0.1, 'R');
	if (keysym == XK_Up)
		move(fractal, 0.1, 'U');
	if (keysym == XK_Down)
		move(fractal, 0.1, 'D');
	fractal_render(fractal);
	return (0);
}


