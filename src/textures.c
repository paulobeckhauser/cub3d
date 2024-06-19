
#include "../../inc/cub3d.h"



bool check_xpm_extension(t_data *data, char *str)
{
    char **array;
    int i;

    array = NULL;

    array = ft_split(str, '.');
    i = size_array(array) - 1;

    if (array[i])
    {
        if (ft_strcmp(array[i], "xpm") != 0)
        {
            replace_error_message(data, "One or more texture not in .xpm format");
            return (false);
        }
    }

    return (true);

}

bool check_input_texture(t_data *data)
{  
    if(data->text_count_n > 1)
    {
		replace_error_message(data, "More than 1 input for North Texture");
		return (false);
	}
	else if (data->text_count_n < 1)
	{
		replace_error_message(data,
			"No input for North Texture or in wrong format");
		return (false);
	}
    else if (data->s_text_count > 1)
	{
		replace_error_message(data, "More than 1 input for South Texture");
		return (false);
	}
    else if (data->s_text_count < 1)
	{
		replace_error_message(data,
			"No input for South Texture or in wrong format");
		return (false);
	}
        else if (data->w_text_count > 1)
	{
		replace_error_message(data, "More than 1 input for West Texture");
		return (false);
	}
    else if (data->w_text_count < 1)
	{
		replace_error_message(data,
			"No input for West Texture or in wrong format");
		return (false);
	}
    else if (data->e_text_count > 1)
	{
		replace_error_message(data, "More than 1 input for East Texture");
		return (false);
	}
    else if (data->e_text_count < 1)
	{
		replace_error_message(data,
			"No input for East Texture or in wrong format");
		return (false);
	}

    return(true);


}


bool store_textures(t_data *data)
{
    
    int i;
    char **array;


    i = 0;
    array = NULL;
    while(data->cub_file[i])
    {

        array = ft_split(data->cub_file[i], ' ');
        if (!array)
		{
			replace_error_message(data, "Memory allocation failed");
			return (false);
		}


        // printf("%d\n", size_array(array));
        // if (size_array(array) != 2)
		// {
		// 	replace_error_message(data, "Texture in wrong format");
		// 	return (false);
		// }

        if (array[0])
        {
            if (ft_strcmp(array[0], "NO") == 0)
            {
                if (size_array(array) != 2)
                {
                    replace_error_message(data, "Texture in wrong format");
                    return (false);
                }
                data->text_count_n++;
                if (!array[1])
                {
                    replace_error_message(data, "No input for North Texture");
			        return (false); 
                }
                else if (!check_xpm_extension(data, array[1]))
                    return (false);
                else
                    data->north_texture = ft_strdup(array[1]);
            }
            
            
            else if (ft_strcmp(array[0], "SO") == 0)
            {
                if (size_array(array) != 2)
                {
                    replace_error_message(data, "Texture in wrong format");
                    return (false);
                }
                data->s_text_count++;

                if (!array[1])
                {
                    replace_error_message(data, "No input for South Texture");
			        return (false); 
                }
                else if (!check_xpm_extension(data, array[1]))
                    return (false);
                else
                    data->south_texture = ft_strdup(array[1]);
            }
            
            
            else if (ft_strcmp(array[0], "WE") == 0)
            {
                if (size_array(array) != 2)
                {
                    replace_error_message(data, "Texture in wrong format");
                    return (false);
                }
                data->w_text_count++;

                if (!array[1])
                {
                    replace_error_message(data, "No input for West Texture");
			        return (false); 
                }
                else if (!check_xpm_extension(data, array[1]))
                    return (false);
                else
                    data->west_texture = ft_strdup(array[1]);
            }
            else if (ft_strcmp(array[0], "EA") == 0)
            {
                if (size_array(array) != 2)
                {
                    replace_error_message(data, "Texture in wrong format");
                    return (false);
                }
                data->e_text_count++;

                if (!array[1])
                 {
                    replace_error_message(data, "No input for East Texture");
			        return (false); 
                }
                else if (!check_xpm_extension(data, array[1]))
                    return (false);
                else
                    data->east_texture = ft_strdup(array[1]);
            }

        }

        i++;
        free_2d_array(array);
    }

    if (!check_input_texture(data))
        return (false);

    return (true);
}
