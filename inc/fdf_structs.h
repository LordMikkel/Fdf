/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:59:36 by migarrid          #+#    #+#             */
/*   Updated: 2025/05/23 01:38:44 by migarrid         ###   ########.fr       */
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
	float	w;
	int		color;
}	t_point;

typedef struct s_map
{
	t_point	**points;
	char	**tokens;
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
	t_map	map;
}	t_fdf;

#endif
