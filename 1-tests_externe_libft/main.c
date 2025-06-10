/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 11:56:06 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/20 12:35:24 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "print_test.h"
#include <stddef.h>//  pour bzero
#include <stdio.h>
#include <string.h>//pour NULL
#include <ctype.h>
#include <stdlib.h>

void	test_atoi(void);
void	test_bzero(void);
void	test_calloc(void);
void	test_isalnum(void);
void	test_isalpha(void);
void	test_isascii(void);
void	test_isdigit(void);
void	test_isprint(void);
void	test_itoa(void);
void	test_memchr(void);
void	test_memcmp(void);
void	test_memcpy(void);
void	test_memmove(void);
void	test_memset(void);
void	test_split(void);
void	test_strchr(void);
void	test_strdup(void);
void	test_striteri(void);
void	test_strjoin(void);
void	test_strlcat(void);
void	test_strlcpy(void);
void	test_strlen(void);
void	test_strmapi(void);
void	test_strncmp(void);
void	test_strnstr(void);
void	test_strrchr(void);
void	test_strtrim(void);
void	test_substr(void);
void	test_tolower(void);
void	test_toupper(void);



int main(void)
{
	printf("----------------------------------------------- TEST LIBFT -------------------------------------------\n");
	test_atoi();
	test_bzero();
	test_calloc();
	test_isalnum(); // retourne des bits; soit 0 soit 8----
	test_isalpha();//retourne des octets; soit 0 soit 1024
	test_isascii();
	test_isdigit();//retourne  des 8,1024 ou 2048 pour un digit
	test_isprint();//retourne normalement >0 pour positif-
	test_itoa();
	// test_lstadd_back();
	// test_lstadd_front();
	// test_lstclear();
	// test_lstdelone();
	// test_lstiter();
	// test_lstlast();
	// test_lstmap();
	// test_lstnew();
	// test_lstsize();
	test_memchr();
	test_memcmp();
	test_memcpy();
	test_memmove();
	test_memset();//-X = 88
	// test_putchar_fd();
	// test_putendl_fd();
	// test_putnber_fd();
	// test_putstr_fd();
	test_split();
	test_strchr();
	test_strdup();
	test_striteri();
	test_strjoin();
	test_strlcat();
	test_strlcpy();
	test_strlen();
	test_strmapi();
	test_strncmp();
	test_strnstr();
	test_strrchr();
	test_strtrim();
	test_substr();
	test_tolower();
	test_toupper();

	print_final_result();
	return (0);
}
