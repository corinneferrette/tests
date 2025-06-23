/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_fds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 11:29:54 by cferrett          #+#    #+#             */
/*   Updated: 2025/06/23 14:25:48 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

int main(void)
{
	int	fd1;
	int	fd2;
	int	fd3;
	int	fd4;
	char *line;

	fd1 = open("/home/cferrett/Documents/0-TESTS/3-test_externe_GNL/test_long.txt", O_RDONLY);
	fd2 = open("/home/cferrett/Documents/0-TESTS/3-test_externe_GNL/test1.txt", O_RDONLY);
	fd3 = open("/home/cferrett/Documents/0-TESTS/3-test_externe_GNL/test_no_newline.txt", O_RDONLY);
	fd4 = open("/home/cferrett/Documents/0-TESTS/3-test_externe_GNL/test_wiki.txt", O_RDONLY);
	if (fd1 < 0 ||fd2 < 0 || fd3 < 0 || fd4 < 0)
	{
		perror("Erreur d'ouverture");
		return 1;
	}

	// Lire une ligne
	line = get_next_line(fd1);
	if (line)
	{
		printf("fd1: %s", line);
		free(line);
	}
	line = get_next_line(fd2);
	if (line)
	{
		printf("fd2: %s", line);
		free(line);
	}
	line = get_next_line(fd3);
	if (line)
	{
		printf("fd3: %s", line);
		free(line);
	}
	line = get_next_line(fd4);
	if (line)
	{
		printf("fd4: %s", line);
		free(line);
	}
	line = get_next_line(fd4);
	if (line)
	{
		printf("fd4: %s", line);
		free(line);
	}
	line = get_next_line(fd1);
	if (line)
	{
		printf("fd1: %s", line);
		free(line);
	}
}
