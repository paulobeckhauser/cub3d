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

#include "../incl/controls.h"
#include "../incl/standard_libs.h"
#include "../incl/textures.h"
#include "../incl/raycaster_test.h"
#include "../incl/structs.h"

int main(int argc, char **argv)
{
    t_line      lines[10];
    t_game      game;

    game.mlx_ptr = mlx_init();
    if (!game.mlx_ptr)
    {
        perror("mlx");
        return (1);
    }
    game.win_ptr = mlx_new_window(game.mlx_ptr, 639, 639, "cub3d");
    if (!game.win_ptr)
    {
        perror("mlx window");
        return (free(game.mlx_ptr), 1);
    }
    game.map_line = lines;
    init_test_map(&game);
    game.img_x = 0;
    game.img_y = 0;
    init_hooks(&game);
    load_images(&game);
    game.player_marked = 0;
    game.player_angle = 0;
    draw_map(&game);
    (void)argc;
    (void)argv;
    mlx_loop(game.mlx_ptr);
    return (0);
}
