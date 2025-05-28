# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/19 17:37:37 by cferrett          #+#    #+#              #
#    Updated: 2025/05/23 17:49:55 by cferrett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#---------------------------------VARIABLES-------------------------------------
NAME = TEST_LIBFT
CC = gcc
CFLAGS = -Wall -Wextra -Werror

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m
#---------------------------------REPERTOIRES------------------------------------
TESTS_DIR = tests
MANDATORY_DIR = mandatory

# On essaie de charger le chemin sauvegardé dans .libft_path
ifeq ($(origin LIBFT_DIR), undefined)
ifneq ("$(wildcard .libft_path)", "")
	LIBFT_DIR := $(shell cat .libft_path)
else
	LIBFT_DIR := ..
endif
endif
LIBFT_DIR ?= ..
LIBFT_A = $(LIBFT_DIR)/libft.a
INCLUDES = -I$(LIBFT_DIR) -I.

#---------------------------------fichiers sources et objet------------------------------------
SRC = $(wildcard *.c) $(wildcard $(MANDATORY_DIR)/*.c)
OBJ = $(SRC:.c=.o)

MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)

#------------------------REGLE PAR DEFAUT--------------------------------------
# all: check_path build_libft $(NAME)
all: check_path $(NAME)
check_path:
	@printf "Chemin vers le dossier contenant libft.a : "; \
	read libft_path; \
	if [ -z "$$libft_path" ]; then \
		echo "Aucun chemin fourni. Abandon."; \
		exit 1; \
	fi; \
	if [ ! -f "$$libft_path/libft.a" ]; then \
		echo "libft.a non trouvé. Tentative de compilation dans $$libft_path..."; \
		if [ -f "$$libft_path/Makefile" ]; then \
			$(MAKE) -C "$$libft_path"; \
		else \
			echo "Pas de Makefile trouvé dans $$libft_path. Abandon."; \
			exit 1; \
		fi; \
	fi; \
	if [ ! -f "$$libft_path/libft.a" ]; then \
		echo "Impossible de trouver ou créer libft.a. Abandon."; \
		exit 1; \
	fi; \
	echo "OK : libft.a trouvé dans $$libft_path"; \
	echo "$$libft_path" > .libft_path
# build_libft:
# 	$(MAKE) -C $(LIBFT_DIR)

#------------------------COMPILATION DE L'EXECUTABLE--------------------------------------
$(NAME) : $(OBJ)
# $(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_A) $(INCLUDES)
	@echo "$(GREEN)---------Executable $(NAME) created------A RETIRER POUR 42-----$(RESET)"

#------------------------COMPILATION DES FICHIERS OBJETS--------------------------------------
%.o:%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$(GREEN)-----------Files .o created-----A RETIRER POUR 42------$(RESET)-"

#-----------------------------NETTOYAGE--------------------------------------
clean:
	rm -f $(OBJ)
	rm -f $(MANDATORY_OBJ)
	@echo "$(RED)--------Files .o deleted--------A RETIRER POUR 42---$(RESET)"
	@echo "\n"
fclean: clean
	rm -f $(NAME)
	@echo "$(RED)---------Library TEST_LIBFT deleted---A RETIRER POUR 42--------$(RESET)"
	rm -f a.out
	@echo "$(RED)--------Files a.out deleted-----------$(RESET)"
	@echo "\n"
re: clean fclean all
run: all
	@./$(NAME)
#-----------------------------DEBUG--------------------------------------
# debug: $(NAME)
# 	lldb ./$(NAME)
#-----------------------------REGLES NON LIEES A DES FICHIERS--------------------------------------
.PHONY: all clean fclean re

# ----------------------------- VALGRIND ---------------------------------
valgrind: all
	@echo "$(GREEN)→ Lancement de Valgrind sur ./$(NAME)$(RESET)"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

leaks:
	@echo "$(GREEN)→ Lancement de leaks sur ./$(NAME)$(RESET)"
	leaks --atExit -- ./$(NAME)