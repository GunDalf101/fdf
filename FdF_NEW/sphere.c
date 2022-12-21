/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbennani <mbennani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:05:11 by mbennani          #+#    #+#             */
/*   Updated: 2022/12/19 03:20:02 by mbennani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <mlx.h>
// #include "fdf.h"

// Constants
#define PI 3.14159265358979323846
#define RADIUS 30.0
#define SEGMENTS_H 15
#define SEGMENTS_V 15

int main(int argc, char** argv) {
	void *mlx = mlx_init();
	void *win =  mlx_new_window(mlx, 1000, 1000, "3D");
  // Loop over the horizontal segments
  
  for (int i = 0; i < SEGMENTS_H; i++) {
    // Loop over the vertical segments
    for (int j = 0; j < SEGMENTS_V; j++) {
      // Calculate the spherical coordinates of the current point
      double theta = 2 * PI * (double)i / (double)SEGMENTS_H;
      double phi = PI * (double)j / (double)SEGMENTS_V;

      // Convert the spherical coordinates to Cartesian coordinates
      double x = RADIUS * sin(phi) * cos(theta);
      double y = RADIUS * sin(phi) * sin(theta);
      double z = RADIUS * cos(phi);

      // Project the 3D Cartesian coordinates onto the 2D plane
      double projection_x = x;
      double projection_y = y;

      // Draw a line between the current point and the next point in the horizontal direction
      if (i < SEGMENTS_H - 1) {
        double theta_next = 2 * PI * (double)(i + 1) / (double)SEGMENTS_H;
        double phi_next = PI * (double)j / (double)SEGMENTS_V;
        double x_next = RADIUS * sin(phi_next) * cos(theta_next);
        double y_next = RADIUS * sin(phi_next) * sin(theta_next);
        double z_next = RADIUS * cos(phi_next);
        double projection_x_next = x_next;
        double projection_y_next = y_next;
        printf("Draw line from (%f, %f) to (%f, %f)\n", projection_x, projection_y, projection_x_next, projection_y_next);
      }

      // Draw a line between the current point and the next point in the vertical direction
        double theta_next = 2 * PI * (double)i / (double)SEGMENTS_H;
        double phi_next = PI * (double)(j + 1) / (double)SEGMENTS_V;
        double x_next = RADIUS * sin(phi_next) * cos(theta_next);
        double y_next = RADIUS * sin(phi_next) * sin(theta_next);
        double z_next = RADIUS * cos(phi_next);
        double projection_x_next = x_next;
        double projection_y_next = y_next;
        mlx_pixel_put(mlx, win, projection_x_next, projection_y_next , 0xFF0000);
		// projection_x, win, projection_x_next, projection_y_next
      
    }
  }
	mlx_loop(mlx);
  return 0;
}


		