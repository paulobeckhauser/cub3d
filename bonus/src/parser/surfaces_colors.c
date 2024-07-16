/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   surfaces_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:16:54 by pabeckha          #+#    #+#             */
/*   Updated: 2024/07/01 18:18:15 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

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
		replace_error_message(data, "Memory allocation failed!");
		return (NULL);
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
