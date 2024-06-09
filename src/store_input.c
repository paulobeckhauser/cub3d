

#include "../../inc/cub3d.h"


bool store_surfaces_colors(char *line, t_data *data)
{
    char **array;

    array = ft_split(line, ' ');
    if (!array)
    {
        replace_error_message(data, "Memory allocation failed");
        return (false);
    }

    if (ft_strcmp(array[0], "F") == 0)
    {
        data->f_surf_count++;
		if (!checker_surfaces_colors(data, line, 'F'))
        {
            free(line);
            return(false);
        }
        data->floor_color_exist = true;
        data->floor_color = store_hex_color(line);
    }
    else if (ft_strcmp(array[0], "C") == 0)
    {
        data->c_surf_count++;
		if (!checker_surfaces_colors(data, line, 'C'))
        {
            free(line);
            return(false);
        }
        data->ceiling_color_exist = true;
        data->ceiling_color = store_hex_color(line);
    }
    free_2d_array(array);
    return (true);
}


bool store_texture_images(char *line, t_data *data)
{
    char **array_textures;

    array_textures = NULL;
    array_textures = ft_split(line, ' ');

    if (!array_textures)
    {
         free(array_textures);
         return(false);
	}
    if (ft_strcmp(array_textures[0], "NO") == 0)
    {
        data->north_texture = ft_strdup(array_textures[1]);
        data->n_text_count++;
    }
	if (ft_strcmp(array_textures[0], "SO") == 0)
	{
		data->south_texture = ft_strdup(array_textures[1]);
		data->s_text_count++;
	}
	if (ft_strcmp(array_textures[0], "WE") == 0)
	{
		data->west_texture = ft_strdup(array_textures[1]);
		data->w_text_count++;
	}
	
	if (ft_strcmp(array_textures[0], "EA") == 0)
	{
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
