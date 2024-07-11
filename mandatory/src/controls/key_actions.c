/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 11:47:25 by sfrankie          #+#    #+#             */
/*   Updated: 2024/05/29 11:47:26 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

int	close_game(t_game *game)
{
    mlx_destroy_window(game->mlx_ptr, game->win_ptr);
    free(game->mlx_ptr);
    exit(0);
}

void    rotate_player_left(t_game *game)
{
	game->ray_main_angle -= 10;
	if (game->ray_main_angle <= 0)
		game->ray_main_angle += 0;
	--game->vec_idx;
	if (game->vec_idx == -1)
		game->vec_idx = 35;
    render_game(game);
}

void    rotate_player_right(t_game *game)
{
	game->ray_main_angle += 10;
	if (game->ray_main_angle >= 360)
		game->ray_main_angle -= 360;
	++game->vec_idx;
	if (game->vec_idx == 36)
		game->vec_idx = 0;
    render_game(game);
}

void    move_player_forward(t_game *game)
{
	game->data->player->x += game->vectors[game->vec_idx].x * SPEED;
	game->data->player->y += game->vectors[game->vec_idx].y * SPEED;
	// if (game->data->player->x < 0 || game->data->player->x > SCREEN_WIDTH
		// || game->data->player->y < 0 || game->data->player->y > SCREEN_HEIGHT)
	// {
		// game->data->player->x -= game->vectors[game->vec_idx].x * SPEED;
		// game->data->player->y -= game->vectors[game->vec_idx].y * SPEED;
		// return ;
	// }
	render_game(game);
}

void    move_player_backward(t_game *game)
{
	game->data->player->x -= game->vectors[game->vec_idx].x * SPEED;
	game->data->player->y -= game->vectors[game->vec_idx].y * SPEED;
	// if (game->data->player->x < 0 || game->data->player->x > SCREEN_WIDTH
		// || game->data->player->y < 0 || game->data->player->y > SCREEN_HEIGHT)
	// {
		// game->data->player->x += game->vectors[game->vec_idx].x * SPEED;
		// game->data->player->y += game->vectors[game->vec_idx].y * SPEED;
		// return ;
	// }
	render_game(game);
}

void    move_player_left(t_game *game)
{
	game->data->player->x += game->vectors[game->vec_idx].y * SPEED;
	game->data->player->y -= game->vectors[game->vec_idx].x * SPEED;
	// if (game->data->player->x < 0 || game->data->player->x > SCREEN_WIDTH
		// || game->data->player->y < 0 || game->data->player->y > SCREEN_HEIGHT)
	// {
		// game->data->player->x -= game->vectors[game->vec_idx].y * SPEED;
		// game->data->player->y += game->vectors[game->vec_idx].x * SPEED;
		// return ;
	// }
	render_game(game);
}

void    move_player_right(t_game *game)
{
	game->data->player->x -= game->vectors[game->vec_idx].y * SPEED;
	game->data->player->y += game->vectors[game->vec_idx].x * SPEED;
	// if (game->data->player->x < 0 || game->data->player->x > SCREEN_WIDTH
		// || game->data->player->y < 0 || game->data->player->y > SCREEN_HEIGHT)
	// {
		// game->data->player->x += game->vectors[game->vec_idx].y * SPEED;
		// game->data->player->y -= game->vectors[game->vec_idx].x * SPEED;
		// return ;
	// }
	render_game(game);
}
