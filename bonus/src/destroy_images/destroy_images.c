/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:33:19 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/05 01:21:14 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	destroy_images(t_game *game)
{
	destroy_images_enemy(game);
	destroy_images_blood(game);
	destroy_images_guns(game);
	destroy_images_obstructions(game);
	destroy_images_ui(game);
}
