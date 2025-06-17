/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_undefined.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:29:54 by cferrett          #+#    #+#             */
/*   Updated: 2025/06/17 10:21:55 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
	int fd;
	char *line;

	fd = open("test_undefined.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Erreur d'ouverture");
		return 1;
	}

	// Lire une ligne
	line = get_next_line(fd);
	if (line)
	{
		printf("1: %s", line);
		free(line);
	}

	printf(">>> Pause 10s : modification automatique en tâche de fond...\n");
	fflush(stdout);
	sleep(10);

	// Lire la 2e ligne après modification
	line = get_next_line(fd);
	if (line)
	{
		printf("2: %s", line);
		free(line);
	}

	close(fd);
	return 0;
}
