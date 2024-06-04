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

int main(int argc, char **argv)
{
    t_game      game;

    game.mlx_ptr = mlx_init();
    if (!game.mlx_ptr)
    {
        perror("mlx");
        return (1);
    }
    game.win_ptr = mlx_new_window(game.mlx_ptr, 640, 640, "cub3d");
    if (!game.win_ptr)
    {
        perror("mlx window");
        return (free(game.mlx_ptr), 1);
    }
    game.map = init_test_map();
    game.img_x = 0;
    game.img_y = 0;
    init_hooks(&game);
    load_images(&game);
    game.player_marked = 0;
    game.ray_angle = 270;
    mark_player(&game);
    mark_main_ray((&game));
    draw_map(&game);
    (void)argc;
    (void)argv;
    mlx_loop(game.mlx_ptr);
    free(game.map);
    return (0);
}
