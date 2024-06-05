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

#include "../../incl/raycaster.h"

void load_images_from_dir(t_game *game)
{
	game->background = mlx_xpm_file_to_image(game->mlx_ptr, BACKGROUND, &game->img_x, &game->img_y);
}