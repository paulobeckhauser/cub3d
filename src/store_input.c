

#include "../../inc/cub3d.h"


bool store_surfaces_colors(char *line, t_data *data)
{
    int i;

    i = 0;

    while (line[i] == ' ')
        i++;
    if (line[i] == 'F')
    {
        if (!checker_surfaces_colors(line, 'F'))
        {
            free(line);
            return(false);
        }
        data->floor_color_exist = true;
        data->floor_color = store_hex_color(line);
    }
    
    else if (line[i] == 'C')
    {
        if (!checker_surfaces_colors(line, 'C'))
        {
            free(line);
            return(false);
        }
        data->ceiling_color_exist = true;
        data->ceiling_color = store_hex_color(line);
    }
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
        data->north_texture = ft_strdup(array_textures[1]);

    if (ft_strcmp(array_textures[0], "SO") == 0)
        data->south_texture = ft_strdup(array_textures[1]);
    if (ft_strcmp(array_textures[0], "WE") == 0)
        data->west_texture = ft_strdup(array_textures[1]);
    if (ft_strcmp(array_textures[0], "EA") == 0)
        data->east_texture = ft_strdup(array_textures[1]);

    free_2d_array(array_textures);

    return (true);
}
