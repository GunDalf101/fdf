/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 13:25:35 by mbennani          #+#    #+#             */
/*   Updated: 2022/12/18 00:11:58 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void rotx_init(t_fdf *mats)
{
	mats->rotmatx = nml_mat_new(3, 3);
	mats->rotmatx->data[0][0] = 1;
	mats->rotmatx->data[0][1] = 0;
	mats->rotmatx->data[0][2] = 0;
	mats->rotmatx->data[1][0] = 0;
	mats->rotmatx->data[1][1] = cos(mats->angle);
	mats->rotmatx->data[1][2] = -sin(mats->angle);
	mats->rotmatx->data[2][0] = 0;
	mats->rotmatx->data[2][1] = sin(mats->angle);
	mats->rotmatx->data[2][2] = cos(mats->angle);
}

void roty_init(t_fdf *mats)
{
	mats->rotmaty = nml_mat_new(3, 3);
	mats->rotmaty->data[0][0] = cos(mats->angle);
	mats->rotmaty->data[0][1] = 0;
	mats->rotmaty->data[0][2] = -sin(mats->angle);
	mats->rotmaty->data[1][0] = 0;
	mats->rotmaty->data[1][1] = 1;
	mats->rotmaty->data[1][2] = 0;
	mats->rotmaty->data[2][0] = sin(mats->angle);
	mats->rotmaty->data[2][1] = 0;
	mats->rotmaty->data[2][2] = cos(mats->angle);
}

void rotz_init(t_fdf *mats)
{
	mats->rotmatz = nml_mat_new(3, 3);
	mats->rotmatz->data[0][0] = cos(mats->angle);
	mats->rotmatz->data[0][1] = -sin(mats->angle);
	mats->rotmatz->data[0][2] = 0;
	mats->rotmatz->data[1][0] = sin(mats->angle);
	mats->rotmatz->data[1][1] = cos(mats->angle);
	mats->rotmatz->data[1][2] = 0;
	mats->rotmatz->data[2][0] = 0;
	mats->rotmatz->data[2][1] = 0;
	mats->rotmatz->data[2][2] = 1;
}