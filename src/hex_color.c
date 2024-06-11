
#include "../inc/cub3d.h"

int rgb_to_hex(int red, int green, int blue)
{
    int hex;

    hex = (red << 16) | (green << 8) | blue;
    hex =  (hex & 0xFFFFFF) | 0x00 << 24;
    return (hex);
}

// colors( red, green, blue)

int store_hex_color(char *line)
{
    char **color_values;
    char **rgb_values;
    int red;
    int green;
    int blue;

    red = 0;
    green = 0;
    blue = 0;
    color_values = NULL;
    rgb_values = NULL;
    color_values = ft_split(line, ' ');

    // printf("%s\n", line);

    // int *color;

    // color = malloc(3 * (sizeof(int)));







    // int k;

    // k = 0;
    // while (color_values[k])
    // {
    //     // printf("%s\n", color_values[k]);
    //     // color[k] = ft_atoi(ft_strtrim(color_values[k], ","));
    //     printf("%s\n", ft_strtrim(color_values[k], ","));

    //     // printf("%d\n\n", k);
    //     k++;
    // }


    red = ft_atoi(ft_strtrim(color_values[1], ","));
    green = ft_atoi(ft_strtrim(color_values[2], ","));
    blue = ft_atoi(ft_strtrim(color_values[3], ","));


    printf("%d\n", red);
    printf("%d\n", red);
    




    // int m; 

    // m = 0;
    // while (color[m])
    // {
    //     printf("%d\n", color[m]);
    //     m++;
    // }
    // rgb_values = ft_split(color_values[1], ',');
    // free_2d_array(color_values);

    // free_2d_array(rgb_values);
    return(rgb_to_hex(red, green, blue));
}
