
#include "../inc/cub3d.h"

int parser(char *str)
{
    t_data data;

    data.player = (t_player *)malloc(sizeof(t_player));

    init_vars(&data);

    if (!check_extension(&data, str, "cub") 
        || !store_cub_file(&data, str)
            || !store_surface_colors(&data) 
            || !store_textures(&data) || !store_map(&data))
        return(free_variables_error(&data));

    return (0);
}
