/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:01:21 by sfrankie          #+#    #+#             */
/*   Updated: 2024/07/21 17:43:12 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	init_image(t_image *image, t_game *game)
{
	image->img = mlx_new_image(game->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	image->bits_per_pixel = 32;
	image->line_length = SCREEN_WIDTH;
	image->endian = 0;
	image->data = (int *)mlx_get_data_addr(image->img, &image->bits_per_pixel,
			&image->line_length, &image->endian);
}

static int	print_error_wrong_args(void)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Incorrect number of arguments\n", 2);
	ft_putstr_fd(RESET, 2);
	return (1);
}

static void	game_implementation(t_data *data)
{
	t_game		game;
	t_image		image;
	t_vectors	vectors[120];

	init_game(&game, data);
	init_image(&image, &game);
	game.image = &image;
	game.vectors = vectors;
	game.data = data;
	calc_dir_vectors(&game);
	load_images_from_dir(&game);
	init_hooks(&game);
	render_game(&game);
	mlx_loop(game.mlx_ptr);
	mlx_destroy_image(game.mlx_ptr, image.img);
	image.img = NULL;
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		status;

	status = 0;
	if (argc == 2 && argv[1] && ft_strcmp(argv[1], "") != 0)
	{
		status = parser(argv[1], &data);
		if (status != 0)
			return (status);
		game_implementation(&data);
	}
	else
		return (print_error_wrong_args());
	return (status);
}
