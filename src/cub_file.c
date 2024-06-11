
#include "../inc/cub3d.h"

bool count_lines_map(t_data *data, char *str)
{
    int fd;
    char *line;

    line = NULL;
    fd = open(str, O_RDONLY);
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


bool store_cub_file(t_data *data, char *str)
{
    int fd;
    int i;
    char *line;
    int j;

    j = 0;

    if (!count_lines_map(data, str))
        return(false);


    data->cub_file = malloc((data->number_lines_map + 1) * sizeof(char *));
    if (!data->cub_file)
    {
        ft_putstr_fd("Memory allocation error\n", 2);
        return (1);
    }

    fd = open(str, O_RDONLY);
    if (fd == -1)
    {
        replace_error_message(data, strerror(errno));
        return(free_variables_error(data));
    }

    i = 0;
    while (1)
    {
        line = get_next_line(fd);

        if (!line)
        {

            free(line);
            break;
        }
        data->cub_file[i] = malloc(ft_strlen(line) * sizeof(char));


        //check malloc
        j = 0;

        while(line[j] && line[j] != '\n')
        {
            data->cub_file[i][j] = line[j];
            j++;
        }
        data->cub_file[i][j] = '\0';



        // while (line[])



        // data->cub_file[i] = ft_strdup(line);
        i++;
        free(line);
    }
    data->cub_file[i] = NULL;
    close(fd);
    return (true);
}
