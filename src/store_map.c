

#include "../../inc/cub3d.h"

bool store_map_element(t_data *data)
{
    if (data->element_position != 6)
    {
        ft_putstr_fd("Map is not the last element\n", 2);
        data->map_error = true;
        return (false);
    }


    return (true);
}