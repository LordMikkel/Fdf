/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:59:36 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/01 02:12:40 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_H
# define FDF_STRUCTS_H

# include "fdf_macros.h"

/* ************************************************************************** */
/*                           Map Structure                                    */
/* ************************************************************************** */

typedef struct s_point
{
	int		x;
	int		y;
	float	z;
	float	w;
	int		color;
}	t_point;

typedef struct s_map
{
	t_point	**points;
	int		width;
	int		height;
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
