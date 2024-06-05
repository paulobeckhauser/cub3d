

#include "../../inc/cub3d.h"

void replace_error_message(t_data *data, char *str)
{
    if (data->map_error_message)
        free(data->map_error_message);
    data->map_error_message = ft_strdup(str);
}

int free_variables_error(t_data *data)
{
    ft_putstr_fd("Error: ", 2);
    ft_putstr_fd(data->map_error_message, 2);
    ft_putstr_fd("\n", 2);
    if (errno == 0)
        errno = 1;
    exit(errno);
}