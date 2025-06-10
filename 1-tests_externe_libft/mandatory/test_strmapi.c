/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strmapi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 11:06:09 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/20 11:31:55 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../print_test.h"
#include <stdlib.h> // pour isprint
#include <stdio.h> // pour printf

char to_upper_strmapi(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

char upper_even(unsigned int i, char c)
{
	if (i % 2 == 0 && c >= 'a' && c <= 'z')
		return c - 32;
	return c;
}

void test_strmapi(void)
{
	printf("****************************************************************************************************-\n");
	printf("-------------------------------test ITERI-----------------------------------------------------------\n");

	char *res = ft_strmapi("hello", to_upper_strmapi);
	printf("Résultat : %s\n", res); // doit afficher "HELLO"
	free(res);

	res = ft_strmapi("", to_upper_strmapi);
	printf("Test vide       : %s\n", res); // doit afficher ""
	free(res);

	res = ft_strmapi("café", to_upper_strmapi);
	printf("Accentué        : %s\n", res); // comportement dépend de l'encodage, ici attendu : "CAFÉ"
	free(res);

	res = ft_strmapi("", to_upper_strmapi);
	printf("Test vide       : %s\n", res); // doit afficher ""
	free(res);

	res = ft_strmapi("abcdef", upper_even);
	printf("Index pair only : %s\n", res); // doit afficher "AbCdEf"
	free(res);

	res = ft_strmapi(NULL, to_upper_strmapi);
	printf("NULL string     : %s\n", res ? res : "(null)");

	res = ft_strmapi("abc", NULL);
	printf("Fonction NULL   : %s\n", res ? res : "(null)");
}
