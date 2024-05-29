
#include "../inc/cub3d.h"


static int check_first_char(char *str, char digit)
{
    int i;

    i = 0;
    while (str[i] && str[i] == ' ')
    {
        i++;
    }
    if (str[i] == digit && str[i + 1] == ' ')
        return (0);
    return (1);
}

// static int check_rgb_values() {
//
// }

int check_color_input(char *str, char digit)
{
    check_first_char(str, digit);
    // check_rgb_values();



    return (1);


}


int parser(void)
{
    
    t_data data;

    data.north_texture = NULL;
    data.south_texture = NULL;
    data.west_texture = NULL;
    data.east_texture = NULL;

    data.map_error = false;

    // // 1. read file
    int fd;
    char *line;
    int i;

    i = 0;


    fd = open("maps/example_2.cub", O_RDONLY);
    if (fd == -1)
        printf("error opening the file\n");




    while(1)
    {

        line = get_next_line(fd);
        if (!line)
            break;



        if (line[i] == 'F')
            data.floor_color = store_hex_color(line);
        if (line[i] == 'C')
            data.ceiling_color = store_hex_color(line);




        free(line);
    }


    printf("%d\n", data.floor_color);
    printf("%X\n", data.floor_color);

    printf("%d\n", data.ceiling_color);
    printf("%X\n", data.ceiling_color);


    return (0);
}