/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_macros.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:59:15 by migarrid          #+#    #+#             */
/*   Updated: 2025/05/23 23:28:08 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_MACROS_H
# define FDF_MACROS_H

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


/* ************************************************************************** */
/*                          Key Bindings                                      */
/* ************************************************************************** */
# define ESC_KEY		65307
# define KEY_LEFT		65361
# define KEY_RIGHT		65363
# define KEY_DOWN		65364
# define KEY_UP			65362
# define KEY_PLUS		61
# define KEY_MINUS		45

/* ************************************************************************** */
/*                          Window Settings                                   */
/* ************************************************************************** */
# define WIN_WIDTH		1920
# define WIN_HEIGHT		1080
# define DEFAULT_ANG 	0.523599

#endif
