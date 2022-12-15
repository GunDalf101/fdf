/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:48:36 by mbennani          #+#    #+#             */
/*   Updated: 2022/12/14 03:39:20 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int draw_frame(t_fdf *mats)
{
	int 	i , j;
	double 	dx, dy, x0, y0, x1 ,y1, p;

	double step, xinc, yinc;
	i = 1;
	while (i < mats->area)
	{
		x0 = mats->vecs[i - 1]->data[0][0];
		y0 = mats->vecs[i - 1]->data[1][0];
		x1 = mats->vecs[i]->data[0][0];
		y1 = mats->vecs[i]->data[1][0];
		dx = x1 - x0;
		dy = y1 - y0;
		if (fabs(dx) > fabs(dy))
			step = fabs(dx);
		else
			step = fabs(dy);
		xinc = dx / step;
		yinc = dy / step;
		j = 0;
		while (j <= step)
		{
			mlx_pixel_put(mats->mlx, mats->win,	mats->origin->data[0][0] / 2 + x0, mats->origin->data[1][0] / 2 - y0 , 0xFF0000);
			x0 = x0 + xinc;
			y0 = y0 + yinc;
			j++;
		}
		if ((i + 1) % mats->width == 0)
			i++;
		i++;
	}
	i = 1;
	while (i < mats->area - mats->width + 1)
	{
		x1 = mats->vecs[i - 1]->data[0][0];
		y1 = mats->vecs[i - 1]->data[1][0];
		x0 = mats->vecs[i + mats->width - 1]->data[0][0];
		y0 = mats->vecs[i + mats->width - 1]->data[1][0];
		dx = x1 - x0;
		dy = y1 - y0;
		if (fabs(dx) > fabs(dy))
			step = fabs(dx);
		else
			step = fabs(dy);
		xinc = dx / step;
		yinc = dy / step;
		j = 0;
		while (j <= step)
		{
			mlx_pixel_put(mats->mlx, mats->win,	mats->origin->data[0][0] / 2 + x0, mats->origin->data[1][0] / 2 - y0 , 0xFF0000);
			x0 = x0 + xinc;
			y0 = y0 + yinc;
			j++;
		}
		i++;
	}
	return (0);
}