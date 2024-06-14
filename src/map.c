/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:16:09 by pabeckha          #+#    #+#             */
/*   Updated: 2024/06/14 17:42:15 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"


bool check_if_map_element(char *str)
{
    int i;
    
    i = 0;
    while(str[i])
    {
        if (str[i] == '1' || str[i] == '0' || str[i] == ' '
        || str[i] == 'N' || str[i] == 'S' || str[i] == 'W'
            || str[i] == 'E' || (str[i] >= 9 && str[i] <= 13))
            i++;
        else
            return (false);
    }
    return (true);
}

bool check_if_empty_line(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if (str[i] == ' ')
            i++;
        else
            return (false);
    }
    return (true);
}


void store_first_line_map_element(t_data *data)
{
    int i;

    i = 0;
    while(data->cub_file[i])
    {
        if (check_if_map_element(data->cub_file[i]) 
            && !check_if_empty_line(data->cub_file[i]))
        {
            // printf("%s\n", data->cub_file[i]);
            data->line_start_map_position = i;
            // printf("%d\n", i);
            break;
        }
        i++;
    }
}

void store_last_line_map_element(t_data *data)
{
    int i;

    i = data->line_start_map_position;
    // printf("%d\n", i);
    while(data->cub_file[i])
    {
        // printf("%s\n", data->cub_file[i]);
        if (check_if_empty_line(data->cub_file[i]))
        {
            data->line_end_map_position = i - 1;
            // printf("%d\n", data->line_end_map_position);
            break;
        }
        i++;
        
    }
    data->line_end_map_position = i - 1;
    // printf("%d\n", data->line_end_map_position);
    
}

bool store_map_element(t_data *data)
{

    int lines_map;
    int i;
    int j;
    
    i = data->line_start_map_position;
    lines_map = data->line_end_map_position - data->line_start_map_position + 1;


    data->map_element = malloc((lines_map + 1) * sizeof(char *));
    if (!data->map_element)
    {
        replace_error_message(data, "Memory allocation failed");
        return (false);
    }

    j = 0;

    while (i <= data->line_end_map_position)
    {
        data->map_element[j] = ft_strdup(data->cub_file[i]);
        i++;
        j++;
    }
    data->map_element[j] = NULL;



    return (true);
}


bool check_map_last_element(t_data *data)
{
    int i;
    int j;

    j = 0;
    i = data->line_end_map_position + 1;
    while (data->cub_file[i])
    {
        j = 0;
        while (data->cub_file[i][j])
        {
            if (data->cub_file[i][j] != ' ')
            {
                replace_error_message(data, "Map element in wrong format");
                return (false);
            }
            j++;
        }
        i++;
    }
    return (true);
}


bool check_map_element_input(t_data *data)
{
    int i;
    int j;

    j = 0;
    i = data->line_start_map_position + 1;

    while(data->cub_file[i])
    {
        j = 0;
        while(data->cub_file[i][j])
        {
            if (data->cub_file[i][j] != '0' && data->cub_file[i][j] != '1'
                && data->cub_file[i][j] != ' ' && data->cub_file[i][j] != 'N'
                && data->cub_file[i][j] != 'S' && data->cub_file[i][j] != 'E'
                && data->cub_file[i][j] != 'W' && (data->cub_file[i][j] < 9 
                || data->cub_file[i][j] > 13))
            {
                // printf("The char is: %c\n", data->cub_file[i][j]);
                replace_error_message(data, "Map element in wrong format");
                return (false);
            }
            j++;
        }
        i++;
    }
    return (true);
}

// bool check_wall(t_data *data)
// {
    
// }

bool store_map(t_data *data)
{
   
    store_first_line_map_element(data);
    store_last_line_map_element(data);

    if (!store_map_element(data))
        return(false);

    if (!check_map_last_element(data))
        return (false);

    if (!check_map_element_input(data))
        return (false);
    
    // if (!store_map_element(data) || !check_map_last_element(data)
    //     || !check_map_element_input(data))
    //     return (false);

    return (true); 
}
