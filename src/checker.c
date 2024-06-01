
#include "../inc/cub3d.h"


char *trim_rgb_input(char *str, char digit)
{
    int count_spaces;
    int i;
    int j;
    char *trimmed_str;

    i = 0;
    j = 0;
    count_spaces = 0;
    trimmed_str = NULL;
    while (str[i])
    {
        if (str[i] == ' ')
            count_spaces++;
        i++;
    }
    trimmed_str = malloc(ft_strlen(str) - count_spaces);
    i = 0;
    while (str[i])
    {
        if (str[i] != ' ' && str[i] != digit)
        {
            trimmed_str[j] = str[i];
            j++;
        }
        i++;
    }
    trimmed_str[j - 1] = '\0';
    return(trimmed_str);
}


bool color_input_exist(char *str, char digit)
{
    int i;

    i = 0;
    while (str[i] == ' ')
        i++;
    if (str[i] == digit && str[i++] && str[i++] == ' ')
        return (true);
    return (false);
}



int size_array(char **array)
{
    int i;

    i = 0;
    while (array[i])
        i++;
    return (i);
}


bool rgb_correct_format(char *str, char digit)
{
    char **rgb_array;
    int i;
    int j;
    char *trimmed_rgb_input;

    trimmed_rgb_input = trim_rgb_input(str, digit);

    rgb_array = ft_split(trimmed_rgb_input, ',');





    i = 0;
    // printf("The size of the array is: %d\n", size_array(rgb_array));
    if (size_array(rgb_array) != 3)
    {
        free_2d_array(rgb_array);
        return (false);
    }
    while (rgb_array[i])
    {
        // printf("The string #%d is: %s\n", i,rgb_array[i]);
        j = 0;
        while (rgb_array[i][j])
        {
            // printf("The iter is #%d: %c\n", i, rgb_array[i][j]);
            if (rgb_array[i][j]!= '0' &&  !ft_isdigit(rgb_array[i][j]))
            {
                // printf("here 1\n");
                free_2d_array(rgb_array);
                return (false);
            }
            j++;
        }

        // printf("The string #%d is: %s\n", i,rgb_array[i]);
        if (ft_atoi(rgb_array[i]) < 0 || ft_atoi(rgb_array[i]) > 255)
        {         
            // printf("here2\n");
            free_2d_array(rgb_array);
            return (false);
        }

        i++;
    }
    free_2d_array(rgb_array);
    free(trimmed_rgb_input);
    return (true);
}

bool checker_surfaces_colors(char *str, char digit)
{

    if (!color_input_exist(str, digit))
    {
        // perror("Input for floor color does not exist\n");
        ft_putstr_fd("Input for surfaces color(floor or ceiling) does not exist or is in wrong format\n", 2);
        return(false);
    }
    
    if (!rgb_correct_format(str, digit))
    {
        ft_putstr_fd("RGB input for surfaces color(floor or ceiling) is incorrect\n", 2);
        return (false);
        // perror("RGB input for floor color is incorrect\n");
    }

    return (true);











}