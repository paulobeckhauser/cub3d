/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:01:21 by sfrankie          #+#    #+#             */
/*   Updated: 2024/07/07 15:52:10 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_data		data;

	parser(argv[1], &data);
	init_game(&game, &data);
	init_image(&image, &game);
	game.image = &image;
	game.vectors = vectors;
	game.data = &data;
	// mark_player(&game);
	printf("%i\n", data.player->x);
	printf("%i\n", data.player->y);
	printf("%c\n", data.player->direction);
	calc_dir_vectors(&game);
	load_images_from_dir(&game);
	init_hooks(&game);
	render_game(&game);
	(void)argc;
	mlx_loop(game.mlx_ptr);
	mlx_destroy_image(game.mlx_ptr, image.img);
	image.img = NULL;
    return (0);
}
