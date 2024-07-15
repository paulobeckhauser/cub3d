/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabeckha <pabeckha@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:14:25 by pabeckha          #+#    #+#             */
/*   Updated: 2024/07/15 18:41:38 by pabeckha         ###   ########.fr       */
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

void	write_lines(t_data *data, int fd)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		data->cub_file[i] = malloc((ft_strlen(line) + 1) * sizeof(char));
		j = 0;
		while (line[j] && line[j] != '\n')
		{
			data->cub_file[i][j] = line[j];
			j++;
		}
		data->cub_file[i][j] = '\0';
		i++;
		free(line);
	}
	data->cub_file[i] = NULL;
}

bool	store_cub_file(t_data *data, char *str)
{
	int	fd;

	if (!count_lines_map(data, str))
		return (false);
	data->cub_file = malloc((data->number_lines_map + 1) * sizeof(char *));
	if (!data->cub_file)
	{
		ft_putstr_fd("Memory allocation error\n", 2);
		return (1);
	}
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		replace_error_message(data, strerror(errno));
		return (free_variables_error(data));
	}
	write_lines(data, fd);
	close(fd);
	return (true);
}
