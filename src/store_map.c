

#include "../../inc/cub3d.h"

bool check_empty_line(char *str)
{
    int i;
    unsigned long count_space_chars;

    count_space_chars = 1;

    i = 0;
    while(str[i])
    {
        if (str[i] == ' ')
            count_space_chars++;
        i++;
    }
    if (count_space_chars == ft_strlen(str))
        return (true);
    return (false);
}

bool check_map_element(char *str)
{
    int i;
    unsigned long count_chars;

    i = 0;
    count_chars = 1;
    while(str[i])
    {
        if (str[i] == '1' || str[i] == '0' || str[i] == ' ' 
                || str[i] == 'N' || str[i] == 'S' || str[i] == 'E' 
                    || str[i] == 'W')
            count_chars++;
        i++;

    }

    if (count_chars == ft_strlen(str))
        return (true);
    return (false);
}


bool size_map_element(t_data *data)
{
    int i;
    int j;
    unsigned long validated_chars_map;
    // int number_lines_map_element;

    data->number_lines_map_element = 0;

    i = 0;
    j = 0;
    validated_chars_map = 1;

    while (data->cub_file[i])
    {
        j = 0;
        validated_chars_map = 1;
        while (data->cub_file[i][j])
        {

            if (data->cub_file[i][j] == '1' || data->cub_file[i][j] == '0' || data->cub_file[i][j] == ' ' 
                || data->cub_file[i][j] == 'N' || data->cub_file[i][j] == 'S' || data->cub_file[i][j] == 'E' 
                    || data->cub_file[i][j] == 'W')
                validated_chars_map++;
            j++;
        }
        if (ft_strlen(data->cub_file[i]) == validated_chars_map && !check_empty_line(data->cub_file[i]))
            data->number_lines_map_element++;

        i++;
    }
    return (true);
}


bool store_map_element(t_data *data)
{
    size_map_element(data);
    
    // printf("NUmber of lines:%d\n", data->number_lines_map_element);
    data->map_element = malloc((data->number_lines_map_element + 1) * sizeof(char *));
    // if (!data->map_element)
    //     return (false)


    int i;
    int j;

    j = 0;

    i = 0;

    while(data->cub_file[i])
    {
        if (check_map_element(data->cub_file[i]) && !(check_empty_line(data->cub_file[i])))
        {
            data->map_element[j] = ft_strdup(data->cub_file[i]);
            j++;
            // printf("%s\n", data->cub_file[i]);
        }
        i++;
    }
    data->map_element[j] = NULL;








    return (true);


    




    
}

