/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:45:14 by mbennani          #+#    #+#             */
/*   Updated: 2022/12/19 11:16:04 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int **map_reader(t_fdf *mats)
{
	char	*line;
	int		*width;
	char	**line2D;
	int		**map;
	int		i;
	int		j;

	
	line  = get_next_line(mats->fd);
	// i = 0;
	// j = 1;
	// while(line[i] != '\n')
	// {
	// 	if(line[i] == ' ' && j == 0)
	// 	{
	// 		j = 1;
	// 		mats->width++;
	// 	} else if (line[i] != ' ' && j == 1) {
	// 		j = 0;
	// 	}
	// 	i++;
	// }
	// mats->width++;
	// mats->width-=30;
	map = ft_calloc(mats->height, sizeof(int *));
	i = 0;
	while (line)
	{
		j = 0;
		line2D = ft_split (line, ' ');
		map[i] = ft_calloc(mats->width, sizeof(int));
		while (j < mats->width)
		{
			map[i][j] = ft_atoi(line2D[j]);
			j++;
		}
		line  = get_next_line(mats->fd);
		i++;
	}
	return (map);
}

nml_mat	**vector_maker(t_fdf *mats)
{
	nml_mat **vectors;
	int	i;
	int	j;

	vectors = ft_calloc(mats->area, sizeof(nml_mat *));
	i = 0;
	while (i < mats->height)
	{
		j = 0;
		while (j < mats->width)
		{
			vectors[i * mats->width + j] = nml_mat_new(3, 1); 
			vectors[i * mats->width + j]->data[0][0] = j * mats->i->data[0][0] \
			+ i * mats->j->data[0][0] + mats->map[i][j] * mats->k->data[0][0];
			vectors[i * mats->width + j]->data[1][0] = j * mats->i->data[1][0] \
			+ i * mats->j->data[1][0]+ mats->map[i][j] * mats->k->data[1][0];
			vectors[i * mats->width + j]->data[2][0] = j * mats->i->data[2][0] \
			+ i * mats->j->data[2][0] + mats->map[i][j] * mats->k->data[2][0];
			j++;
		}
		i++;
	}
	return (vectors);
}

void	vector_trans(t_fdf *mats)
{
	int 	i;
	int		j;
	i = 0;
	while (i < mats->height)
	{
		j = 0;
		while (j < mats->width)
		{
			mats->vecs[i * mats->width + j]->data[0][0] = (j - mats->width / 2) * mats->i->data[0][0] \
			+ (i - mats->height / 2) * mats->j->data[0][0] + mats->map[i][j] * mats->k->data[0][0];
			mats->vecs[i * mats->width + j]->data[1][0] = (j - mats->width / 2) * mats->i->data[1][0] \
			+ (i - mats->height / 2) * mats->j->data[1][0] + mats->map[i][j] * mats->k->data[1][0];
			mats->vecs[i * mats->width + j]->data[2][0] = j * mats->i->data[2][0] \
			+ i * mats->j->data[2][0] + mats->map[i][j] * mats->k->data[2][0];
			j++;
		}
		i++;
	}
}
