/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isdigit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:30:14 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/19 18:59:01 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../print_test.h"
#include <ctype.h>// pour isdigitt
#include <stdio.h>// pour printf

void	test_isdigit(void)
{
	printf("*******************************************************************************************************-\n");
	printf("--------------------test ISDIGIT-retourne  des 8,1024 ou 2048 suivant l'ordinateur----------------------\n");
	printf("------------------------------------ici 2048 pour un digit----dépend peut être de l'ordi----------------\n");
	int os_val;
	#ifdef __linux__
		os_val = 2048;
	#elif __APPLE__
		os_val = 1;
	#elif _WIN32
		os_val = 1;
	#else
		os_val = 1;
	#endif
	print_test_int("ft_isdigit('a')", ft_isdigit('a'), isdigit('a')/os_val);
	print_test_int("ft_isdigit('5')", ft_isdigit('5'), isdigit('5')/os_val);
	print_test_int("ft_isdigit(0)", ft_isdigit(0), isdigit(0)/os_val);
	print_test_int("ft_isdigit('\t')", ft_isdigit('\t'), isdigit('\t')/os_val);
	print_test_int("ft_isdigit('@)", ft_isdigit('@'), isdigit('@')/os_val);
	print_test_int("ft_isdigit((char)200)", \
		ft_isdigit((char)200), isdigit((char)200)/os_val);
}
