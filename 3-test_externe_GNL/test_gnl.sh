#!/bin/bash


#VERIFIER QUE chmod +x test_gnl.sh

# Valeurs de BUFFER_SIZE à tester
BUFFER_SIZES=(1 8 32 9999 10000000)

# Couleurs ANSI
GRNB='\033[1;32m'
GRN='\033[0;32m'
RESET='\033[0m'

# Fichiers de test
FILES=("test_1.txt" "test_empty.txt" "test_no_newline.txt" "test_long.txt")

for size in "${BUFFER_SIZES[@]}"; do
	printf "\n$GRNB *************** BUFFER_SIZE = $size *************** $RESET\n"
	make re BUFFER_SIZE=$size > /dev/null
	for file in "${FILES[@]}"; do
		if [ -f "$file" ]; then
			printf "\n${GRN}--- Test: $file ---${RESET}\n"
			./get_next_line "$file" | head -n 3
		else
			printf "Fichier manquant : $file"
		fi
	done
done
