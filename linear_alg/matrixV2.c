/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrixV2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:14:54 by mbennani          #+#    #+#             */
/*   Updated: 2022/12/11 16:03:06 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_alg.h"

int	nml_mat_add_r(nml_mat *m1, nml_mat *m2)
{
	int	i;
	int	j;
	while (i < m1->num_rows){
		while (j < m1->num_cols) {
			m1->data[i][j] += m2->data[i][j];
			j++;
		}
		i++;
	}
	return 1;
}

nml_mat	*nml_mat_add(nml_mat *m1, nml_mat *m2)
{
	nml_mat	*r = nml_mat_cp(m1);

	if (!nml_mat_add_r(r, m2)){
		nml_mat_free(r);
	return NULL;
	}
	return r;
}


nml_mat	*nml_mat_dot(nml_mat *m1, nml_mat *m2)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	nml_mat *r = nml_mat_new(m1->num_rows, m2->num_cols);
	if (!r) {
		nml_mat_free(r);
		return NULL;
	}
	while (i < r->num_rows){
		j = 0;
		while (j < r->num_cols){
			k = 0;
    		while (k < m1->num_cols){
    			r->data[i][j] += m1->data[i][k] * m2->data[k][j];
				k++;
    		}
			j++;
		}
		i++;
	}
	return r;
}
