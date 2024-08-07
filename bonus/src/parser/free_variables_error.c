/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_variables_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:15:56 by pabeckha          #+#    #+#             */
/*   Updated: 2024/07/17 14:44:05 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

/* Function: print_arg_error
 * --------------------------
 * Prints an error message indicating an incorrect number of arguments.
 * 
 * This function uses ANSI color codes to print the error message in red, followed by resetting the text color.
 */
void	print_arg_error(void)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("Incorrect number of arguments\n", 2);
	ft_putstr_fd(RESET, 2);
}

/* Function: replace_error_message
 * -------------------------------
 * Replaces the current error message with a new one.
 * 
 * data: A pointer to the game data structure.
 * str: The new error message to be set.
 * 
 * If there's an existing error message, it is freed before setting the new one.
 * If memory allocation for the new message fails, it recursively calls itself with a "Memory allocation failed" message and then frees game variables.
 */
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

/* Function: free_variables_error
 * -------------------------------
 * Frees all allocated memory in the game data structure and prints the current error message.
 * 
 * data: A pointer to the game data structure.
 * 
 * This function iterates through all pointers in the data structure, freeing any that are not NULL.
 * After freeing the resources, it prints the current error message, sets errno if it's not already set, and exits the program.
 */
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
	if (data->map_error_message != NULL)
		ft_putstr_fd(data->map_error_message, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd(RESET, 2);
	if (errno == 0)
		errno = 1;
	if (data->map_error_message != NULL)
		free(data->map_error_message);
	exit(errno);
}
