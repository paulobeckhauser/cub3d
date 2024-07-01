/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:13:45 by pabeckha          #+#    #+#             */
/*   Updated: 2024/07/01 18:14:11 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

int	size_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

bool	check_extension(t_data *data, char *str, char *extension)
{
	int		i;
	char	**array;

	array = NULL;
	array = ft_split(str, '.');
	i = size_array(array) - 1;
	if (size_array(array) == 1 || ft_strcmp(array[i], extension) != 0)
	{
		replace_error_message(data, "Map is not a '.cub' file");
		free_2d_array(array);
		return (false);
	}
	free_2d_array(array);
	return (true);
}
