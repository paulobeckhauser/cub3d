/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:01:21 by sfrankie          #+#    #+#             */
/*   Updated: 2024/05/28 19:01:22 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/raycaster.h"
#include "../incl/cub3d.h"

int main(int argc, char **argv)
{
    t_game      game;

	init_game(&game);
	load_images(&game);
    init_hooks(&game);
    draw_map(&game);
    (void)argc;
    (void)argv;
    mlx_loop(game.mlx_ptr);
    free(game.map);
    return (0);
}
