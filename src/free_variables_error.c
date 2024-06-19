/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_variables_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:51:41 by pabeckha          #+#    #+#             */
/*   Updated: 2024/06/19 17:53:04 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	replace_error_message(t_data *data, char *str)
{
	if (data->map_error_message)
		free(data->map_error_message);
	data->map_error_message = ft_strdup(str);
}

int	free_variables_error(t_data *data)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(data->map_error_message, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd(RESET, 2);
	if (errno == 0)
		errno = 1;
	exit(errno);
}

void	free_2d_array(char **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
	array = NULL;
}
