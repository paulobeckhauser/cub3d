/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_test_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:57:55 by sfrankie          #+#    #+#             */
/*   Updated: 2024/05/29 15:57:56 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/raycaster_test.h"
#include "../../incl/standard_libs.h"

void init_test_map(t_game *game)
{
	int i = 0;
	while (i < 10)
	{
		game->map_line[i].idx = i;
		if (i == 4)
			game->map_line[i].sprites = "1000N00001";
		else if (i == 0 || i == 9)
			game->map_line[i].sprites = "1111111111";
		else
			game->map_line[i].sprites = "1000000001";
		game->map_line[i].len = 10;
		if (i == 0)
		{
			game->map_line[i].prev = NULL;
			game->map_line[i].next = &game->map_line[i + 1];
		}
		else if (i == 9)
		{
			game->map_line[i].prev = &game->map_line[i - 1];
			game->map_line[i].next = NULL;
		}
		else
		{
			game->map_line[i].prev = &game->map_line[i - 1];
			game->map_line[i].next = &game->map_line[i + 1];
		}
		++i;
	}
	game->map_line_count = 10;
}