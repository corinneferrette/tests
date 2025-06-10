/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 20:19:48 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/22 11:36:37 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../print_test.h"
#include <unistd.h> // pour size_t
#include <stdio.h>// pour printf

#include <stddef.h>

//STRLCPY N EXISTE PAS SOUS LINUX IL FAUR DONC COMPARER AU RESULTAT ATTENDU ET NON AU RESULTAT DE LA FONCTION
// J AI FAIT LES TESTS SUR MAC OU LA FONCTION STRLCPY EXISTE ET JE COMPARE LES RESULTATS OBTENUS AVEC CEUX ATTENDUS SUR MAC
void	test_strlcpy(void)
{
	printf("**********************************************************************************************************-\n");
	printf("-----------------------test STRLCPY-------COMPARE AUX ATTENDUS PAS A LA FONCTION---------------------------\n");
	printf("CAS GENERAL\n");
	char ft_dest0[10] = {0};
	char sys_dest0[10] = "hello";
	size_t ft_ret0 = ft_strlcpy(ft_dest0, "hello", 10);
	size_t sys_ret0 = 5;
	print_test_int("SIZE-ft_strlcpy(\"0000000000\",\"hello\",10)", ft_ret0, sys_ret0);
	print_test_cmpr("DST-ft_strlcpy(\"0000000000\",\"hello\",10)", ft_dest0, sys_dest0);
	printf("\n");

	char ft_dest1[10] = {0};
	char sys_dest1[10] = "he";
	size_t ft_ret1 = ft_strlcpy(ft_dest1, "hello", 3);
	size_t sys_ret1 = 5;
	print_test_int("SIZE-ft_strlcpy(\"0000000000\",\"hello\",3)", ft_ret1, sys_ret1);
	print_test_cmpr("DST-ft_strlcpy(\"0000000000\",\"hello\",3)", ft_dest1, sys_dest1);
	printf("\n");
	
	char ft_dest2[10] = {0};
	char sys_dest2[10] = "";
	size_t ft_ret2 = ft_strlcpy(ft_dest2, "hello", 0);
	size_t sys_ret2 = 5;
	print_test_int("SIZE-ft_strlcpy(\"0000000000\",\"hello\",0)", ft_ret2, sys_ret2);
	print_test_cmpr("DST-ft_strlcpy(\"0000000000\",\"hello\",0)", ft_dest2, sys_dest2);
	printf("\n");

	printf("DEST = NULL	- SEGFAULT\n");	
	// char *ft_dest3 = NULL;
	// char sys_dest3[10] = "";
	// size_t ft_ret3 = ft_strlcpy(ft_dest3, "", 10);
	// size_t sys_ret3 = 0;
	// print_test_int("SIZE-ft_strlcpy(\"0000000000\",\"\",10)", ft_ret3, sys_ret3);
	// print_test_cmpr("DST-ft_strlcpy(\"0000000000\",\"\",10)", ft_dest3, sys_dest3);
	// printf("\n");

	// char ft_dest4[10] = {0};
	// char sys_dest4[10] = "";
	// size_t ft_ret4 = ft_strlcpy(ft_dest4, "", 3);
	// size_t sys_ret4 = 0;
	// print_test_int("SIZE-ft_strlcpy(\"0000000000\",\"\",3)", ft_ret4, sys_ret4);
	// print_test_cmpr("DST-ft_strlcpy(\"0000000000\",\"\",3)", ft_dest4, sys_dest4);
	// printf("\n");

	// char ft_dest5[10] = {0};
	// char sys_dest5[10] = "";
	// size_t ft_ret5 = ft_strlcpy(ft_dest5, "", 0);
	// size_t sys_ret5 = 0;
	// print_test_int("SIZE-ft_strlcpy(\"0000000000\",\"\",0)", ft_ret5, sys_ret5);
	// print_test_cmpr("DST-ft_strlcpy(\"0000000000\",\"\",0)", ft_dest5, sys_dest5);
	// printf("\n");

	printf("SRC = NULL - SEGFAULT\n");
	// char ft_dest6[10] = {0};
	// char sys_dest6[10] = "";
	// size_t ft_ret6 = ft_strlcpy(ft_dest6, "", 0);
	// size_t sys_ret6 = 0;
	// print_test_int("SIZE-ft_strlcpy(\"\",\"\",0)", ft_ret6, sys_ret6);
	// print_test_cmpr("DST-ft_strlcpy(\"\",\"\",0)", ft_dest6, sys_dest6);
	// printf("\n");

	// printf("DEST = NULL - SRC = \"abcd\" - 3\n");	SEGFAULT
	// char *ft_dest7 = '\0';
	// char sys_dest7[10] = "abcd";
	// size_t ft_ret7 = ft_strlcpy(ft_dest7, "abcd", 3);
	// size_t sys_ret7 = 3;
	// print_test_int("SIZE-ft_strlcpy(\"\",\"\",0)", ft_ret7, sys_ret7);
	// print_test_cmpr("DST-ft_strlcpy(\"\",\"\",0)", ft_dest7, sys_dest7);
	// printf("\n");

	// printf("DEST = 'NULL' - SRC = \"abcd\" - 3\n");	SEGFAULT
	// char *ft_dest7 = '\0';
	// char sys_dest7[10] = "abcd";
	// size_t ft_ret7 = ft_strlcpy(ft_dest7, "abcd", 3);
	// size_t sys_ret7 = 3;
	// print_test_int("SIZE-ft_strlcpy(\"\",\"\",0)", ft_ret7, sys_ret7);
	// print_test_cmpr("DST-ft_strlcpy(\"\",\"\",0)", ft_dest7, sys_dest7);
	// printf("\n");
}
