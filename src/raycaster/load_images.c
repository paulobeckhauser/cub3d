/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:33:19 by sfrankie          #+#    #+#             */
/*   Updated: 2024/05/29 16:33:21 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/structs.h"
#include "../../incl/textures.h"
#include "../../incl/defines.h"

void load_images(t_game *game)
{
	game->txt_floor = mlx_xpm_file_to_image(game->mlx_ptr, FLOOR, &game->img_x, &game->img_y);
	game->txt_player = mlx_xpm_file_to_image(game->mlx_ptr, PLAYER, &game->img_x, &game->img_y);
	game->txt_wall = mlx_xpm_file_to_image(game->mlx_ptr, WALL, &game->img_x, &game->img_y);
}
