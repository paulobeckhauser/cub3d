

#include "../inc/cub3d.h"

void check_map_content_last_element(t_data *data)
{
    int i;
    // int j;
    
    i = data->number_lines_map - 1;

    while (i >= 0)
    {
        printf("%s\n", data->cub_file[i]);

        // j = 0;

        // while (data->map[i][j])
        // {
        //     if (data->map[i][j] != '1' || data->map[i][j] != '0' 
        //         || data->map[i][j] != 'N' || data->map[i][j] != 'S'
        //             || data->map[i][j] != 'E' || data->map[i][j] != 'W' || data->map[i][j] != ' ')
        //         {
        //             data->map_error = true;
        //             data->map_message = ft_strdup("Map content is not the last element\n");
        //             break;
        //         }
        //     if (data->map_error == true)
        //         break;
        //     j++;
        // }


        


        i--;
    }
    // return (true);
}
