/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:14:25 by pabeckha          #+#    #+#             */
/*   Updated: 2024/07/16 17:22:32 by pabeckha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

bool	count_lines_map(t_data *data, char *str)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		ft_putstr_fd("Error opening the file\n", 2);
		return (false);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		data->number_lines_map++;
		free(line);
	}
	close(fd);
	return (true);
}

static bool	write_char_by_char(t_data *data, int i, char *line)
{
	int	j;

	data->cub_file[i] = malloc((ft_strlen(line) + 1) * sizeof(char));
	if (!data->cub_file[i])
	{
		replace_error_message(data, "Memory allocation failed");
		free_variables_error(data);
		return (false);
	}
	j = 0;
	while (line[j] && line[j] != '\n')
	{
		data->cub_file[i][j] = line[j];
		j++;
	}
	data->cub_file[i][j] = '\0';
	return (true);
}

bool	write_lines(t_data *data, int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		if (!write_char_by_char(data, i, line))
			return (false);
		i++;
		free(line);
	}
	data->cub_file[i] = NULL;
	return (true);
}

bool	store_cub_file(t_data *data, char *str)
{
	int	fd;

	if (!count_lines_map(data, str))
		return (false);
	data->cub_file = malloc((data->number_lines_map + 1) * sizeof(char *));
	if (!data->cub_file)
	{
		replace_error_message(data, "Memory allocation failed");
		free_variables_error(data);
		return (false);
	}
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		replace_error_message(data, strerror(errno));
		return (free_variables_error(data));
	}
	if (!write_lines(data, fd))
		return (false);
	close(fd);
	return (true);
}
