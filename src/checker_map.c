

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
    int j;
    int line_map_elem;
    int first_line_map_elem;
    int last_line_map_elem;

    i = 0;
    j = 0;
    line_map_elem =  data->line_start_map_position;
    first_line_map_elem = data->line_start_map_position;
    last_line_map_elem = line_map_elem + data->number_lines_map_element - 1;

    while (line_map_elem <= last_line_map_elem)
    {
//        printf("%s\n", data->cub_file[line_map_elem]);
        line_map_elem++;
    }

    return (true);
}



// bool check_walls_in_edges(t_data *data)
// {

//     int i;
//     int j;
//     int line_map_elem;
//     int first_line_map_elem;
//     int last_line_map_elem;

//     i = 0;
//     j = 0;
//     line_map_elem =  data->line_start_map_position;
//     first_line_map_elem = data->line_start_map_position;
//     last_line_map_elem = line_map_elem + data->number_lines_map_element - 1;
//     while(line_map_elem <= last_line_map_elem)
//     {
//         i = 0;
//         if (line_map_elem == first_line_map_elem)
//         {
//             j = 0;
//             while (data->cub_file[line_map_elem][j])
//             {
//                 if (data->cub_file[line_map_elem][j] != '1' && data->cub_file[line_map_elem][j] == ' ' && data->cub_file[line_map_elem][j] != '\n')
//                 {
//                     i = line_map_elem + 1;
//                     while(data->cub_file[i][j])
//                     {
//                         if (data->cub_file[i][j] == ' ')
//                             i++;
//                         else if (data->cub_file[i][j] == '1')
//                             break;
//                         else
//                         {
//                             printf("WALL NOT BLOCKED\n");
//                             printf("ERROR\n");
//                         }
//                     }

//                 }

//                 else if(data->cub_file[line_map_elem][j] != '1' && data->cub_file[line_map_elem][j] != ' ' && data->cub_file[line_map_elem][j] != '\n')
//                 {
//                     replace_error_message(data, "Input not ");
//                     // return (false);
//                     printf("ERROR\n");
//                 }

//                 j++;
//             }


            
//             printf("First line\n");
//         }



//         if (line_map_elem == last_line_map_elem)
//         {
//             printf("Last line\n");
//         }


//         // printf("%s\n\n\n\n", data->cub_file[line_map_elem]);







//         line_map_elem++;
//     }






    

    // while (data->cub_file[i])
    // {

    //     if (check_map_element(data->cub_file[i]))
    //         printf("%s\n", data->cub_file[i]);
        










    //     i++;
    // }


    // // printf("%d\n", data->number_lines_map_element);

    // printf("%s\n", data->map_element[data->number_lines_map_element - 1]);


    // return (true);


// }
