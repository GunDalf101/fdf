/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrixV1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:13:46 by mbennani          #+#    #+#             */
/*   Updated: 2022/12/02 15:05:57 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linear_alg.h"

nml_mat	*nml_mat_new(unsigned int num_rows, unsigned int num_cols)
{
	int		i;
	nml_mat	*mat;

	i = 0;
	mat = ft_calloc(1, sizeof(*mat));
	mat->num_rows = num_rows;
	mat->num_cols = num_cols;
	mat->is_square = (num_rows == num_cols) ? 1 : 0;
	mat->data = ft_calloc(mat->num_rows, sizeof(*mat->data));
	
	while (i < mat->num_rows){
    	mat->data[i] = ft_calloc(mat->num_cols, sizeof(**mat->data));
		i++;
  	}
	return (mat);
}

void	nml_mat_free(nml_mat *matrix)
{
  int i;

  i = 0;
  while (i < matrix->num_rows){
    free(matrix->data[i]);
	i++;
  }
  free(matrix->data);
  free(matrix);
}

void	nml_mat_printf(nml_mat *matrix)
{
	int	i;
	int	j;

	i = 0;
	ft_printf("\n");
	while (i < matrix->num_rows) {
		while (j < matrix->num_cols) {
			ft_printf("%lf ", matrix->data[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}

nml_mat *nml_mat_cp(nml_mat *matrix)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	nml_mat *r = nml_mat_new(matrix->num_rows, matrix->num_cols);
	while (i < matrix->num_rows) {
    	while (j < matrix->num_cols) {
    		r->data[i][j] = matrix->data[i][j];
			j++;
    	}
		i++;
	}
	return (r);
}