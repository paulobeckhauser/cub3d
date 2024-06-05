#include "../inc/cub3d.h"

void init_vars(t_data *data)
{
    data->cub_file = NULL;
    data->north_texture = NULL;
    data->south_texture = NULL;
    data->west_texture = NULL;
    data->east_texture = NULL;
    data->number_lines_map = 0;
    data->map_error = false;
    data->floor_color_exist = false;
    data->ceiling_color_exist = false;
    data->map_error_message = NULL;
    data->element_position = 0;
    data->number_lines_map_element = 0;
    data->map_element = NULL;
    data->line_start_map_position = 0;

    data->map_correct_position = false;

    
    
}