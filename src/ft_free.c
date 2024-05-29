

#include "../inc/cub3d.h"


void free_2d_array(char **array)
{
    int i;

    i = 0;
    if (array)
    {
        while(array[i])
        {
            free(array[i]);
            i++;
        }
        free(array);
    }
    array = NULL;
}