/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 20:15:03 by cferrett          #+#    #+#             */
/*   Updated: 2025/06/16 19:21:45 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int fd;
	char *line;
	int is_stdin = 1;

	fd = 0; // par défaut, fd = 0 entree standard
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			write(2, "Error due to open.\n", 19);
			return (1);
		}
		is_stdin = 0;
	}
	else if (argc > 2)
	{
		write(2, "Too many arguments.\n", 21);
		return (1);
	}
	if (is_stdin)
		write(1, "> ", 2); // Premier prompt
	while ((line = get_next_line(fd)) != NULL)
	{
		write(1, line, gnl_strlen(line));
		free(line);
		if (is_stdin)
			write(1, "> ", 2); // prompt suivant
	}
	if (fd != 0)
		close(fd);
	return (0);
}
// On fait
// cc - Wall - Wextra - Werror - D BUFFER_SIZE = 42 get_next_line_utils.c get_next_line.c
// puis
// ./ a.out test_long.txt