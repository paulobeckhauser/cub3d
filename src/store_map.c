

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
    {
        return (true);
    }
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


void store_player_info(t_data *data, char *str, int i)
{
    int j;

    j = 0;

    while (str[j])
    {
        if (check_player_dir(str[j]))
        {
            data->player->direction = str[j];
            data->player->x = i - 1;
            data->player->y = j;
        }
        j++;
    }


}



void replace_player_for_floor(t_data *data, int j)
{
    int g;

    g = 0;
    while (data->map_element[j][g])
    {
        if (check_player_dir(data->map_element[j][g]))
            data->map_element[j][g] = '0';
        g++;
    }
}

// bool store_map_element(t_data *data)
// {

//     int i;
//     int j;
//     int count_line;
//     int g;

//     data->map_element = malloc((data->number_lines_map_element + 1) * sizeof(char *));

//     j = 0;

//     i = 0;
//     g = 0;
//     count_line = 0;
//     while(data->cub_file[i])
//     {

//         if (check_map_element(data->cub_file[i]) && !(check_empty_line(data->cub_file[i])))
//         {
//             count_line++;
//             store_player_info(data, data->cub_file[i], count_line);
//             data->map_element[j] = ft_strdup(data->cub_file[i]);
//             replace_player_for_floor(data, j);
//             j++;
//         }
//         i++;
//     }
//     data->map_element[j] =  NULL;
//     return (true);
// }

