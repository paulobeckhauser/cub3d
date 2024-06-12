/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:16:09 by pabeckha          #+#    #+#             */
/*   Updated: 2024/06/12 18:57:08 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"


void position_start_map_element(t_data *data)
{
    int i;
    int j;
    size_t count_map_line;

    i = 0;
    j = 0;
    count_map_line = 0;
    while(data->cub_file[i])
    {
        j = 0;
        count_map_line = 0;
        while (data->cub_file[i][j])
        {
            while (data->cub_file[i][j] == ' ')
            {
    
                j++;
            }

            if (data->cub_file[i][j] == '1' || data->cub_file[i][j] == '0'
                || data->cub_file[i][j] == ' ' || data->cub_file[i][j] == 'N'
                || data->cub_file[i][j] == 'S' || data->cub_file[i][j] == 'W'
                || data->cub_file[i][j] == 'E')
                count_map_line++;
            j++;  
        }
        if (count_map_line == ft_strlen(data->cub_file[i]) 
            && ft_strcmp(data->cub_file[i], "") != 0)
        {
            data->line_start_map_position = i;
            break;
        }
        i++;
    }
}

// void position_end_map_element(t_data *data)
// {
    
// }


// bool check_empty_line_map(t_data *data)
// {
//     int i;

//     i = data->line_start_map_position;

//     while(data->cub_file[i])
//     {
//         if (ft_strcmp(data->cub_file[i], "") == 0)
//         {
//             replace_error_message(data, "Map has empty lines");
//         }
//         i++;
//     }
//     return (true);
// }

bool store_map(t_data *data)
{
    position_start_map_element(data);



    int i;

    i = data->line_start_map_position;

    while(data->cub_file[i])
    {
        printf("%s\n", data->cub_file[i]);
        i++;
    }

    return (true); 
}
