/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:33:19 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/05 01:21:14 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	load_images_from_dir(t_game *game)
{
	load_images_wall(game);
	load_images_minimap(game);
	load_images_desert_eagle(game);
	load_images_shotgun_1_2(game);
	load_images_shotgun_2_2(game);
	load_images_door(game);
	load_images_hp(game);
	load_images_blood_1_3(game);
	load_images_blood_2_3(game);
	load_images_blood_3_3(game);
	load_images_menu(game);
	load_images_avatar(game);
	load_images_enemy_1_2(game);
	load_images_enemy_2_2(game);
}
