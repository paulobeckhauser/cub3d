

#include "../inc/cub3d.h"

bool check_map_content_last_element(t_data *data)
{
    // int i;
    // // int j;
    
    // i = data->number_lines_map - 1;

    // while (i >= 0)
    // {
    //     printf("%s\n", data->cub_file[i]);

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


        


    //     i--;
    // }
    // return (true);


    // int i;

    // i = 0;

    // while(data->cub_file[i])
    // {

    //     printf("%s\n", data->cub_file[i]);
    //     i++;
    // }

    // printf("%d\n", data->number_lines_map);
    // int i;

    // i = data->number_lines_map -1 ;
    // // printf("%d\n", data->number_lines_map_element);

    // while (i >= 0)
    // {
    //     printf("%s\n", data->cub_file[i]);
    //     i--;
    // }

    int i;
    int j;

    i = 0;
    j = 0;
    while(data->cub_file[i])
    {
        // // printf("%s\n", data->cub_file[i]);
        // if (check_empty_line(data->cub_file[i]))
        //     i++;

        // else if (!check_empty_line(data->cub_file[i]))
        // {

        //     // j = 0;

        //     // printf("%s\n", data->cub_file[i]);

        //     while (!check_map_element(data->cub_file[i]))
        //         i++;

        //     break;


            // check_map_element(char *str)

            




            // while(data->cub_file[i][j])
            // {

            //     // if (data->cub_file[i][j] != ' ' && data->cub_file[i][j] != '0' && data->cub_file[i][j] != '1' 
            //     //     && data->cub_file[i][j] != 'N' && data->cub_file[i][j] != 'S' && data->cub_file[i][j] != 'W' 
            //     //         && data->cub_file[i][j] != 'E' && data->cub_file[i][j] != '\n')
            //     //     printf("diff char\n");
            //     printf("%c\n", data->cub_file[i][j]);


            //     j++;
            // }
        // }


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
        // printf("%s\n", data->cub_file[i]);

        if (!check_map_element(data->cub_file[i]))
        {
            // data->map_correct_position = false;
            return(false);
            break;
        }
        i++;
    }

    // data->map_correct_position = true;

    return (true);












    // printf("%d\n", i);


    




    // while ()





}
