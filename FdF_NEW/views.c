/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:53:06 by mbennani          #+#    #+#             */
/*   Updated: 2022/12/19 08:50:49 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	isoview(int keycode, t_fdf *mats)
{
	if (keycode == 48)
	{
		
		mats->i->data[0][0] = (25.98 / RATIO) * mats->A / mats->B;
		mats->i->data[1][0] = (-12.5 / RATIO) * mats->A / mats->B;
		mats->i->data[2][0] = (-7.499966 / RATIO) * mats->A / mats->B;
		mats->j->data[0][0] = (-15.000000 / RATIO) * mats->A / mats->B;
		mats->j->data[1][0] = (-22.500034 / RATIO) * mats->A / mats->B;
		mats->j->data[2][0] = (-12.990321 / RATIO) * mats->A / mats->B;
		mats->k->data[0][0] = (0.000000 / RATIO) * mats->A / mats->B;
		mats->k->data[1][0] = (2.499989 * ZRATIO / RATIO) * mats->A / mats->B;
		mats->k->data[2][0] = (-4.330134 * ZRATIO / RATIO) * mats->A / mats->B;
		vector_trans(mats);
	}
	return (0);
}

int	xview(int keycode, t_fdf *mats)
{
	if (keycode == 7)
	{
		mats->i->data[0][0] = (30.0 / RATIO) * mats->A / mats->B;
		mats->i->data[1][0] = 0;
		mats->i->data[2][0] = 0;
		mats->j->data[0][0] = 0;
		mats->j->data[1][0] = - (30.0 / RATIO) * mats->A / mats->B;
		mats->j->data[2][0] = 0;
		mats->k->data[0][0] = 0;
		mats->k->data[1][0] = 0;
		mats->k->data[2][0] = - (5.0 * ZRATIO / RATIO) * mats->A / mats->B;
		vector_trans(mats);
	}
	return (0);
}

int	yview(int keycode, t_fdf *mats)
{
	if (keycode == 16)
	{
		mats->i->data[0][0] = (30.0 / RATIO) * mats->A / mats->B;
		mats->i->data[1][0] = 0;
		mats->i->data[2][0] = 0;
		mats->j->data[0][0] = 0;
		mats->j->data[1][0] = 0;
		mats->j->data[2][0] = (30.0 / RATIO) * mats->A / mats->B;
		mats->k->data[0][0] = 0;
		mats->k->data[1][0] = (5.0 * ZRATIO / RATIO) * mats->A / mats->B;
		mats->k->data[2][0] = 0;
		vector_trans(mats);
	}
	return (0);
}