/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:53:06 by mbennani          #+#    #+#             */
/*   Updated: 2022/12/14 04:08:01 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	isoview(int keycode, t_fdf *mats)
{
	if (keycode == 100)
	{
		mats->angle = 0.57;
		rotationz(100, mats);
		rotationx(100, mats);
		vector_trans(mats);
	}
	return (0);
}

int	xview(int keycode, t_fdf *mats)
{
	if (keycode == 12)
	{
		mats->angle = 0;
		rotationz(100, mats);
		rotationx(100, mats);
		vector_trans(mats);
	}
	return (0);
}

int	yview(int keycode, t_fdf *mats)
{
	if (keycode == 12)
	{
		mats->angle = 1.5708;
		rotationx(100, mats);
		vector_trans(mats);
	}
	return (0);
}