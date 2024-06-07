/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:01:21 by sfrankie          #+#    #+#             */
/*   Updated: 2024/06/06 19:35:27 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
		return (parser(argv[1]));
	else
	{
        ft_putstr_fd(RED, 2);
        ft_putstr_fd("Error!\n", 2);
		ft_putstr_fd("Incorrect number of arguments\n", 2);
        ft_putstr_fd(RESET, 2);
		return (1);
	}
    return (0);
}
