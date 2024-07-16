/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:09:30 by pabeckha          #+#    #+#             */
/*   Updated: 2024/07/15 20:36:00 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

bool	flood_fill(char **map, int x, int y, char target)
{
	size_t	new_y;
	bool	up;
	bool	down;
	bool	right;
	bool	left;

	new_y = (size_t)y;
	if (x < 0 || x >= size_array(map) || y < 0 || new_y >= ft_strlen(map[x]))
		return (false);
	if (map[x][y] == ' ')
		return (false);
	if (map[x][y] != target || map[x][y] == 'X')
		return (true);
	map[x][y] = 'X';
	down = flood_fill(map, x + 1, y, target);
	up = flood_fill(map, x - 1, y, target);
	right = flood_fill(map, x, y + 1, target);
	left = flood_fill(map, x, y - 1, target);
	return (up && down && right && left);
}

bool	apply_ffill_algo(char **map_backup, t_data *data)
{
	bool	all_surrounded;
	int		i;
	int		j;

	all_surrounded = true;
	i = 0;
	j = 0;
	while (map_backup[i])
	{
		j = 0;
		while (map_backup[i][j])
		{
			if (map_backup[i][j] == '0')
			{
				if (!flood_fill(map_backup, i, j, '0'))
				{
					replace_error_message(data, "Map not surrounded");
					all_surrounded = false;
				}
			}
			j++;
		}
		i++;
	}
	return (all_surrounded);
}
