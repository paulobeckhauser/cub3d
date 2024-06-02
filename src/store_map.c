
#include "../inc/cub3d.h"

bool count_lines_map(t_data *data)
{
    int fd;
    char *line;

    line = NULL;
    fd = open("maps/example_2.cub", O_RDONLY);
    if (fd == -1)
    {
        close(fd);
        ft_putstr_fd("Error opening the file\n", 2);
        return(false);
    }
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
        {
            free(line);
            break;
        }
        data->number_lines_map++;
        free(line);
    }
    close(fd);
    return(true);
}


bool store_map(t_data *data)
{
    int fd;
    int i;
    char *line;

    if (!count_lines_map(data))
        return(false);

    data->map = malloc(data->number_lines_map * sizeof(char *));
    if (!data->map)
    {
        ft_putstr_fd("Memory allocation error\n", 2);
        return (1);
    }

    fd = open("maps/example_2.cub", O_RDONLY);
    i = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
        {
            free(line);
            break;
        }
        printf("%s", line);
        data->map[i] = ft_strdup(line);
        free(line);
        i++;
    }
    printf("\n");
    return (true);
}
