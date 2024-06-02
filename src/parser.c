
#include "../inc/cub3d.h"

int parser(void)
{
    
    t_data data;

    init_vars(&data);
    if (!store_map(&data))
        return (1);

    // while(1)
    // {

    //     line = get_next_line(fd);
    //     if (!line)
    //     {
    //         free(line);
    //         break;
    //     }

    //     if (!store_surfaces_colors(line, &data) || !store_texture_images(line, &data))
    //     {
    //         free(line);
    //         return (1);
    //     }






    //     free(line);
    // }


    // if (!check_input_exist(&data))
    // {
    //     //free all variables -> TO-DO
    //     return (1);
    // }
    // close(fd);
    return (0);
}
