
#include "../inc/cub3d.h"

int parser(void)
{
    
    t_data data;
    init_vars(&data);


    if (!store_map(&data))
        return(free_variables_error(&data));


    int i = 0;
    while (data.map[i])
    {
        if (!store_surfaces_colors(data.map[i], &data) || !store_texture_images(data.map[i], &data))
            return(free_variables_error(&data));
        i++;
    }


    if (!check_input_exist(&data))
        return(free_variables_error(&data));


    
    // check_map_last_element


    

    return (0);
}
