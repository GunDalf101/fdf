/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:33:38 by mbennani          #+#    #+#             */
/*   Updated: 2022/12/14 04:15:12 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	rotationx(int keycode, t_fdf *mats)
{
	nml_mat *tempi;
	nml_mat *tempj;
	nml_mat *tempk;
	mats->angle += 3.14159;
	if (keycode == 13)
		mats->angle = -0.05;
	if (keycode == 1)
		mats->angle = 0.05;
	rotx_init(mats);
	tempi = nml_mat_dot(mats->rotmatx, mats->i);
	tempj = nml_mat_dot(mats->rotmatx, mats->j);
	tempk = nml_mat_dot(mats->rotmatx, mats->k);
	mats->i = tempi;
	mats->j = tempj;
	mats->k = tempk;
	return (0);
}

int	rotationy(int keycode, t_fdf *mats)
{
	nml_mat *tempi;
	nml_mat *tempj;
	nml_mat *tempk;
	if (keycode == 2)
		mats->angle = -0.05;
	if (keycode == 0)
		mats->angle = 0.05;
	roty_init(mats);
	tempi = nml_mat_dot(mats->rotmaty, mats->i);
	tempj = nml_mat_dot(mats->rotmaty, mats->j);
	tempk = nml_mat_dot(mats->rotmaty, mats->k);
	mats->i = tempi;
	mats->j = tempj;
	mats->k = tempk;
	return (0);
}

int	rotationz(int keycode, t_fdf *mats)
{
	nml_mat *tempi;
	nml_mat *tempj;
	nml_mat *tempk;
	if (keycode == 14)
		mats->angle = -0.05;
	if (keycode == 12)
		mats->angle = 0.05;
	rotz_init(mats);
	tempi = nml_mat_dot(mats->rotmatz, mats->i);
	tempj = nml_mat_dot(mats->rotmatz, mats->j);
	tempk = nml_mat_dot(mats->rotmatz, mats->k);
	mats->i = tempi;
	mats->j = tempj;
	mats->k = tempk;
	return (0);
}

int	translation(int keycode, t_fdf *mats)
{
	if (keycode == 126)
		mats->origin->data[1][0] -= 10;
	if (keycode == 125)
		mats->origin->data[1][0] += 10;
	if (keycode == 124)
		mats->origin->data[0][0] += 10;
	if (keycode == 123)
		mats->origin->data[0][0] -= 10;
	return (0);
}

int	zoom(int keycode, t_fdf *mats)
{
	int i;

	i = 0;
	if (keycode == 6)
	{
		while(i < 3)
		{
			mats->i->data[i][0] *= 1.2;
			mats->j->data[i][0] *= 1.2;
			mats->k->data[i][0] *= 1.2;
			i++;
		}
	}
	i = 0;
	if (keycode == 8)
	{
		while(i < 3)
		{
			mats->i->data[i][0] /= 1.2;
			mats->j->data[i][0] /= 1.2;
			mats->k->data[i][0] /= 1.2;
			i++;
		}
	}
	return (0);
}

