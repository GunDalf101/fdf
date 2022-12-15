/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 06:00:01 by mbennani          #+#    #+#             */
/*   Updated: 2022/12/15 21:00:10 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "linear_alg/linear_alg.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "gnl/get_next_line_bonus.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>

# define x 2000
# define y 1000

typedef struct s_fdf {
	void				*mlx;
	void				*win;
	int					fd;
	int					width;
	int					height;
	int					area;
	int					**map;
	struct nml_mat_s	**vecs;
	struct nml_mat_s	*rotmatz;
	struct nml_mat_s	*rotmatx;
	struct nml_mat_s	*rotmaty;
	struct nml_mat_s	*origin;
	struct nml_mat_s	*i;
	struct nml_mat_s	*j;
	struct nml_mat_s	*k;
	double				angle;
} t_fdf;

int 	**map_reader(t_fdf *mats);
nml_mat	**vector_maker(t_fdf *mats);
int		rotationz(int keycode, t_fdf *mats);
int		rotationy(int keycode, t_fdf *mats);
int		rotationx(int keycode, t_fdf *mats);
void	rotz_init(t_fdf *mats);
void	rotx_init(t_fdf *mats);
void	roty_init(t_fdf *mats);
int		isoview(int keycode, t_fdf *mats);
int		translation(int keycode, t_fdf *mats);
int		zoom(int keycode, t_fdf *mats);
int		draw_frame(t_fdf *mats);
void	vector_trans(t_fdf *mats);
int	read_height (t_fdf *mats);


#endif

/*
                              ___                     ___              _        __     _       __      _    
    o O O    o O O    o O O  / __|   _  _    _ _     |   \   __ _     | |      / _|   / |     /  \    / |   
   o        o        o      | (_ |  | +| |  | ' \    | |) | / _` |    | |     |  _|   | |    | () |   | |   
  TS__[O]  TS__[O]  TS__[O]  \___|   \_,_|  |_||_|   |___/  \__,_|   _|_|_   _|_|_   _|_|_   _\__/   _|_|_  
 {======| {======| {======|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""|_|"""""| 
./o--000'./o--000'./o--000'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'"`-0-0-'
*/