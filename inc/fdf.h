/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 18:29:16 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/09 23:34:18 by migarrid         ###   ########.fr       */
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
/*                             Initialization                                 */
/* ************************************************************************** */
int		init_data(t_fdf *data);
void	init_cam(t_cam *cam, t_map *map);
void	init_line(t_line *line, t_point_2d a, t_point_2d b);
int		allocate_points_map_memory(t_map *map);

/* ************************************************************************** */
/*                                    4d                                      */
/* ************************************************************************** */
int		check_4d_mode(const char *av, t_map *map);
int		init_4d(const char *av, t_map *map);
int		diff_coords(t_point *a, t_point *b);
int		init_tesseract(t_map *map);
int		init_pentachoron(t_map *map);
int		init_hecatonicosachoron(t_map *map);
void	move_map_to_origin_4d(t_point *point, t_map map, t_cam cam);

/* ************************************************************************** */
/*                          Rendering & Projection                            */
/* ************************************************************************** */
void	render_fdf(t_fdf *data, t_map *map);
void	render_3d_map(t_fdf *data, t_map *map);
void	rotate_x(float *y, float *z, float angle);
void	rotate_y(float *x, float *z, float angle);
void	rotate_z(float *x, float *y, float angle);
t_point	project_point(t_point point, t_map map, t_cam cam);

/* ************************************************************************** */
/*                            transformations                                 */
/* ************************************************************************** */
void	set_isometric_view(t_cam *cam);
void	set_top_view(t_cam *cam);
void	set_front_view(t_cam *cam);
void	set_lateral_view(t_cam *cam);
void	set_pov_view(t_cam *cam);
void	set_spherical_view(t_cam *cam);
void	scale_map_z(t_point **points, int width, int height, float scale);
void	move_map_to_origin(t_point *point, t_map map, t_cam cam);

/* ************************************************************************** */
/*                             Line Drawing                                   */
/* ************************************************************************** */
void	draw_line(t_point a, t_point b, t_fdf *data);
void	ft_mlx_put_pixel(t_fdf *data, int x, int y, int color);

/* ************************************************************************** */
/*                            Color Handling                                  */
/* ************************************************************************** */
int		interpolate_color(int color1, int color2, float t);
int		assign_height_color(t_point *pt, t_map *map);

/* ************************************************************************** */
/*                            Event Handling                                  */
/* ************************************************************************** */
void	mlx_setup(t_fdf *data);
int		handle_key(int key, t_fdf *data);
int		handle_mouse(int button, int x, int y, t_fdf *data);
int		handle_mouse_move(int x, int y, t_fdf *data);
int		handle_mouse_release(int button, int x, int y, t_fdf *data);
int		handle_resize(t_fdf *data);

/* ************************************************************************** */
/*                                utils                                       */
/* ************************************************************************** */
float	square(float x);
void	find_min_max_z(t_map *map);

/* ************************************************************************** */
/*                          Memory Management                                 */
/* ************************************************************************** */
void	clear_image(t_fdf *data);
void	free_data(t_fdf *data);

/* ************************************************************************** */
/*                            Error Handling                                  */
/* ************************************************************************** */
void	error_exit(t_fdf *data);
int		close_exit(t_fdf *data);

#endif
