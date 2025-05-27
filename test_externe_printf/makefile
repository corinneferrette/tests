# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cferrett <cferrett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/19 17:37:37 by cferrett          #+#    #+#              #
#    Updated: 2025/05/27 19:00:26 by cferrett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== Variables =====
PATH_FILE = .path_file
SRC = main.c test_c.c test_s.c test_d_i.c test_p.c test_u.c test_x_X.c test_percent.c
OBJ = $(SRC:.c=.o)
EXE = test_exec
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -I$(PATH_PRINTF) -I$(PATH_PRINTF)/libft

# ===== Chargement du chemin depuis .path_file =====
-include $(PATH_FILE)

# ===== Règle : définir le chemin vers ft_printf =====
set:
	@read -p "Chemin vers ft_printf (ex: ../ft_printf) : " path && \
	echo "PATH_PRINTF=$$path" > $(PATH_FILE) && \
	echo "→ Chemin enregistré dans $(PATH_FILE)"

# ===== Règle : vérification que PATH_PRINTF est défini =====
check_path:
	@if [ -z "$(PATH_PRINTF)" ]; then \
		echo "PATH_PRINTF non défini. Lancez 'make set' d'abord."; \
		exit 1; \
	fi

# ===== Règle principale =====
all: check_path $(EXE)

# ===== Compilation de l’exécutable =====
$(EXE): $(OBJ)
	@make -C $(PATH_PRINTF)
	$(CC) $(CFLAGS) $(OBJ) \
	$(PATH_PRINTF)/libftprintf.a \
	$(PATH_PRINTF)/libft/libft.a \
	-o $(EXE)
	@echo "Exécutable $(EXE) généré"

# ===== Compilation des .o =====
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "→ Compilé : $<"

# ===== Lancement du programme =====
run: all
	@./$(EXE)

# ===== Nettoyage =====
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXE)

re: fclean all

# ======= Lancer avec valgrind ==========
valgrind: $(EXE)
	@echo "Test avec valgrind"
	valgrind --leak-check=full --track-origins=yes ./$(NAME)


.PHONY: all set clean fclean re run valgrind
