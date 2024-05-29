
#include "../inc/cub3d.h"


bool floor_line_exist(char *str, char digit)
{
    int i;

    i = 0;
    while (str[i] == ' ')
        i++;
    if (str[i] == digit && str[i++])
        return (true);
    return (false);
}


int checker_map(char *str)
{
    (void)str;


    if (!floor_line_exist(str, 'F'))
        printf("Error\n");
        // perror("Error\n");
    // {
    //     printf("Floor line exist\n");
    //     return (0);
    // }



    // printf("Error\n");

    return (1);











}