/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 23:54:18 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/07 19:02:42 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

/* Function: animation_enemy_death
 * -------------------------------
 * Animates the death of enemies in the game.
 * 
 * game: A pointer to the game structure containing all game information and state.
 * 
 * Iterates through all enemies in the game. If an enemy is marked as not dead and is
 * located on a map element representing an enemy, it triggers the death animation for
 * that enemy by calling update_death_textures.
 */
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

/* Function: update_death_textures
 * -------------------------------
 * Updates the textures to animate enemy death.
 * 
 * game: A pointer to the game structure.
 * j: The index of the enemy in the game's enemy array.
 * 
 * Uses a static start_time to track the beginning of the animation. Calculates the
 * current frame of the death animation based on the elapsed time. Once the animation
 * reaches the last frame, it marks the enemy as dead and resets the start time.
 */
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

/* Function: animation_enemy_cast
 * ------------------------------
 * Animates the casting action of enemies in the game.
 * 
 * game: A pointer to the game structure containing all game information and state.
 * 
 * Iterates through all enemies in the game. If an enemy is visible and not dead, it
 * triggers the casting animation for that enemy by calling update_enemy_cast_textures.
 */
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

/* Function: update_enemy_cast_textures
 * ------------------------------------
 * Updates the textures to animate enemy casting.
 * 
 * game: A pointer to the game structure.
 * j: The index of the enemy in the game's enemy array.
 * 
 * Uses a static start_time to track the beginning of the animation. Calculates the
 * current frame of the casting animation based on the elapsed time. Once the animation
 * reaches the last frame, it hides the enemy and updates the health status of the player
 * if necessary.
 */
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
