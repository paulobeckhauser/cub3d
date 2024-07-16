/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_variables_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:15:56 by pabeckha          #+#    #+#             */
/*   Updated: 2024/07/16 20:22:37 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

void	replace_error_message(t_data *data, char *str)
{
	if (data->map_error_message != NULL)
		free(data->map_error_message);
	data->map_error_message = ft_strdup(str);
	if (!data->map_error_message)
	{
		replace_error_message(data, "Memory allocation failed");
		free_variables_error(data);
	}
}

int	free_variables_error(t_data *data)
{
	if (data->player != NULL)
		free(data->player);
	
	if (data->cub_file != NULL)
		free_2d_array(data->cub_file);
	
	if (data->map_element != NULL)
		free_2d_array(data->map_element);


	if (data->texture_north != NULL)
		free(data->texture_north);

	if (data->texture_south != NULL)
		free(data->texture_south);

	if (data->texture_west != NULL)
		free(data->texture_west);

	if (data->texture_east != NULL)
		free(data->texture_east);



	
	
	
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(data->map_error_message, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd(RESET, 2);
	if (errno == 0)
		errno = 1;


	if (data->map_error_message != NULL)
		free(data->map_error_message);
	exit(errno);
}
