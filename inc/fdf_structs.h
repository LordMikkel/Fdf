/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:59:36 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/09 19:27:01 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_H
# define FDF_STRUCTS_H

# include "fdf_macros.h"

/* ************************************************************************** */
/*                           Map Structure                                    */
/* ************************************************************************** */

typedef struct s_color
{
	int	r1;
	int	g1;
	int	b1;
	int	r2;
	int	g2;
	int	b2;
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_point_2d
{
	int		x;
	int		y;
	int		color;
}	t_point_2d;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	float	w;
	int		color;
}	t_point;

typedef struct s_line
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		error;
	int		double_error;
	int		c1;
	int		c2;
	int		mix_c;
	float	steps;
	float	t;
}	t_line;

typedef struct s_map
{
	t_point	**points;
	int		width;
	int		height;
	int		max_z;
	int		min_z;
	int		type;
	int		object;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		length;
	int		endian;
}	t_img;

typedef struct s_cam
{
	float	zoom;
	float	x_offset;
	float	y_offset;
	float	alpha;
	float	beta;
	float	gamma;
	float	projection;
}	t_cam;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_map	map;
	t_cam	cam;
}	t_fdf;

#endif
