/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:01:21 by sfrankie          #+#    #+#             */
/*   Updated: 2024/06/11 21:22:04 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int argc, char **argv)
{
	// (void)argc;
	// (void)argv;


	// int fd;
	// char *line;

	// fd = open("maps/correct/square_map.cub", O_RDONLY);
	// if (fd == -1)
	// 	printf("not possible to open the map\n");

	// while(true)
	// {
	// 	line = get_next_line(fd);
	// 	if (!line)
	// 		break;
			
	// 	printf("%s", line);

	// 	printf("  ->  %lu", ft_strlen(line));
	// 	printf("\n\n\n");
	// 	free(line);
		
	// }

	if (argc == 2)
		return (parser(argv[1]));
	else
	{
        ft_putstr_fd(RED, 2);
        ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Incorrect number of arguments\n", 2);
        ft_putstr_fd(RESET, 2);
		return (1);
	}
    return (0);
}
