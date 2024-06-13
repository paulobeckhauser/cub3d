/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:16:09 by pabeckha          #+#    #+#             */
/*   Updated: 2024/06/13 12:42:53 by pabeckha         ###   ########.fr       */
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
            || str[i] == 'E')
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
        if (check_if_map_element(data->cub_file[i]) && !check_if_empty_line(data->cub_file[i]))
        {
            data->line_start_map_position = i;
            break;
        }
        i++;
    }
}

void store_last_line_map_element(t_data *data)
{
    int i;

    i = data->line_start_map_position;
    while(data->cub_file[i])
    {
        if (check_if_empty_line(data->cub_file[i]))
        {
            data->line_end_map_position = i - 1;
            break;
        }
        i++;
        
    }
    
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

bool store_map(t_data *data)
{
    // int i;

    
    store_first_line_map_element(data);
    store_last_line_map_element(data);

    if (!store_map_element(data))
    {
        return (false);
    }

    

    int i;

    i = 0;
    while(data->map_element[i])
    {
        printf("%s\n", data->map_element[i]);
        i++;
    }

    return (true); 
}
