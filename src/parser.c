
#include "../inc/cub3d.h"

int parser(char *str)
{
    t_data data;

    data.player = (t_player *)malloc(sizeof(t_player));

    init_vars(&data);
    if (!check_extension(&data, str))
        return(free_variables_error(&data));
    if (!store_cub_file(&data, str))
        return(free_variables_error(&data));

    get_map_elem_info(&data);


    if (!check_floor_texture_format(&data))
        return(free_variables_error(&data));
     if (!check_input_floor_texture_exist(&data))
         return(free_variables_error(&data));
     if (!check_map_content_last_element(&data))
         return(free_variables_error(&data));
     if (!check_walls_in_edges(&data))
         return(free_variables_error(&data));
    if (!new_checker_borders(&data))
        return(free_variables_error(&data));


    if (!check_player(&data))
        return(free_variables_error(&data));



    store_map_element(&data);


    print_returned_map(&data);


    return (0);
}
