
#include "../inc/cub3d.h"

int parser(void)
{
    
    t_data data;
    init_vars(&data);


    if (!store_cub_file(&data))
        return(free_variables_error(&data));


    int i = 0;
    while (data.cub_file[i])
    {
        if (!store_surfaces_colors(data.cub_file[i], &data) || !store_texture_images(data.cub_file[i], &data))
            return(free_variables_error(&data));
        i++;
    }


    if (!check_input_exist(&data))
        return(free_variables_error(&data));




    check_map_content_last_element(&data);



    //store_map


    // printf("The current element position is: %d\n", data.element_position);
    // store_map_element(&data);




    store_map_element(&data);







    // int i; 

    // i = 0;

    // while(data.map_element[i])
    // {
    //     printf("%s\n", data.map_element[i]);
    //     i++;
    // }




    // if (data.map_error == true)
    // {
    //     printf("The map has an error\n");

        
    //     return (1);
    // }


    

    return (0);
}