/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfrankie <sfrankie@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 18:14:25 by pabeckha          #+#    #+#             */
/*   Updated: 2024/08/07 19:15:22 by sfrankie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/cub3d.h"

/* Function: count_lines_map
 * --------------------------
 * Counts the number of lines in a map file.
 * 
 * data: A pointer to the game data structure.
 * str: The filename of the map file.
 * 
 * Opens the map file and reads it line by line, incrementing a counter for each line read.
 * Returns true if the file was successfully read, false if the file could not be opened.
*/
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

/* Function: write_char_by_char
 * -----------------------------
 * Writes a line from the map file into the game data structure, character by character.
 * 
 * data: A pointer to the game data structure.
 * i: The index of the line being written.
 * line: The line from the map file to be written.
 * 
 * Allocates memory for the line and copies it character by character.
 * Returns true if the operation was successful, false if memory allocation failed.
 */
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


/* Function: write_lines
 * ----------------------
 * Reads lines from the map file and writes them into the game data structure.
 * 
 * data: A pointer to the game data structure.
 * fd: The file descriptor of the map file.
 * 
 * Reads the map file line by line using a loop and calls write_char_by_char for each line.
 * Returns true if all lines were successfully written, false if an error occurred.
 */
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

/* Function: store_cub_file
 * -------------------------
 * Stores the contents of the .cub file in the game data structure.
 * 
 * data: A pointer to the game data structure.
 * str: The filename of the .cub file.
 * 
 * Counts the number of lines in the .cub file, allocates memory for storing the file's contents,
 * opens the file, and writes its lines into the allocated memory.
 * Returns true if the file was successfully stored, false if an error occurred.
 */
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
