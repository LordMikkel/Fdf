/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:59:36 by migarrid          #+#    #+#             */
/*   Updated: 2025/05/22 16:49:37 by migarrid         ###   ########.fr       */
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
	float	x;
	float	y;
	float	z;
	int		color;
}	t_point;

typedef struct s_map
{
	t_point	**points;
	int		**colors;
	int		width;
	int		height;
}	t_map;

typedef struct s_fdf
{
	int		fd;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	t_map	*map;
}	t_fdf;

#endif
