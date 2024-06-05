/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:01:21 by sfrankie          #+#    #+#             */
/*   Updated: 2024/06/05 18:03:14 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
// #include "../mlx_linux/mlx.h"

// static void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }


// static int rgb_to_hex(int red, int green, int blue)
// {
//     return ((red << 16) | (green << 8) | blue);
// }


int main(int argc, char **argv)
{
    // t_mlx mlx;
    

    // t_image img;
    
    // (void)argv;
    // (void)argc;

    if (argc == 2)
        return (parser(argv[1]));
    // parser("maps/example_.cub");
    
    else
    {
        ft_putstr_fd("Incorrect number of arguments\n", 2);
        return (1);
    }


    
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

    // img.img = mlx_new_image(mlx.mlx_ptr, 1920, 1080);

    // img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);

    

    // int x = 100;

    // int y = 50;


    // int red;
    // int green;
    // int blue;
    
    // red = ft_atoi("220");
    // green = ft_atoi("100");
    // blue = ft_atoi("0");

    // printf("%d\n", red);
    // printf("%d\n", green);
    // printf("%d\n", blue);


    // int test;

    // test = rgb_to_hex(red, green, blue);


    // printf("%X\n", test);

    // int a;

    // a = (test & 0xFFFFFF) | 0x00 << 24;


    // printf("%d\n", a);
    // printf("%X\n", a);

    // // char *test;

    // // test = "DC6400"

    // while (y < 200)
    // {
    //     // my_mlx_pixel_put(&img, x, y, 0x00FF0000);
    //     my_mlx_pixel_put(&img, 300, y, 0x00DC6400);
    //     my_mlx_pixel_put(&img, x, y, a);
    //     my_mlx_pixel_put(&img, 10, y, a);
    //     my_mlx_pixel_put(&img, 20, y, 0x00DC6400);
    //     y++;
    // }
    
    

    // // my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
    // // my_mlx_pixel_put(&img, 5, 6, 0x00FF0000);
    // // my_mlx_pixel_put(&img, 5, 7, 0x00FF0000);
    // // my_mlx_pixel_put(&img, 5, 8, 0x00FF0000);
    // // my_mlx_pixel_put(&img, 5, 9, 0x00FF0000);
    // // my_mlx_pixel_put(&img, 5, 10, 0x00FF0000);
    // // my_mlx_pixel_put(&img, 5, 11, 0x00FF0000);
    // // my_mlx_pixel_put(&img, 5, 12, 0x00FF0000);
    // // my_mlx_pixel_put(&img, 5, 13, 0x00FF0000);
    // // my_mlx_pixel_put(&img, 5, 14, 0x00FF0000);
    // // my_mlx_pixel_put(&img, 5, 15, 0x00FF0000);
    // // my_mlx_pixel_put(&img, 5, 16, 0x00FF0000);

    // // my_mlx_pixel_put(&img, 5, 17, 0x00FF0000);
    
    // mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.img, 0, 0);
    
    // mlx_loop(mlx.mlx_ptr);
    // return (0);
}