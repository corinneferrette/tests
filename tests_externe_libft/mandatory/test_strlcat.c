/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 16:59:30 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/20 10:59:51 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "/home/cferrett/Documents/1-libft/libft.h"
#include "libft.h"
#include "../print_test.h"
#include <stdio.h>// pour printf
#include <string.h> // pour strlcat -Fonctionne sur mac mais pas sous linux

#define GRN "\033[0;32m"
#define RED = "\033[0;31m"
#define RESET = "\033[0m"

void	test_strlcat(void)
{

	printf("*******************************************************************************************************-\n");
	printf("-----------------------------------------test STRLCAT-------N EXISTE PAS SOUS LINUX------------------------\n");
	printf("CAS GENERAL\n");
	char 	ft_dest[20] = "bonjour";
	print_test_int("SIZE-\"ft_strlcat(\"bonjour\",\"jour\",2)", ft_strlcat(ft_dest, "jour", 2), 6);
	print_test_cmpr("TEXT-\"ft_strlcat(\"bonjour\",\"jour\",2)", ft_dest, "bonjour");
	printf("\n");
	
	char ft_dest1[20] = "bonjour";
	print_test_int("SIZE-\"ft_strlcat(\"bonjour\",\"jour\",5)", ft_strlcat(ft_dest1, "jour", 5), 9 );
	print_test_cmpr("TEXT-\"ft_strlcat(\"bonjour\",\"jour\",5)", ft_dest1, "bonjour");


	char ft_dest2[20] = "bonjour";
	print_test_int("SIZE-\"ft_strlcat(\"bonjour\",\"jour\",11)", ft_strlcat(ft_dest2, "jour", 11), 11);
	print_test_str("TEXT-\"ft_strlcat(\"bonjour\",\"jour\",11)", ft_dest2, "bonjourjou");

	printf("SRC=\"\"\n");
	char ft_dest3[20] = "bonjour";
	print_test_int("SIZE-\"ft_strlcat(\"bonjour\",\"\",2)", ft_strlcat(ft_dest3, "", 2), 2 );
	print_test_str("TEXT-\"ft_strlcat(\"bonjour\",\"\",2)", ft_dest3, "bonjour");


	char ft_dest4[20] = "bonjour";

	print_test_int("SIZE-\"ft_strlcat(\"bonjour\",\"\",7)", ft_strlcat(ft_dest4, "", 7), 7);
	print_test_str("TEXT-\"ft_strlcat(\"bonjour\",\"\",7)", ft_dest4, "bonjour");

	char ft_dest5[20] = "bonjour";
	print_test_int("SIZE-\"ft_strlcat(\"bonjour\",\"\",0)", ft_strlcat(ft_dest5, "", 0), 0);
	print_test_str("TEXT-\"ft_strlcat(\"bonjour\",\"\",0)", ft_dest5, "bonjour");

	printf("DEST=\"\"\n");
	char ft_dest6[20] = "";
	print_test_int("SIZE-\"ft_strlcat(\"\",\"jour\",0)", ft_strlcat(ft_dest6, "jour", 0), 4);
	print_test_str("TEXT-\"ft_strlcat(\"\",\"jour\",0)", ft_dest6, "");


	char ft_dest7[20] = "";
	print_test_int("SIZE-\"ft_strlcat(\"\",\"jour\",2)", ft_strlcat(ft_dest7, "jour", 2), 4);
	print_test_str("TEXT-\"ft_strlcat(\"\",\"jour\",2)", ft_dest7, "j");


	char ft_dest8[20] = "";
	print_test_int("SIZE-\"ft_strlcat(\"\",\"jour\",7)", ft_strlcat(ft_dest8, "jour", 7), 4);
	print_test_str("TEXT-\"ft_strlcat(\"\",\"jour\",7)", ft_dest8, "jour");


	// printf(GRN"DEST == NULL OU SRC == NULL ------> SEGFAULT\n"RESET);
	// 	//SEGFAULT AVEC VOID
	// 	// char dest10[20] ="bonjour";
	// 	// ft_strlcat(((void *)0), "jour", 6);
	// 	// ft_strlcat(dest10, ((void *)0), 6);
	
	

}