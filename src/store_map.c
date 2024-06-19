

#include "../../inc/cub3d.h"

bool check_empty_line(char *str)
{
    int i;
    unsigned long count_space_chars;

    count_space_chars = 1;

    i = 0;
    while(str[i])
    {
        if (str[i] == ' ')
            count_space_chars++;
        i++;
    }
    if (count_space_chars == ft_strlen(str))
    {
        return (true);
    }
    return (false);
}

// bool check_map_element(char *str)
// {
//     int i;
//     unsigned long count_chars;

//     i = 0;
//     count_chars = 1;
//     while(str[i])
//     {
//         if (str[i] == '1' || str[i] == '0' || str[i] == ' ' 
//                 || str[i] == 'N' || str[i] == 'S' || str[i] == 'E' 
//                     || str[i] == 'W')
//             count_chars++;
//         i++;

//     }

//     if (count_chars == ft_strlen(str))
//         return (true);
//     return (false);
// }
