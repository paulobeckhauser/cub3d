/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:11:37 by sfrankie          #+#    #+#             */
/*   Updated: 2024/07/31 12:54:19 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	init_hooks(t_game *game)
{
	mlx_hook(game->win_ptr, 02, 1L << 0, keypress, game);
	mlx_hook(game->win_ptr, 3, 1L << 1, keyrelease, game);
	mlx_hook(game->win_ptr, 6, 1L << 6, mouse_move, game);
	mlx_hook(game->win_ptr, 17, 0, close_game, game);
	mlx_mouse_hook(game->win_ptr, mouse_press, game);
	mlx_loop_hook(game->mlx_ptr, loop_hook, game);
}
