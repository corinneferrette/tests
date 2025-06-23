/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 09:40:13 by cferrett          #+#    #+#             */
/*   Updated: 2025/06/23 14:03:44 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

int main(int argc, char **argv)
{
	int 	fd;
	char	*line;
	int 	i;

	i = 0;
	// Si aucun fichier : lecture depuis stdin
	if (argc == 1)
	{
		write(1, "> ", 2);
		while ((line = get_next_line(0)) != NULL)
		{
			write(1, line, gnl_strlen(line));
			free(line);
			write(1, "> ", 2);
		}
		return (0);
	}

	// Sinon, lecture de chaque fichier passé en argument
	
	for (int i = 1; i < argc; i++)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd < 0)
		{
			write(2, "Error opening file: ", 21);
			write(2, argv[i], gnl_strlen(argv[i]));
			write(2, "\n", 1);
			continue;
		}
		write(1, "=== ", 4);
		write(1, argv[i], gnl_strlen(argv[i]));
		write(1, " ===\n", 5);
		while ((line = get_next_line(fd)) != NULL)
		{
			write(1, line, gnl_strlen(line));
			free(line);
		}
		close(fd);
	}
	return (0);
}
