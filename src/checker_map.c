

#include "../inc/cub3d.h"

bool check_map_content_last_element(t_data *data)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(data->cub_file[i])
    {
        if (check_empty_line(data->cub_file[i]))
            i++;
        else if(check_map_element(data->cub_file[i]))
        {
            data->line_start_map_position = i;
            break;
        }
        else
            i++;
    }
    i = data->line_start_map_position;
    while (data->cub_file[i])
    {
        if (!check_map_element(data->cub_file[i]))
        {
            replace_error_message(data, "Map element not in the correct position");
            return(false);
        }
        i++;
    }
    return (true);
}


static bool check_walls_edges_lines(t_data *data, int position)
{
    int i;

    i = 0;
    while(data->cub_file[position][i])
    {
        if (data->cub_file[position][i] == '0')
        {
            replace_error_message(data, "Map not surrounded by walls");
            return (false);
        }
        i++;
    }
    return (true);

}

static bool check_walls_first_column(t_data *data)
{
    int i;
    int line_map_elem;
    int last_line_map_elem;

    i = 0;
    line_map_elem = data->line_start_map_position;
    last_line_map_elem = line_map_elem + data->number_lines_map_element - 1;
    while (line_map_elem <= last_line_map_elem)
    {
        if (data->cub_file[line_map_elem][i] == '0')
        {
            replace_error_message(data, "Map not surrounded by walls");
            return (false);
        }
        line_map_elem++;
    }
    return (true);

}


static int get_last_column_position(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    i = i - 2;
    return (i);
}

static bool check_walls_last_column(t_data *data)
{
    int i;
    int line_map_elem;
    int last_line_map_elem;

    i = 0;
    line_map_elem = data->line_start_map_position;
    last_line_map_elem = line_map_elem + data->number_lines_map_element - 1;
    while (line_map_elem <= last_line_map_elem)
    {
        i = get_last_column_position(data->cub_file[line_map_elem]);
        if (data->cub_file[line_map_elem][i] == '0')
        {
            replace_error_message(data, "Map not surrounded by walls");
            return (false);
        }
        line_map_elem++;
    }
    return (true);


}





bool check_walls_in_edges(t_data *data)
{
    int line_map_elem;
    int first_line_map_elem;
    int last_line_map_elem;

    line_map_elem =  data->line_start_map_position;
    first_line_map_elem = data->line_start_map_position;
    last_line_map_elem = line_map_elem + data->number_lines_map_element - 1;
    while (line_map_elem <= last_line_map_elem)
    {
        if (line_map_elem == first_line_map_elem || line_map_elem == last_line_map_elem)
        {
            if (!check_walls_edges_lines(data, line_map_elem))
                free_variables_error(data);
        }
        line_map_elem++;
    }
    if (!check_walls_first_column(data))
        free_variables_error(data);
    if (!check_walls_last_column(data))
        free_variables_error(data);





    return (true);
}
