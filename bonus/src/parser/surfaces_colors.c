/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surfaces_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:16:54 by pabeckha          #+#    #+#             */
/*   Updated: 2024/08/07 19:33:24 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

/* Function: count_chars_color
 * ----------------------------
 * Counts the number of characters in a string that are not equal to a specified character or space.
 * 
 * data: A pointer to the game data structure.
 * i: The index of the string within the data structure's cub_file array.
 * c: The character to check against in the string.
 * 
 * Returns the count of characters not equal to 'c' and not a space.
 */
int	count_chars_color(t_data *data, int i, char c)
{
	int	j;
	int	count_chars;

	count_chars = 0;
	j = 0;
	while (data->cub_file[i][j])
	{
		if (data->cub_file[i][j] != c && data->cub_file[i][j] != ' ')
			count_chars++;
		j++;
	}
	return (count_chars);
}

/* Function: clean_str_color
 * --------------------------
 * Creates a new string from the given string, removing specified characters and spaces.
 * 
 * data: A pointer to the game data structure.
 * i: The index of the string within the data structure's cub_file array.
 * surf: The character to be removed from the string, along with spaces.
 * 
 * Returns a newly allocated string with 'surf' characters and spaces removed.
 * If memory allocation fails, returns NULL after setting an error message.
 */
char	*clean_str_color(t_data *data, int i, char surf)
{
	int		count_chars;
	char	*cleaned_string;
	int		j;
	int		k;

	k = 0;
	count_chars = count_chars_color(data, i, surf);
	cleaned_string = malloc((count_chars + 1) * sizeof(char));
	if (!cleaned_string)
	{
		free(cleaned_string);
		return (replace_error_message(data, "Memory allocation failed!"), NULL);
	}
	j = 0;
	while (data->cub_file[i][j])
	{
		if (data->cub_file[i][j] != surf && data->cub_file[i][j] != ' ')
		{
			cleaned_string[k] = data->cub_file[i][j];
			k++;
		}
		j++;
	}
	cleaned_string[k] = '\0';
	return (cleaned_string);
}
