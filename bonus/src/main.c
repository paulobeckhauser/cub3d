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

void    init_image(t_image *image, t_game *game)
{
	(void)game;
	image->img = mlx_new_image(game->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	image->bits_per_pixel = 32;
	image->line_length = SCREEN_WIDTH;
	image->endian = 0;
	image->data = (int *)mlx_get_data_addr(image->img, &image->bits_per_pixel, &image->line_length, &image->endian);
}

int main(int argc, char **argv)
{
    t_game      game;
	t_image     image;
	t_vectors   vectors[72];

    init_game(&game);
    init_image(&image, &game);
    game.image = &image;
	game.vectors = vectors;
	calc_dir_vectors(&game);
    load_images_from_dir(&game);
    init_hooks(&game);
    render_map(&game);
	(void)argc;
	(void)argv;
	mlx_mouse_hide(game.mlx_ptr, game.win_ptr);
	mlx_loop(game.mlx_ptr);
	free(game.map);
	mlx_destroy_image(game.mlx_ptr, image.img);
	image.img = NULL;
    return (0);
}