/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 00:12:07 by sfrankie          #+#    #+#             */
/*   Updated: 2024/08/07 19:58:13 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d.h"

/* Function: free_2d_array
Frees a dynamically allocated 2D array.
array: A pointer to the first element of the array to be freed.
This function iterates through the array, freeing each sub-array (row) before finally freeing the array itself. It then sets the pointer to the array to NULL to avoid dangling pointers. */
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
