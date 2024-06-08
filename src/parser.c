
#include "../inc/cub3d.h"

int parser(char *str)
{
    t_data data;
    int i;

    i = 0;
    init_vars(&data);
    if (!check_extension(&data, str))
        return(free_variables_error(&data));
    if (!store_cub_file(&data, str))
        return(free_variables_error(&data));
    get_map_elem_info(&data);
    while (data.cub_file[i])
    {
         if (!store_surfaces_colors(data.cub_file[i], &data) || !store_texture_images(data.cub_file[i], &data))
             return(free_variables_error(&data));
        i++;
    }
     if (!check_input_floor_texture_exist(&data))
         return(free_variables_error(&data));
     if (!check_map_content_last_element(&data))
         return(free_variables_error(&data));
     if (!check_walls_in_edges(&data))
         return(free_variables_error(&data));



    if (!new_checker_borders(&data))
        return(free_variables_error(&data));


    store_map_element(&data);


    print_returned_map(&data);


    



    return (0);
}
