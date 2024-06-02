

#include "../../inc/cub3d.h"

int size_array(char **array)
{
    int i;

    i = 0;
    while (array[i])
        i++;
    return (i);
}



bool check_input_exist(t_data *data)
{
    if (!data->floor_color_exist || !data->ceiling_color_exist)
    {
        ft_putstr_fd("Error\n", 2);
        ft_putstr_fd("Input for surfaces color(floor or ceiling) does not exist or is in wrong format\n", 2);
        return(false);
    }
    if (!data->north_texture || !data->south_texture || !data->west_texture || !data->east_texture)
    {
        ft_putstr_fd("Error\n", 2);
        ft_putstr_fd("Input for texture(north, south, west or east) does not exist or is in wrong format\n", 2);
        return(false);
    }
    return (true);
}
