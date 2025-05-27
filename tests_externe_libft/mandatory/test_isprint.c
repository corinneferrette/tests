/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:30:14 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/19 15:00:03 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../print_test.h"
#include <ctype.h>// pour isprint
#include <stdio.h>// pour printf

void	test_isprint(void)
{
	printf("****************************************************************************************************-\n");
	printf("----------------------test ISPRINT---retourne normalement >0 pour positif----------------------------\n");
	print_test_int("ft_isprint('a')", ft_isprint('a'), isprint('a') > 0);
	print_test_int("ft_isprint('Z')", ft_isprint('Z'), isprint('Z') > 0);
	print_test_int("ft_isprint(0)", ft_isprint(0), isprint(0) > 0);
	print_test_int("ft_isprint('\t')", ft_isprint('\t'), isprint('\t') > 0);
	print_test_int("ft_isprint('@)", ft_isprint('@'), isprint('@') > 0);
	print_test_int("ft_isprint((char)200)", \
		ft_isprint((char)200), isprint((char)200) > 0);
}
