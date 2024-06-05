

#include "../../inc/cub3d.h"

int size_array(char **array)
{
    int i;

    i = 0;
    while (array[i])
        i++;
    return (i);
}



bool check_input_floor_texture_exist(t_data *data)
{
    if (!data->floor_color_exist || !data->ceiling_color_exist)
    {
        replace_error_message(data, "Input for surfaces color(floor or ceiling) does not exist or is in wrong format");
        return(false);
    }
    if (!data->north_texture || !data->south_texture || !data->west_texture || !data->east_texture)
    {
        replace_error_message(data, "Input for texture(north, south, west or east) does not exist or is in wrong format");
        return(false);
    }
    return (true);
}
