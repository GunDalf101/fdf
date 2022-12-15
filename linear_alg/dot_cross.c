/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot_cross.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 20:59:56 by mbennani          #+#    #+#             */
/*   Updated: 2022/11/28 23:27:36 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_alg.h"

int	dotProduct(nml_mat vect_A, nml_mat vect_B)
{
	int	i;
    int	product;
 
    product = 0;
	i = 0;
    while (i < 10)
	{
        product = product + vect_A.data[i][0] * vect_A.data[i][0];
		i++;
	}
    return (product);
}

void	crossProduct(nml_mat vect_A, nml_mat vect_B, nml_mat cross_P)
 
{
    cross_P.data[0][0] = vect_A.data[1][0] * vect_B.data[2][0] - vect_A.data[2][0] * vect_B.data[1][0];
    cross_P.data[1][0] = vect_A.data[2][0] * vect_B.data[0][0] - vect_A.data[0][0] * vect_B.data[2][0];
    cross_P.data[2][0] = vect_A.data[0][0] * vect_B.data[1][0] - vect_A.data[1][0] * vect_B.data[0][0];
}