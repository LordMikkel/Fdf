/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 00:58:39 by migarrid          #+#    #+#             */
/*   Updated: 2025/06/09 21:50:06 by migarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	check_4d_mode(const char *av, t_map *map)
{
	if (ft_strcmp(av, "pentachoron") == 0)
	{
		printf("4d mode activated\n");
		map->object = PENTACHORON;
		return (1);
	}
	else if (ft_strcmp(av, "tesseract") == 0)
	{
		printf("4d mode activated\n");
		map->object = TESSERACT;
		return (1);
	}
	else if (ft_strcmp(av, "hexacosicoron") == 0)
	{
		printf("4d mode activated\n");
		map->object = HEXACOSICORON;
		return (1);
	}
	return (0);
}

int	init_4d(const char *av, t_map *map)
{
	map->type = OBJECT_4D;
	if (map->object == PENTACHORON)
	{
		if (!init_pentachoron(map))
			return (ft_putstr_fd(ERR_MEM, STDERR), 0);
		printf("Succes init pentachoron\n");
	}
	else if (map->object == TESSERACT)
	{
		if (!init_tesseract(map))
			return (ft_putstr_fd(ERR_MEM, STDERR), 0);
		printf("Succes init tesseract\n");
	}
	else if (map->object == HEXACOSICORON)
	{
		if (!init_hexacosicoron(map))
			return (ft_putstr_fd(ERR_MEM, STDERR), 0);
		printf("Succes init tesseract\n");
	}
	return (1);
}

int	init_pentachoron(t_map *map)
{
	map->height = 1;
	map->width = 5;
	map->points = ft_calloc(1, sizeof(t_point *));
	if (!map->points)
		return (0);
	map->points[0] = ft_calloc(5, sizeof(t_point));
	if (!map->points[0])
		return (0);
	map->points[0][0] = (t_point){1, 1, 1, -1, DARK_ORANGE};
	map->points[0][1] = (t_point){1, -1, -1, -1, DARK_ORANGE};
	map->points[0][2] = (t_point){-1, 1, -1, 1, ORANGE};
	map->points[0][3] = (t_point){-1, -1, 1, 1, GOLD};
	map->points[0][4] = (t_point){0, 0, 0, -2, TOMATO};
	return (1);
}

int	init_tesseract(t_map *map)
{
	map->height = 1;
	map->width = 16;
	map->points = ft_calloc(1, sizeof(t_point *));
	if (!map->points)
		return (0);
	map->points[0] = ft_calloc(16, sizeof(t_point));
	if (!map->points[0])
		return (0);
	map->points[0][0] = (t_point){-1, -1, -1, -1, PURPLE};
	map->points[0][1] = (t_point){-1, -1, -1, 1, GREEN};
	map->points[0][2] = (t_point){-1, -1, 1, -1, PURPLE};
	map->points[0][3] = (t_point){-1, -1, 1, 1, GREEN};
	map->points[0][4] = (t_point){-1, 1, -1, -1, PURPLE};
	map->points[0][5] = (t_point){-1, 1, -1, 1, MINT};
	map->points[0][6] = (t_point){-1, 1, 1, -1, AZURE};
	map->points[0][7] = (t_point){-1, 1, 1, 1, MINT};
	map->points[0][8] = (t_point){1, -1, -1, -1, AZURE};
	map->points[0][9] = (t_point){1, -1, -1, 1, MINT};
	map->points[0][10] = (t_point){1, -1, 1, -1, AZURE};
	map->points[0][11] = (t_point){1, -1, 1, 1, GREEN};
	map->points[0][12] = (t_point){1, 1, -1, -1, PURPLE};
	map->points[0][13] = (t_point){1, 1, -1, 1, GREEN};
	map->points[0][14] = (t_point){1, 1, 1, -1, PURPLE};
	map->points[0][15] = (t_point){1, 1, 1, 1, GREEN};
	return (1);
}

int	init_hexacosicoron(t_map *map)
{
	ft_putstr_fd("Descomenta y no veas la norminette", STDERR);
	return (0);
}

// int init_hexacosicoron(t_map *map)
// {
//     map->height = 1;
//     map->width = 600;
//     map->points = ft_calloc(1, sizeof(t_point *));
//     if (!map->points)
//         return (0);
//     map->points[0] = ft_calloc(600, sizeof(t_point));
//     if (!map->points[0])
//         return (0);

//     // Proporción áurea
//     double phi = 1.618033988749895; // (1 + sqrt(5)) / 2
//     double inv_phi = 0.618033988749895; // 1 / phi

//     // Normalizamos los valores para que estén en [-1, 1]
//     double norm = 2.0 / (1.0 + phi);

//     // Grupo 1: Permutaciones de (±1, ±1, ±1, ±1) - 16 puntos
//     int idx = 0;
//     int signs1[4] = {-1, -1, -1, -1};
//     for (int s1 = 0; s1 < 2; s1++) {
//         for (int s2 = 0; s2 < 2; s2++) {
//             for (int s3 = 0; s3 < 2; s3++) {
//                 for (int s4 = 0; s4 < 2; s4++) {
//                     signs1[0] = (s1 == 0) ? -1 : 1;
//                     signs1[1] = (s2 == 0) ? -1 : 1;
//                     signs1[2] = (s3 == 0) ? -1 : 1;
//                     signs1[3] = (s4 == 0) ? -1 : 1;
//                     map->points[0][idx] = (t_point){
//                         signs1[0] * norm,
//                         signs1[1] * norm,
//                         signs1[2] * norm,
//                         signs1[3] * norm,
//                         PURPLE
//                     };
//                     idx++;
//                 }
//             }
//         }
//     }

//     // Grupo 2: Permutaciones pares de (0, ±1/φ, ±1, ±φ) - 96 puntos
//     double coords2[4][4] = {{0, inv_phi, 1, phi}, {0, inv_phi, 1, -phi},
// 							{0, inv_phi, -1, phi}, {0, inv_phi, -1, -phi}};
//     int perms2[24][4] = {
//         {0,1,2,3}, {0,1,3,2}, {0,2,1,3}, {0,2,3,1}, {0,3,1,2}, {0,3,2,1},
//         {1,0,2,3}, {1,0,3,2}, {1,2,0,3}, {1,2,3,0}, {1,3,0,2}, {1,3,2,0},
//         {2,0,1,3}, {2,0,3,1}, {2,1,0,3}, {2,1,3,0}, {2,3,0,1}, {2,3,1,0},
//         {3,0,1,2}, {3,0,2,1}, {3,1,0,2}, {3,1,2,0}, {3,2,0,1}, {3,2,1,0}
//     };

//     for (int c = 0; c < 4; c++) {
//         for (int p = 0; p < 24; p++) {
//             map->points[0][idx] = (t_point){
//                 coords2[c][perms2[p][0]] * norm,
//                 coords2[c][perms2[p][1]] * norm,
//                 coords2[c][perms2[p][2]] * norm,
//                 coords2[c][perms2[p][3]] * norm,
//                 GREEN
//             };
//             idx++;
//         }
//     }

//     // Grupo 3: Permutaciones pares de (±1/φ, 0, ±φ, ±1) - 96 puntos
//     double coords3[4][4] = {{inv_phi, 0, phi, 1}, {inv_phi, 0, phi, -1},
// 							{inv_phi, 0, -phi, 1}, {inv_phi, 0, -phi, -1}};
//     for (int c = 0; c < 4; c++) {
//         for (int p = 0; p < 24; p++) {
//             map->points[0][idx] = (t_point){
//                 coords3[c][perms2[p][0]] * norm,
//                 coords3[c][perms2[p][1]] * norm,
//                 coords3[c][perms2[p][2]] * norm,
//                 coords3[c][perms2[p][3]] * norm,
//                 MINT
//             };
//             idx++;
//         }
//     }

//     // Grupo 4: Permutaciones pares de (±1, ±φ, 0, ±1/φ) - 96 puntos
//     double coords4[4][4] = {{1, phi, 0, inv_phi}, {1, phi, 0, -inv_phi},
// 							{1, -phi, 0, inv_phi}, {1, -phi, 0, -inv_phi}};
//     for (int c = 0; c < 4; c++) {
//         for (int p = 0; p < 24; p++) {
//             map->points[0][idx] = (t_point){
//                 coords4[c][perms2[p][0]] * norm,
//                 coords4[c][perms2[p][1]] * norm,
//                 coords4[c][perms2[p][2]] * norm,
//                 coords4[c][perms2[p][3]] * norm,
//                 AZURE
//             };
//             idx++;
//         }
//     }

//     // Grupo 5: Permutaciones pares de (±φ, ±1, ±1/φ, 0) - 96 puntos
//     double coords5[4][4] = {{phi, 1, inv_phi, 0}, {phi, 1, -inv_phi, 0},
// 							{phi, -1, inv_phi, 0}, {phi, -1, -inv_phi, 0}};
//     for (int c = 0; c < 4; c++) {
//         for (int p = 0; p < 24; p++) {
//             map->points[0][idx] = (t_point){
//                 coords5[c][perms2[p][0]] * norm,
//                 coords5[c][perms2[p][1]] * norm,
//                 coords5[c][perms2[p][2]] * norm,
//                 coords5[c][perms2[p][3]] * norm,
//                 GOLD
//             };
//             idx++;
//         }
//     }

//     // Grupo 6: Permutaciones de (±1/φ, ±1/φ, ±1/φ, ±φ) - 32 puntos
//     double base6[4] = {inv_phi, inv_phi, inv_phi, phi};
//     int signs6[4];
//     for (int s1 = 0; s1 < 2; s1++) {
//         for (int s2 = 0; s2 < 2; s2++) {
//             for (int s3 = 0; s3 < 2; s3++) {
//                 for (int s4 = 0; s4 < 2; s4++) {
//                     signs6[0] = (s1 == 0) ? -1 : 1;
//                     signs6[1] = (s2 == 0) ? -1 : 1;
//                     signs6[2] = (s3 == 0) ? -1 : 1;
//                     signs6[3] = (s4 == 0) ? -1 : 1;

//                     // Permutación (0,1,2,3)
//                     map->points[0][idx] = (t_point){
//                         signs6[0] * base6[0] * norm,
//                         signs6[1] * base6[1] * norm,
//                         signs6[2] * base6[2] * norm,
//                         signs6[3] * base6[3] * norm,
//                         TOMATO
//                     };
//                     idx++;

//                     // Permutación (3,2,1,0)
//                     map->points[0][idx] = (t_point){
//                         signs6[3] * base6[3] * norm,
//                         signs6[2] * base6[2] * norm,
//                         signs6[1] * base6[1] * norm,
//                         signs6[0] * base6[0] * norm,
//                         TOMATO
//                     };
//                     idx++;
//                 }
//             }
//         }
//     }

//     // Grupo 7: Permutaciones de (±1/φ, ±1/φ, ±φ, ±1/φ) - 32 puntos
//     double base7[4] = {inv_phi, inv_phi, phi, inv_phi};
//     for (int s1 = 0; s1 < 2; s1++) {
//         for (int s2 = 0; s2 < 2; s2++) {
//             for (int s3 = 0; s3 < 2; s3++) {
//                 for (int s4 = 0; s4 < 2; s4++) {
//                     signs6[0] = (s1 == 0) ? -1 : 1;
//                     signs6[1] = (s2 == 0) ? -1 : 1;
//                     signs6[2] = (s3 == 0) ? -1 : 1;
//                     signs6[3] = (s4 == 0) ? -1 : 1;

//                     // Permutación (0,1,2,3)
//                     map->points[0][idx] = (t_point){
//                         signs6[0] * base7[0] * norm,
//                         signs6[1] * base7[1] * norm,
//                         signs6[2] * base7[2] * norm,
//                         signs6[3] * base7[3] * norm,
//                         COLOR_HIGH
//                     };
//                     idx++;

//                     // Permutación (2,3,0,1)
//                     map->points[0][idx] = (t_point){
//                         signs6[2] * base7[2] * norm,
//                         signs6[3] * base7[3] * norm,
//                         signs6[0] * base7[0] * norm,
//                         signs6[1] * base7[1] * norm,
//                         COLOR_HIGH
//                     };
//                     idx++;
//                 }
//             }
//         }
//     }

//     // Grupo 8: Permutaciones de (±1/φ, ±φ, ±1/φ, ±1/φ) - 32 puntos
//     double base8[4] = {inv_phi, phi, inv_phi, inv_phi};
//     for (int s1 = 0; s1 < 2; s1++) {
//         for (int s2 = 0; s2 < 2; s2++) {
//             for (int s3 = 0; s3 < 2; s3++) {
//                 for (int s4 = 0; s4 < 2; s4++) {
//                     signs6[0] = (s1 == 0) ? -1 : 1;
//                     signs6[1] = (s2 == 0) ? -1 : 1;
//                     signs6[2] = (s3 == 0) ? -1 : 1;
//                     signs6[3] = (s4 == 0) ? -1 : 1;

//                     // Permutación (0,1,2,3)
//                     map->points[0][idx] = (t_point){
//                         signs6[0] * base8[0] * norm,
//                         signs6[1] * base8[1] * norm,
//                         signs6[2] * base8[2] * norm,
//                         signs6[3] * base8[3] * norm,
//                         CYAN
//                     };
//                     idx++;

//                     // Permutación (1,0,3,2)
//                     map->points[0][idx] = (t_point){
//                         signs6[1] * base8[1] * norm,
//                         signs6[0] * base8[0] * norm,
//                         signs6[3] * base8[3] * norm,
//                         signs6[2] * base8[2] * norm,
//                         CYAN
//                     };
//                     idx++;
//                 }
//             }
//         }
//     }

//     // Grupo 9: Permutaciones de (±φ, ±1/φ, ±1/φ, ±1/φ) - 32 puntos
//     double base9[4] = {phi, inv_phi, inv_phi, inv_phi};
//     for (int s1 = 0; s1 < 2; s1++) {
//         for (int s2 = 0; s2 < 2; s2++) {
//             for (int s3 = 0; s3 < 2; s3++) {
//                 for (int s4 = 0; s4 < 2; s4++) {
//                     signs6[0] = (s1 == 0) ? -1 : 1;
//                     signs6[1] = (s2 == 0) ? -1 : 1;
//                     signs6[2] = (s3 == 0) ? -1 : 1;
//                     signs6[3] = (s4 == 0) ? -1 : 1;

//                     // Permutación (0,1,2,3)
//                     map->points[0][idx] = (t_point){
//                         signs6[0] * base9[0] * norm,
//                         signs6[1] * base9[1] * norm,
//                         signs6[2] * base9[2] * norm,
//                         signs6[3] * base9[3] * norm,
//                         COLOR_LOW
//                     };
//                     idx++;

//                     // Permutación (0,2,3,1)
//                     map->points[0][idx] = (t_point){
//                         signs6[0] * base9[0] * norm,
//                         signs6[2] * base9[2] * norm,
//                         signs6[3] * base9[3] * norm,
//                         signs6[1] * base9[1] * norm,
//                         COLOR_LOW
//                     };
//                     idx++;
//                 }
//             }
//         }
//     }
//     return (1);
// }
