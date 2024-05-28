/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:01:21 by sfrankie          #+#    #+#             */
/*   Updated: 2024/05/28 19:01:22 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

int main(int argc, char **argv)
{
    t_mlx mlx;

    (void)argc;
    (void)argv;
    mlx.mlx_ptr = mlx_init();
    if (!mlx.mlx_ptr)
    {
        perror("mlx");
        return (1);
    }
    mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 1000, 800, "cub3d");
    if (!mlx.win_ptr)
    {
        perror("mlx window");
        return (free(mlx.mlx_ptr), 1);
    }
    mlx_loop(mlx.mlx_ptr);
    return (0);
}