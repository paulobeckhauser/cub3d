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
	image->img = mlx_new_image(game->mlx_ptr, (int)SCREEN_WIDTH, (int)SCREEN_HEIGHT);
	image->bits_per_pixel = 32;
	image->line_length = (int)SCREEN_WIDTH;
	image->endian = 0;
	image->data = (int *)mlx_get_data_addr(image->img, &image->bits_per_pixel, &image->line_length, &image->endian);
	image->created = 0;
}

int main(int argc, char **argv)
{
    t_game      game;
	t_image     image;
	t_vectors   vectors[36];

    init_game(&game);
    init_image(&image, &game);
    game.image = &image;
	game.vectors = vectors;
	calc_dir_vectors(&game);
    load_images_from_dir(&game);
    init_hooks(&game);
    draw_map(&game);
	(void)argc;
	(void)argv;
	mlx_loop(game.mlx_ptr);
	free(game.map);
	mlx_destroy_image(game.mlx_ptr, image.img);
	image.img = NULL;
    return (0);
}
