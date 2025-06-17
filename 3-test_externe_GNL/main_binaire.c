/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_binaire.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:09:36 by cferrett          #+#    #+#             */
/*   Updated: 2025/06/17 19:32:00 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

int main(void)
{
	int fd = open("test.bin", O_RDONLY);
	if (fd < 0)
		return (perror("open"), 1);

	char *line;
	while ((line = get_next_line(fd)))
	{
		write(1, line, strlen(line)); // ou affiche en hexadécimal
		free(line);
	}
	close(fd);
	return (0);
}
