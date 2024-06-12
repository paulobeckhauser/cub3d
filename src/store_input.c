

#include "../../inc/cub3d.h"


// bool store_surfaces_colors(char *line, t_data *data)
// {
//     char **array;
//     (void)data;
//     (void)line;

//     array = ft_split(line, ' ');
//     if (!array)
//     {
//         replace_error_message(data, "Memory allocation failed");
//         return (false);
//     }

//     int k;

//     k = 0;
//     while (array[k])
//     {
//         printf("%s\n", array[k]);
//         k++;
//     }


//     printf("\n\n\n\n\n");

//     if (array[0] && ft_strcmp(array[0], "F") == 0)
//     {
//         data->f_surf_count++;
// 		if (!checker_surfaces_colors(data, line, 'F'))
//         {
//             free(line);
//             return(false);
//         }
//         data->floor_color_exist = true;
//         // printf("%s\n", line);
//         data->floor_color = store_hex_color(line);
//     }
//     // else if (array[0] && ft_strcmp(array[0], "C") == 0)
//     // {
//     //     data->c_surf_count++;
// 	// 	if (!checker_surfaces_colors(data, line, 'C'))
//     //     {
//     //         free(line);
//     //         return(false);
//     //     }
//     //     data->ceiling_color_exist = true;
//     //     data->ceiling_color = store_hex_color(line);
//     // }
//     free_2d_array(array);
//     return (true);
// }


// bool check_xpm_extension(char **array)
// {
//     int last_element_array;
//     int last_element_new_array;
//     char **new_array;

//     last_element_array = size_array(array) - 1;

//     new_array = ft_split(array[last_element_array], '.');
//     last_element_new_array = size_array(new_array) - 1;


//     // int k;

//     // k = 0;
//     // while (array[k])
//     // {
//     //     printf("%s\n", array[k]);
//     //     k++;
//     // }
//     // // int k;

//     // k = 0;
//     // while (new_array[k])
//     // {
//     //     printf("%s\n", new_array[k]);
//     //     k++;
//     // }
//     // int a;

//     // a = ft_strcmp(new_array[last_element_new_array], "xpm");

//     // printf("%s", new_array[last_element_new_array]);
//     // printf("xpm");

//     // printf("%d\n", a);

//     // if (ft_strcmp(new_array[last_element_new_array], "xpm\n") == 0)
//         // printf("there is xpm\n");

//     // printf("%s", new_array[last_element_new_array]);

//     // if (size_array(new_array) > 1
//     //     && ft_strcmp(new_array[last_element_new_array], "xpm") == 0)
//     //     return (true);

//     if (size_array(new_array) > 1 &&
//         ft_strcmp(new_array[last_element_new_array], "xpm") == 0)
//         return (true);
//         // printf("is xpm\n");

//     return (false);
//     // return (true);


// }





bool store_texture_images(char *line, t_data *data)
{
    char **array_textures;
    int k;
    k = 0;

    array_textures = NULL;
    array_textures = ft_split(line, ' ');

    if (!array_textures)
    {
         free(array_textures);
         return(false);
	}





    if (ft_strcmp(array_textures[0], "NO") == 0)
    {
        // printf("%s\n", array_textures[0]);
        k = 0;

        while (array_textures[k])
        {
            // printf("%s\n", array_textures[k]);
            k++;
        }
        // if (!check_xpm_extension(array_textures))
        // {
        //     replace_error_message(data, "No 'xpm' file in Textures");
        //     return (false);
        // }
        data->north_texture = ft_strdup(array_textures[1]);




        data->n_text_count++;
    }
	if (ft_strcmp(array_textures[0], "SO") == 0)
	{
        // printf("%s\n", array_textures[0]);
        // k = 0;

        // while (array_textures[k])
        // {
        //     printf("%s\n", array_textures[k]);
        //     k++;
        // }
        // if (!check_xpm_extension(array_textures))
        // {
        //     replace_error_message(data, "No 'xpm' file in Textures");
        //     return (false);
        // }
		data->south_texture = ft_strdup(array_textures[1]);
		data->s_text_count++;
	}
	if (ft_strcmp(array_textures[0], "WE") == 0)
	{
        // printf("%s\n", array_textures[0]);
        // k = 0;

        // while (array_textures[k])
        // {
        //     printf("%s\n", array_textures[k]);
        //     k++;
        // }

        // if (!check_xpm_extension(array_textures))
        // {
        //     replace_error_message(data, "No 'xpm' file in Textures");
        //     return (false);
        // }
		data->west_texture = ft_strdup(array_textures[1]);
		data->w_text_count++;
	}
	
	if (ft_strcmp(array_textures[0], "EA") == 0)
	{
        // printf("%s\n", array_textures[0]);
        // if (!check_xpm_extension(array_textures))
        // {
        //     replace_error_message(data, "No 'xpm' file in Textures");
        //     return (false);
        // }
		data->east_texture = ft_strdup(array_textures[1]);
		data->e_text_count++;
	}
	free_2d_array(array_textures);


    // if (!check_extension(data, data->north_texture, "xpm"))
    // //     || !check_extension(data, data->south_texture, "xpm")
    // //     || !check_extension(data, data->west_texture, "xpm")
    // //     || !check_extension(data, data->east_texture, "xpm"))
    //     {
    //         replace_error_message(data, "Texture not in xpm format");
    //         return (false);
    //     }


    return (true);
}
