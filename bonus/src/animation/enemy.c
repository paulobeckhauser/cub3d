/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 23:54:18 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/04 23:54:19 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	animation_enemy_death(t_game *game)
{
	int	j;
	
	j = 0;
	while (j < ENEMY_MAX)
	{
		if (game->data.map_element[game->enemy[j].y][game->enemy[j].x] == '5'
			&& !game->enemy[j].dead)
			update_death_textures(game, j);
		++j;
	}
}

void	update_death_textures(t_game *game, int j)
{
	static long		start_time = 0;
	long			current_time;
	int				blood_frame;
	struct timeval	tv;
	
	if (start_time == 0)
	{
		gettimeofday(&tv, NULL);
		start_time = tv.tv_sec * 1000000 + tv.tv_usec;
	}
	gettimeofday(&tv, NULL);
	current_time = tv.tv_sec * 1000000 + tv.tv_usec;
	blood_frame = (current_time - start_time)
				  / (BLOOD_FRAME_DURATION / BLOOD_FRAMES);
	if (blood_frame < 0)
		blood_frame = 0;
	if (blood_frame >= BLOOD_FRAMES - 1)
	{
		game->enemy[j].texture
				= game->textures.dark_priest_texture[ENEMY_FRAMES - 1];
		game->enemy[j].dead = true;
		start_time = 0;
		return ;
	}
	game->enemy[j].texture = game->textures.blood[blood_frame];
}

void	animation_enemy_cast(t_game *game)
{
	int				j;
	
	j = 0;
	while (j < ENEMY_MAX)
	{
		if (game->enemy[j].visible && !game->enemy[j].dead)
			update_enemy_cast_textures(game, j);
		++j;
	}
}

void	update_enemy_cast_textures(t_game *game, int j)
{
	struct timeval	tv;
	static long		start_time = 0;
	long			current_time;
	int				enemy_frame;
	
	if (start_time == 0)
	{
		gettimeofday(&tv, NULL);
		start_time = tv.tv_sec * 1000000 + tv.tv_usec;
	}
	gettimeofday(&tv, NULL);
	current_time = tv.tv_sec * 1000000 + tv.tv_usec;
	enemy_frame = (current_time - start_time)
				  / (ENEMY_FRAME_DURATION / ENEMY_FRAMES);
	if (enemy_frame > ENEMY_FRAMES - 1 || enemy_frame < 0)
	{
		start_time = 0;
		enemy_frame = 0;
	}
	if (enemy_frame != ENEMY_FRAMES - 1)
		game->enemy[j].texture
				= game->textures.dark_priest_texture[enemy_frame];
	game->enemy[j].visible = false;
	update_hp_status(game, enemy_frame);
}
