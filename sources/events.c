/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btoksoez <btoksoez@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:02:45 by btoksoez          #+#    #+#             */
/*   Updated: 2024/07/11 12:21:12 by btoksoez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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
	if (keysym == ESC)
		close_window(fractal);
	if (keysym == EQUAL)
		fractal->max_iter += 10;
	if (keysym == MINUS)
	{
		if (fractal->max_iter > 10)
			fractal->max_iter -= 10;
		else
			fractal->max_iter = 10;
	}
	if (keysym == LEFT_KEY)
		move(fractal, 0.1, 'L');
	if (keysym == RIGHT_KEY)
		move(fractal, 0.1, 'R');
	if (keysym == UP_KEY)
		move(fractal, 0.1, 'U');
	if (keysym == DOWN_KEY)
		move(fractal, 0.1, 'D');
	if (keysym == W_KEY)
		zoom(fractal, 0.8);
	if (keysym == S_KEY)
		zoom(fractal, 1.2);
	fractal_render(fractal);
	return (0);
}


