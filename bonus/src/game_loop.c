/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:11:37 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/05 00:50:17 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

void	init_hooks(t_game *game)
{
	mlx_hook(game->win_ptr, 02, 1L << 0, keypress, game);
	mlx_hook(game->win_ptr, 3, 1L << 1, keyrelease, game);
	mlx_hook(game->win_ptr, 6, 1L << 6, mouse_move, game);
	mlx_hook(game->win_ptr, 17, 0, close_game, game);
	mlx_mouse_hook(game->win_ptr, mouse_press, game);
	mlx_loop_hook(game->mlx_ptr, loop_hook, game);
}

int	loop_hook(t_game *game)
{
	if (game->keys[ESC])
		close_game(game);
	if (game->main_menu && !game->won_game)
		action_main_menu(game);
	else if (!game->main_menu && !game->won_game)
		action_game(game);
	render_game(game);
	animation(game);
	return (0);
}
