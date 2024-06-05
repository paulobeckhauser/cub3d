

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



bool check_walls_in_edges(t_data *data)
{

    int i;
    int last_line;

    i = 0;

    last_line = data->number_lines_map_element - 1;


    

    // while (data->map_element[i])
    // {
    //     printf("%s\n", data->map_element[i]);









    //     i++;
    // }


    // // printf("%d\n", data->number_lines_map_element);

    // printf("%s\n", data->map_element[data->number_lines_map_element - 1]);


    return (true);


}
