

#include "../inc/cub3d.h"

bool check_map_content_last_element(t_data *data)
{
    int i;

    i = 0;
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
        if (data->cub_file[position][i] == '0' 
            || check_player_dir(data->cub_file[position][i]))
        {
            replace_error_message(data, "Map not surrounded by walls");
            return (false);
        }
        i++;
    }
    return (true);

}



static bool check_spaces_edges_lines(t_data *data, int position)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while(data->cub_file[position][i])
    {
        if (data->cub_file[position][i] == ' ')
        {
//            //replace_error_message(data, "Map not surrounded by walls");
//            //return (false);
            j = position;
            while(data->cub_file[j][i])
            {
                if (data->cub_file[j][i] == ' ')
                    j++;
                else if(data->cub_file[j][i] == '1')
                    break;
                else
                {
                    replace_error_message(data, "Map not surrounded by walls");
                    return (false);
                }
            }
             replace_error_message(data, "Map not surrounded by walls");
             return (false);
//
//            // printf("There is a mistake\n");
        }
        i++;
    }
//    (void)check_spaces_edges_lines(data, 2);

    (void)data;
    (void)position;
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
        i = 0;
        if (data->cub_file[line_map_elem][i] == '0' 
            || check_player_dir(data->cub_file[line_map_elem][i]))
        {
            replace_error_message(data, "Map not surrounded by walls");
            return (false);
        }
        else if(data->cub_file[line_map_elem][i] == ' ')
        {
            while(data->cub_file[line_map_elem][i])
            {
                if (data->cub_file[line_map_elem][i] == ' ')
                    i++;
                else if(data->cub_file[line_map_elem][i] == '1')
                    break;
                else
                {
                    replace_error_message(data, "Map not surrounded by walls");
                    return (false);
                }
            }
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
        if (data->cub_file[line_map_elem][i] == '0' 
            || check_player_dir(data->cub_file[line_map_elem][i]))
        {
            replace_error_message(data, "Map not surrounded by walls");
            return (false);
        }
        else if(data->cub_file[line_map_elem][i] == ' ')
        {
            while(data->cub_file[line_map_elem][i])
            {
                if (data->cub_file[line_map_elem][i] == ' ')
                    i++;
                else if(data->cub_file[line_map_elem][i] == '1')
                    break;
                else
                {
                    replace_error_message(data, "Map not surrounded by walls");
                    return (false);
                }
            }
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

    int i;

    i = 0;

    line_map_elem =  data->line_start_map_position;
    first_line_map_elem = data->line_start_map_position;
    last_line_map_elem = line_map_elem + data->number_lines_map_element - 1;
    while (line_map_elem <= last_line_map_elem)
    {
        if (line_map_elem == first_line_map_elem || line_map_elem == last_line_map_elem)
        {
            if (!check_walls_edges_lines(data, line_map_elem))
                free_variables_error(data);
//
//
//
//            (void)check_spaces_edges_lines(data, first_line_map_elem);
            if (!check_spaces_edges_lines(data, first_line_map_elem))
                free_variables_error(data);
//
//
//
//
//
        }
        line_map_elem++;
    }
//    (void)check_walls_edges_lines(data, 2);
//    (void)check_spaces_edges_lines(data, 2);
//    (void)check_walls_first_column(data);
//    (void)check_walls_last_column(data);
    if (!check_walls_first_column(data))
        free_variables_error(data);
    if (!check_walls_last_column(data))
        free_variables_error(data);








    return (true);
}



bool is_first_column(char *str, int position)
{
    int i;

    i = 0;
    while(str[i] == ' ')
        i++;
    if (i == position)
        return(true);
    return (false);
}


bool is_last_column(char *str, int position)
{
    int i;

    i = ft_strlen(str) - 1;

    while(str[i] == ' ' || str[i] == '\n')
        i--;
    if (i == position)
        return(true);
    return (false);
}


bool new_checker_borders(t_data *data)
{

    int i;
    int line_map_elem;
    int first_line_map_elem;
    int last_line_map_elem;

//    int j;
//
//    j= 0;
    i = 0;
    line_map_elem =  data->line_start_map_position;
    first_line_map_elem = data->line_start_map_position;
    last_line_map_elem = line_map_elem + data->number_lines_map_element - 1;

//    i = line_map_elem;
    while(data->cub_file[line_map_elem])
    {

        if (line_map_elem != first_line_map_elem
            && line_map_elem != last_line_map_elem)
        {
            i = 0;
            while(data->cub_file[line_map_elem][i])
            {

                if (!is_first_column(data->cub_file[line_map_elem], i) &&
                    !is_last_column(data->cub_file[line_map_elem], i))
                {
                    // up
                    if ( data->cub_file[line_map_elem - 1]
                         && data->cub_file[line_map_elem - 1][i] == ' ' &&
                         data->cub_file[line_map_elem][i] != '1'
                         && data->cub_file[line_map_elem][i] != '\n'
                         && data->cub_file[line_map_elem][i] != ' ')
                    {
                        replace_error_message(data, "Map not surrounded by walls");
                        return (false);
                    }
                    // right
                    if (data->cub_file[line_map_elem][i + 1]
                        && data->cub_file[line_map_elem][i + 1] == ' ' &&
                        data->cub_file[line_map_elem][i] != '1'
                        && data->cub_file[line_map_elem][i] != '\n'
                        && data->cub_file[line_map_elem][i] != ' ')
                    {
                        replace_error_message(data, "Map not surrounded by walls");
                        return (false);
                    }
                    //left
                    if (data->cub_file[line_map_elem][i - 1]
                        && data->cub_file[line_map_elem][i - 1] == ' ' &&
                        data->cub_file[line_map_elem][i] != '1'
                        && data->cub_file[line_map_elem][i] != '\n'
                        && data->cub_file[line_map_elem][i] != ' ')
                    {
                        replace_error_message(data, "Map not surrounded by walls");
                        return (false);
                    }
                    //down
                    if ( data->cub_file[line_map_elem + 1]
                            && data->cub_file[line_map_elem + 1][i] == ' ' &&
                            data->cub_file[line_map_elem][i] != '1'
                            && data->cub_file[line_map_elem][i] != '\n'
                            && data->cub_file[line_map_elem][i] != ' ')
                        {
                            replace_error_message(data, "Map not surrounded by walls");
                            return (false);
                        }
                }
                i++;
            }
        }
        line_map_elem++;
    }
    return (true);
}


void print_returned_map(t_data *data)
{
    // PRINT TEXTURES;

    printf("\n\033[4mThe textures are:\033[0m\n\n");
    printf("North: %s\n", data->north_texture);
    printf("South %s\n", data->south_texture);
    printf("West %s\n", data->west_texture);
    printf("East %s\n", data->east_texture);

    printf("\n\n");

    printf("\033[4mThe Colors are:\033[0m\n\n");
    printf("Floor color: %x\n", data->floor_color);
    printf("Ceiling color: %x\n", data->ceiling_color);

    printf("\n\n");

    printf("\033[4mThe map element is:\033[0m\n\n");




    int k = 0;

    while (data->map_element[k])
    {
        printf("%s", data->map_element[k]);
        k++;
    }

    printf("\nThe direction of the player is: %c\n", data->player->direction);

    printf("The position is: (%d, %d)\n", data->player->x, data->player->y);
}

bool check_player_dir(char c)
{
    char *str_dir;
    int i;

    i = 0;

    str_dir = "NSWE";

    while(str_dir[i])
    {
        if (str_dir[i] == c)
            return (true);
        i++;
    }
    return(false);

}



bool check_player(t_data *data)
{
    int i;
    int line_map_elem;
    int first_line_map_elem;
    int last_line_map_elem;
    int count_player;

    i = 0;
    count_player = 0;
    line_map_elem =  data->line_start_map_position;
    first_line_map_elem = data->line_start_map_position;
    last_line_map_elem = line_map_elem + data->number_lines_map_element - 1;
    while(line_map_elem <= last_line_map_elem)
    {
        i = 0;
        while(data->cub_file[line_map_elem][i])
        {
        if (check_player_dir(data->cub_file[line_map_elem][i]))
                count_player++;
            i++;
        }
        line_map_elem++;
    }
    if (count_player == 0)
    {
        replace_error_message(data, "No player in map element");
        return(false);
    }
    else if (count_player > 1)
    {
        replace_error_message(data, "More than one player in map element");
        return(false);
    }

    return (true);
}









bool check_empty_line_map_element (t_data *data)
{
    int i;
    int line_map_elem;
    int first_line_map_elem;
    int last_line_map_elem;
    int count_player;

    i = 0;
    count_player = 0;
    line_map_elem =  data->line_start_map_position;
    first_line_map_elem = data->line_start_map_position;
    last_line_map_elem = line_map_elem + data->number_lines_map_element - 1; 


    while (line_map_elem <= last_line_map_elem)
    {
        // printf("%s\n", data->cub_file[line_map_elem]);

        if (check_empty_line(data->cub_file[line_map_elem]))
        {
            replace_error_message(data, "Map element separated by line of spaces");
            return (false);
        }
        line_map_elem++;
    }








    return (true);
}
