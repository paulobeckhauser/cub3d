/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:01:21 by sfrankie          #+#    #+#             */
/*   Updated: 2024/05/29 12:51:05 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"
#include "../mlx_linux/mlx.h"

int main(int argc, char **argv)
{
    // t_mlx mlx;
    
    (void)argc;
    (void)argv;


    parser();
    // mlx.mlx_ptr = mlx_init();
    // if (!mlx.mlx_ptr)
    // {
    //     perror("mlx");
    //     return (1);
    // }
    // mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 1000, 800, "cub3d");
    // if (!mlx.win_ptr)
    // {
    //     perror("mlx window");
    //     return (free(mlx.mlx_ptr), 1);
    // }
    // mlx_loop(mlx.mlx_ptr);
    return (0);
}