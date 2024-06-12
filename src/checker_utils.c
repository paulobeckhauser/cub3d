

#include "../../inc/cub3d.h"

int size_array(char **array)
{
    int i;

    i = 0;
    while (array[i])
        i++;
    return (i);
}


bool check_floor_texture_format(t_data *data)
{
    int i;

    i = 0;
    while (data->cub_file[i])
    {
        // if (!store_surfaces_colors(data->cub_file[i], data))
        //     return(false);
            // printf("here");
        // if (!store_texture_images(data->cub_file[i], data))
        //     printf("ok");
    //     if (!store_surfaces_colors(data->cub_file[i], data)
    //         || !store_texture_images(data->cub_file[i], data))
    //         return(false);
        // printf("%s\n", data->cub_file[i]);
        i++;
    }
    // if (data->n_text_count != 1 
	// 		|| data->s_text_count != 1 
	// 	|| data->w_text_count != 1 
	// 	|| data->e_text_count != 1)
	// {
	// 	replace_error_message(data, "More than one Texture");
	// 	return(false);
	// }
    // if (data->f_surf_count != 1 
	// 		|| data->c_surf_count != 1)
	// {
	// 	replace_error_message(data, "More than one Surface");
	// 	return(false);
	// }
    return (true);
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


bool check_extension(t_data *data, char *str, char *extension)
{
    int i;
    char **array;

    array = NULL;
    array = ft_split(str, '.');
    i = size_array(array) - 1;

    if(size_array(array) == 1 || ft_strcmp(array[i], extension) != 0)
    {
        replace_error_message(data, "Map is not a '.cub' file");
        free_2d_array(array);
        return (false);
    }
    free_2d_array(array);
    return (true);
}
