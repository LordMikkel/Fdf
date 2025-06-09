/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_macros.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:59:15 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/09 21:03:26 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_MACROS_H
# define FDF_MACROS_H

/* ************************************************************************** */
/*                          Maths and Projections                             */
/* ************************************************************************** */
# define ISOMETRIC		0
# define ORTHOGONAL		1
# define POV			2
# define PI				3.14159265358979323846
# define DEFAULT_ANG 	0.6154797f
# define OBJECT_3D		3
# define OBJECT_4D		4
# define PENTACHORON	5
# define TESSERACT		16

/* ************************************************************************** */
/*                          Error & Limits                                    */
/* ************************************************************************** */
# define STDERR			2
# define TRUE			1
# define FALSE			0
# define ERR_ARGS		"Usage: Provide one .fdf file (ex: ./fdf map.fdf)\n"
# define ERR_EXT		"Error: Invalid map format. file must be .fdf\n"
# define ERR_OPEN		"Error: Can't open file. Check existence/permissions\n"
# define ERR_READ		"Error: Read failed. May be corrupted/inaccessible\n"
# define ERR_PARSE		"Error: Data parsing failed. Check number formatting\n"
# define ERR_LINE		"Error: Line length mismatch. Rows must be equals\n"
# define ERR_EMPTY		"Error: Empty file. Valid .fdf required\n"
# define ERR_MEM		"Error: Memory alloc failed. Check system resources\n"
# define ERR_MLX		"Error: Mlx init failed. Check system resources\n"

/* ************************************************************************** */
/*                          Key Bindings and Events                           */
/* ************************************************************************** */
# define CLOSE_EVENT	17
# define NO_FILTER		0
# define ESC_KEY		65307
# define KEY_LEFT		65361
# define KEY_RIGHT		65363
# define KEY_DOWN		65364
# define KEY_UP			65362
# define KEY_MINUS1		45
# define KEY_MINUS2		65453
# define KEY_PLUS1		61
# define KEY_PLUS2		65451
# define KEY_I			105
# define KEY_T			116
# define KEY_F			102
# define KEY_L			108
# define KEY_Q			113
# define KEY_W			119
# define KEY_P			112
# define KEY_S			115
# define ZOOM_IN		4
# define ZOOM_OUT		5
# define ROTATE_LEFT	7
# define ROTATE_RIGHT	6
# define CLICK			1

/* ************************************************************************** */
/*                          Window Settings                                   */
/* ************************************************************************** */
# define WIN_WIDTH		720
# define WIN_HEIGHT		720

/* ************************************************************************** */
/*                                Colors                                      */
/* ************************************************************************** */
# define DEFAULT_COLOR	-1
# define COLOR_LOW		0x641D96
# define COLOR_MID  	0x5F34C4
# define COLOR_HIGH 	0x3A5DC2
# define CYAN			0x00E5FF
# define AZURE			0x0099CC
# define MINT			0x66FFCC
# define GREEN			0x00FFD0
# define PURPLE			0x9966FF
# define RED_ORANGE		0xFF4500
# define DARK_ORANGE	0xFF8C00
# define ORANGE			0xFFA500
# define GOLD			0xFFD700
# define TOMATO			0xFF6347

#endif
