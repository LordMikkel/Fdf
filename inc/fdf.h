/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:29:16 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/01 18:49:52 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* ************************************************************************** */
/*                               Includes                                     */
/* ************************************************************************** */
# include "../lib/libft_plus/libft_plus.h"
# include "../lib/minilibx-linux/mlx.h"
# include <math.h>
# include <errno.h>
# include "fdf_structs.h"
# include "fdf_macros.h"

/* ************************************************************************** */
/*                          Parsing & Validation                              */
/* ************************************************************************** */
int		parse_map(const char *filename, t_map *map);
int		calculate_dimensions(int fd, t_map *map);
int		parse_values(int fd, t_map *map);

/* ************************************************************************** */
/*                          Error Handling                                    */
/* ************************************************************************** */
void	error_exit(t_fdf *data);
int		close_exit(t_fdf *data);

/* ************************************************************************** */
/*                          Initialization                                    */
/* ************************************************************************** */
int		init_data(t_fdf *data);
void	init_cam(t_cam *cam, t_map *map);
int		allocate_points_map_memory(t_map *map);

/* ************************************************************************** */
/*                          Rendering & Projection                            */
/* ************************************************************************** */
void	render_fdf(t_fdf *data, t_map *map, t_cam *cam);
void	draw_map(t_fdf *data, t_map *map);
void	rotate_x(float *y, float *z, float angle);
void	rotate_y(float *x, float *z, float angle);
void	rotate_z(float *x, float *y, float angle);
t_point	project_point(t_point point, t_cam cam);

/* ************************************************************************** */
/*                          Line Drawing                                      */
/* ************************************************************************** */
void	ft_mlx_put_pixel(t_fdf *data, int x, int y, int color);

/* ************************************************************************** */
/*                          Color Handling                                    */
/* ************************************************************************** */

/* ************************************************************************** */
/*                          Event Handling                                    */
/* ************************************************************************** */
void	mlx_setup(t_fdf *data);
int		handle_key(int key, t_fdf *data);
int		handle_mouse(int button, int x, int y, t_fdf *data);

/* ************************************************************************** */
/*                          Memory Management                                 */
/* ************************************************************************** */
int		free_data(t_fdf *data);

#endif
