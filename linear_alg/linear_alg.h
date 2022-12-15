/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_alg.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:15:21 by mbennani          #+#    #+#             */
/*   Updated: 2022/12/11 14:40:52 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINEAR_ALG_H
# define LINEAR_ALG_H

typedef struct nml_mat_s {
	unsigned int num_rows;
	unsigned int num_cols;
	double **data;
	int is_square;
} nml_mat;

nml_mat	*nml_mat_new(unsigned int num_rows, unsigned int num_cols);
void	nml_mat_free(nml_mat *matrix);
void	nml_mat_printf(nml_mat *matrix);
nml_mat	*nml_mat_cp(nml_mat *matrix);
int		nml_mat_add_r(nml_mat *m1, nml_mat *m2);
nml_mat	*nml_mat_add(nml_mat *m1, nml_mat *m2);
nml_mat	*nml_mat_dot(nml_mat *m1, nml_mat *m2);
int		dotProduct(nml_mat vect_A, nml_mat vect_B);
void	crossProduct(nml_mat vect_A, nml_mat vect_B, nml_mat cross_P);

# include "../fdf.h"

#endif