/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:11:37 by sfrankie          #+#    #+#             */
/*   Updated: 2024/05/29 12:11:43 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/controls.h"

void	init_hooks(t_mlx *mlx)
{
    mlx_hook(mlx->win_ptr, 02, 1L<<0, keypress, mlx);
    mlx_hook(mlx->win_ptr, 17, 0, close_game, mlx);
}