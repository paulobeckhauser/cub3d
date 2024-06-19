

#include "../../inc/cub3d.h"



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
