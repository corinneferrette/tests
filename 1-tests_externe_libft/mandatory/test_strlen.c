/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:30:14 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/18 10:55:25 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../print_test.h"
#include <string.h> // pour strlen
#include <stdio.h>// pour printf

void	test_strlen(void)
{
	printf("**********************************************************************************************************-\n");
	printf("--------------------------------------------test STRLEN----------------------------------------------------\n");
	print_test_int("ft_strlen(\"coucou\")", \
		ft_strlen("coucou"), strlen("coucou"));
	print_test_int("ft_strlen(\"coucou\ncomment \tca va\")", \
		ft_strlen("coucou\ncomment \tca va"), \
		strlen("coucou\ncomment \tca va"));
	print_test_int("ft_strlen(\"\")", ft_strlen(""), strlen(""));
	print_test_int("ft_strlen(\"abc\\0def\")", \
		ft_strlen("abc\0def"), strlen("abc\0def"));
}

// print_test_int("ft_strlen(NULL)", ft_strlen(NULL), strlen(NULL));