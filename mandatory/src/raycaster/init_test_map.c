/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_test_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:57:55 by sfrankie          #+#    #+#             */
/*   Updated: 2024/07/07 15:27:25 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

char	**init_test_map()
{
	char	**map;
	int i;
	char *map_data[] = {
			"1111111111",
			"1000000001",
			"1000000001",
			"1000000001",
			"1111011111",
			"1000000001",
			"1000000001",
			"1000000001",
			"1N00000001",
			"1111111111"
	};
	
	map = malloc(sizeof(char*) * 10);
	if (map == NULL)
	{
		perror("malloc");
		exit(1);
	}
	
	for(i = 0; i < 10; i++) {
		map[i] = malloc(sizeof(char) * 11); // 10 for characters and 1 for null terminator
		if (map[i] == NULL)
		{
			perror("malloc");
			exit(1);
		}
		strcpy(map[i], map_data[i]);
	}
	
	return (map);
}
