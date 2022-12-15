/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 06:00:06 by mbennani          #+#    #+#             */
/*   Updated: 2022/12/15 21:07:30 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int key_hooks(int keycode, t_fdf *mats)
{
	if(keycode == 13 || keycode == 1)
		rotationx(keycode, mats);
	if(keycode == 2 || keycode == 0)
		rotationy(keycode, mats);
	if(keycode == 14 || keycode == 12)
		rotationz(keycode, mats);
	if(keycode == 126 || keycode == 125 || keycode == 124 || keycode == 123)
		translation(keycode, mats);
	if(keycode == 6 || keycode == 8)
		zoom(keycode, mats);
	mlx_clear_window(mats->mlx, mats->win);
	vector_trans(mats);
	draw_frame(mats);
	return (0);
}

void val_init(t_fdf *mats)
{
	mats->width = 5;
	mats->height = 5;
	mats->area = mats->width * mats->height;
	mats->origin = nml_mat_new(3, 1);
	mats->i = nml_mat_new(3, 1);
	mats->j = nml_mat_new(3, 1);
	mats->k = nml_mat_new(3, 1);
	mats->origin->data[0][0] = x/2;
	mats->origin->data[1][0] = y/2;
	mats->origin->data[2][0] = 0;
	mats->i->data[0][0] = 30;
	mats->i->data[1][0] = 0;
	mats->i->data[2][0] = 0;
	mats->j->data[0][0] = 0;
	mats->j->data[1][0] = 30;
	mats->j->data[2][0] = 0;
	mats->k->data[0][0] = 0;
	mats->k->data[1][0] = 0;
	mats->k->data[2][0] = 20;
	mats->angle = 0;
	rotx_init(mats);
	roty_init(mats);
	rotz_init(mats);
}



int main (int ac, char **av)
{
	t_fdf		mats;

	if(ac == 2)
	{
		val_init(&mats);
		mats.mlx = mlx_init();
		mats.win =  mlx_new_window(mats.mlx, x, y, "3D");
		mats.fd = open(av[1], O_RDONLY, 777);
		mats.map = map_reader(&mats);
		mats.vecs = vector_maker(&mats);
		isoview(100, &mats);
		mlx_key_hook (mats.win, key_hooks, &mats);
		draw_frame(&mats);
		mlx_loop(mats.mlx);
		}
}