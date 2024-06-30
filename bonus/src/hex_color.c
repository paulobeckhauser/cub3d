/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 00:12:17 by sfrankie          #+#    #+#             */
/*   Updated: 2024/05/30 00:12:22 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int rgb_to_hex(int red, int green, int blue)
{
	int hex;

	hex = (red << 16) | (green << 8) | blue;
	hex =  (hex & 0xFFFFFF) | 0x00 << 24;
	return (hex);
}

int store_hex_color(char *line)
{
	char	**color_values;
	char	**rgb_values;
	int		red;
	int		green;
	int		blue;

	color_values = NULL;
	rgb_values = NULL;
	color_values = ft_split(line, ' ');
	rgb_values = ft_split(color_values[1], ',');
	free_2d_array(color_values);
	red = ft_atoi(rgb_values[0]);
	green = ft_atoi(rgb_values[1]);
	blue = ft_atoi(rgb_values[2]);
	free_2d_array(rgb_values);
	return(rgb_to_hex(red, green, blue));
}