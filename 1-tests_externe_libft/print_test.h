/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 12:43:27 by cferrett          #+#    #+#             */
/*   Updated: 2025/05/14 15:10:06 by cferrett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_TEST_H
# define PRINT_TEST_H

void	print_bytes(const char *test_n, const unsigned char *ptr, size_t len);
void	print_test_int(char *test_name, int result, int expected);
void	print_test_str(char *test_name, char *result, char *expected);
void	print_test_cmpr(char *test_n, char *res, char *exp);
void	print_test_cmprn(char *test_n, char *res, char *exp, int len);
void	print_test_ptr(char *test_n, char *res, char *exp);
void	print_test_different_ptr(char *test_n, char *res, char *exp) ;
void	print_test_calloc(const char *desc, size_t count, size_t size);
// void	run_test_safely(void (*test_func)(void), const char *label);
void	compare_string_tab(const char *test_n, char **result, char **expected);
void print_final_result(void);

#endif