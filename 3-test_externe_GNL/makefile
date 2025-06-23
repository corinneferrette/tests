# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/30 11:05:46 by cferrett          #+#    #+#              #
#    Updated: 2025/06/23 14:01:17 by cferrett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#============== Définition des variables ===========================
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -I${PATH_GNL}
PATH_FILE = .path_file
TEST_MAIN ?= main.c
TEST_MAIN_BONUS ?= main_bonus.c
FILE_TEST ?= test_wiki.txt

SRC = ${PATH_GNL}/get_next_line.c ${PATH_GNL}/get_next_line_utils.c ${TEST_MAIN}
OBJ = $(SRC:.c=.o)
NAME  = get_next_line

SRC_BONUS = ${PATH_GNL}/get_next_line_bonus.c ${PATH_GNL}/get_next_line_utils_bonus.c ${TEST_MAIN_BONUS}
OBJ_BONUS = $(SRC_BONUS:.c=.o)
NAME_BONUS = get_next_line_bonus



#======== Chargement du chemin depuis .path_file ==============
-include $(PATH_FILE)
# ===== Règle : définir le chemin vers ft_printf ============
set:
	@read -p "Chemin vers get_next_linef (ex: ../get_next_line) : " path && \
	echo "PATH_GNL=$$path" > $(PATH_FILE) && \
	echo "→ Chemin enregistré dans $(PATH_FILE)"

# ===== Règle : vérification que PATH_PRINTF est défini =====
check_path:
	@if [ -z "$(PATH_GNL)" ]; then \
		echo "PATH_GNL non défini. Lancez 'make set' d'abord."; \
		exit 1; \
	fi

RED=\033[1;31m
GRNB=\033[1;32m
GRN=\033[0;32m
RESET=\033[0m

#Option par dèfaut si non prècisèe
BUFFER_SIZE ?= 42

#Règle generale
all: $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -o $(NAME) $(OBJ)
	@echo "${RED}Compilation avec BUFFER_SIZE=$(BUFFER_SIZE) terminée ${RESET}"

#Regle de compilation individuelle
%.o: %.c
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@

#DEPENDANCES  Recompiler si get_next_line.f est modifie
${PATH_GNL}/get_next_line.o: ${PATH_GNL}/get_next_line.h
${PATH_GNL}/get_next_line_utils.o: ${PATH_GNL}/get_next_line.h
main.o: ${PATH_GNL}/get_next_line.h

#Règle de nettoyage qui supprime les fichiers objet
clean:
	rm -f $(OBJ)

#règle pour supprimr tous les fichiers y compris l'exécutable

fclean: clean
	rm -f $(NAME)

# Règle pour tout nettoyer et recompiler
re: fclean all

# Regle de tests buffer
BUFFER_SIZES = 1 8 32 1000
TEST_FILES = test_1.txt test_empty.txt test_no_newline.txt test_long.txt test.wiki.txt
test_buffer:
	@for size in $(BUFFER_SIZES); do \
		echo "\n${GRNB}=== Tests avec BUFFER_SIZE=$$size ===${RESET}"; \
		$(MAKE) re BUFFER_SIZE=$$size --no-print-directory; \
		for file in $(TEST_FILES); do \
			if [ -f $$file ]; then \
				echo "${GRN}--- Fichier: $$file ---${RESET}"; \
				./$(NAME) $$file | head -n 3; \
			else \
				echo "Fichier $$file manquant"; \
			fi; \
		done; \
	done
test_neg:
	@$(MAKE) re TEST_MAIN=main_fd_negative.c --no-print-directory
	@./$(NAME)

test:
	@$(MAKE) re TEST_MAIN=main.c --no-print-directory
	@./$(NAME) $(FILE_TEST)

# Règle pour lancer valgrind
valgrind: $(NAME)
	valgrind --leak-check=full --track-origins=yes ./$(NAME) test_1.txt

# Règle pour lancer leaks
leaks: $(NAME)
	leaks --atExit -- ./$(NAME) test_1.txt

# Spécification des cibles qui ne sont pas des fichiers
.PHONY: all clean fclean re valgrind leaks test_buffer
