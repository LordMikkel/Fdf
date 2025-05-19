# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/19 17:55:34 by migarrid          #+#    #+#              #
#    Updated: 2025/05/19 18:29:02 by migarrid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                              Project Information                             #
# **************************************************************************** #
NAME				= fdf

# **************************************************************************** #
#                            Compiler and Flags                                #
# **************************************************************************** #
CC					= gcc
CFLAGS				= -Wall -Wextra -Werror -g #-fsanitize=address,undefined -O0

# **************************************************************************** #
#                               Shell Comands                                  #
# **************************************************************************** #
RM					= rm -rf
PRINTF				= printf

# **************************************************************************** #
#                              Directories                                     #
# **************************************************************************** #
INCLUDE_DIR			= inc
LIB_DIR				= lib
MAPS_DIR			= maps
OBJ_DIR				= obj
OBJ_BONUS_DIR		= obj/bonus
SRC_DIR				= src
SRC_BONUS_DIR 		= src/bonus

# **************************************************************************** #
#                      File Paths and Dependencies                             #
# **************************************************************************** #
MAKEFILE			= Makefile
HEADER				= $(INCLUDE_DIR)/fdf.h

# **************************************************************************** #
#                                   Colors                                     #
# **************************************************************************** #
DEFAULT				= \033[0;39m
GREEN 				= \033[0;92m
BLUE 				= \033[0;94m
MAGENTA 			= \033[0;95m
CYAN 				= \033[0;96m
YELLOW 				= \033[0;33m
RED 				= \033[0;31m
GREY 				= \033[38;5;240m
PURPLE 				= \033[38;5;141m
RESET 				= \033[0m
BOLD 				= \033[1m
CLEAR 				= \r\033[K

# **************************************************************************** #
#                              Progress Bars                                   #
# **************************************************************************** #
SRC_COUNT_TOT := $(shell echo -n $(SRCS) | wc -w)
ifeq ($(shell test $(SRC_COUNT_TOT) -le 0; echo $$?),0)
	SRC_COUNT_TOT := $(shell echo -n $(SRCS) | wc -w)
endif
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))

BONUS_COUNT_TOT := $(shell echo -n $(SRC_BONUS) | wc -w)
ifeq ($(shell test $(BONUS_COUNT_TOT) -le 0; echo $$?),0)
	BONUS_COUNT_TOT := $(shell echo -n $(SRC_BONUS) | wc -w)
endif
BONUS_COUNT := 0
BONUS_PCT = $(shell expr 100 \* $(BONUS_COUNT) / $(BONUS_COUNT_TOT))

# **************************************************************************** #
#                               Source File                                    #
# **************************************************************************** #
SRCS =				fdf.c \

# Rule to compile archive .c to ,o with progress bars
${OBJ_DIR}/%.o: ${SRC_DIR}/%.c ./includes/push_swap.h Makefile
	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
	@$(PRINTF) "\r%100s\r[ %d/%d (%d%%) ] Compiling $(BLUE)$<$(DEFAULT)...\n" "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
	@$(CC) $(CFLAGS) -I. -c -o $@ $<

# Rule to compile archive .c to ,o with progress bars (Bonus)
$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c ./includes/push_swap.h Makefile
	@$(eval BONUS_COUNT = $(shell expr $(BONUS_COUNT) + 1))
	@$(PRINTF) "\r%100s\r[ %d/%d (%d%%) ] Compiling $(MAGENTA)$<$(DEFAULT)...\n" "" $(BONUS_COUNT) $(BONUS_COUNT_TOT) $(BONUS_PCT)
	@$(CC) $(CFLAGS) -I. -c -o $@ $<

# **************************************************************************** #
#                               Object File                                    #
# **************************************************************************** #
OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)
OBJS_BONUS 	= $(SRC_BONUS:%.c=$(OBJ_BONUS_DIR)/%.o)

# Create the directory if it doesn't exist
${OBJS}: | ${OBJ_DIR}
${OBJS_BONUS}: |  $(OBJ_DIR)
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p ${OBJ_DIR}/bonus

# **************************************************************************** #
#                              Targets                                         #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS)

# Rule to compile bonus
bonus:

# Clean object files
clean:

# Full clean
fclean: clean

# Rebuild everything
re:

# Rebuild everything including bonus
rebonus:

# Phony targets
.PHONY: all bonus clean fclean re rebonus
.DEFAULT_GOAL := all
