#include "../inc/cub3d.h"

void init_vars(t_data *data)
{
    data->north_texture = NULL;
    data->south_texture = NULL;
    data->west_texture = NULL;
    data->east_texture = NULL;
    data->map_error = false;
    data->floor_color_exist = false;
    data->ceiling_color_exist = false;
}