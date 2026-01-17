# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/19 17:55:34 by migarrid          #+#    #+#              #
#    Updated: 2025/12/25 03:04:04 by migarrid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                              Project Information                             #
# **************************************************************************** #
NAME				= fdf

# **************************************************************************** #
#                            Compiler and Flags                                #
# **************************************************************************** #
CC					= clang
CFLAGS				= -Wall -Wextra -Werror -O3 -fno-math-errno -march=native -funroll-loops -flto #-g
MLXI				= -L$(MINILIBX_DIR) -lmlx -lXext -lX11 -lm

# **************************************************************************** #
#                               Shell Comands                                  #
# **************************************************************************** #
RM					= rm -rf
PRINT				= printf
MAKE				= make
MKDIR				= mkdir -p
NORM				= norminette

# **************************************************************************** #
#                              Directories                                     #
# **************************************************************************** #
INC_DIR				= inc
LIB_DIR				= lib
MAPS_DIR			= maps
OBJ_DIR				= obj
SRC_DIR				= src
LIBFT_DIR			= $(LIB_DIR)/libft_plus
MINILIBX_DIR		= $(LIB_DIR)/minilibx-linux
DEPS				= $(HEADER) $(MAKEFILE) $(LIBFT_H) $(LIBFT_MAKEFILE) $(MINILIBX_H) $(MINILIBX_MAKEFILE)

# **************************************************************************** #
#                      File Paths and Dependencies                             #
# **************************************************************************** #
MAKEFILE			= Makefile
HEADER				= $(INC_DIR)/fdf.h \
					  $(INC_DIR)/fdf_macros.h \
					  $(INC_DIR)/fdf_structs.h
LIBFT_A				= $(LIBFT_DIR)/libft_plus.a
LIBFT_H				= $(LIBFT_DIR)/libft_plus.h
LIBFT_MAKEFILE		= $(LIBFT_DIR)/Makefile
MINILIBX_A			= $(MINILIBX_DIR)/libmlx_Linux.a
MINILIBX_H			= $(MINILIBX_DIR)/mlx.h
MINILIBX_MAKEFILE	= $(MINILIBX_DIR)/Makefile

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
#                               Source File                                    #
# **************************************************************************** #
SRCS =				core/main.c \
					core/exit.c \
					core/free.c \
					core/init.c \
					core/mlx.c \
					render/render.c \
					render/draw.c \
					render/projection.c \
					render/rotation_3d.c \
					render/rotation_4d.c \
					render/traslation.c \
					render/sets1.c \
					render/sets2.c \
					render/color.c \
					render/4d.c \
					parse/parse_principal.c \
					parse/parse_calculate.c \
					parse/parse_allocate.c \
					parse/parse_value.c \
					events/events1.c \
					events/events2.c \
					menu/menu1.c \
					menu/menu2.c \
					render/utils.c \

# **************************************************************************** #
#                              Progress Bars                                   #
# **************************************************************************** #
SRC_COUNT_TOT := $(shell echo -n $(SRCS) | wc -w)
ifeq ($(shell test $(SRC_COUNT_TOT) -le 0; echo $$?),0)
	SRC_COUNT_TOT := $(shell echo -n $(SRCS) | wc -w)
endif
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))

# **************************************************************************** #
#                               Object File                                    #
# **************************************************************************** #
OBJS		= $(SRCS:%.c=$(OBJ_DIR)/%.o)

# Rule to compile archive .c to ,o with progress bars
${OBJ_DIR}/%.o: ${SRC_DIR}/%.c $(DEPS)
	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
	@$(MKDIR) $(dir $@)
	@$(PRINT) "\r%100s\r[ %d/%d (%d%%) ] Compiling $(BLUE)$<$(DEFAULT)...\n" "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
	@$(CC) $(CFLAGS) -I. -c -o $@ $<

# **************************************************************************** #
#                              Targets                                         #
# **************************************************************************** #

all: $(LIBFT_A) $(MINILIBX_A) $(NAME)

# Build fdf executable
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(MINILIBX_A) $(MLXI) -I$(INC_DIR) -o $(NAME)
	@$(PRINT) "${CLEAR}${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: ${RED}${BOLD}${NAME} ${RESET}compiled ${GREEN}successfully${RESET}.${GREY}\n${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}"

# Rebuild libft.a
$(LIBFT_A): $(LIBFT_MAKEFILE) $(LIBFT_H)
	@$(MAKE) -s -C $(LIBFT_DIR)

# Rebuild libmlx_Linux.a
$(MINILIBX_A): $(MINILIBX_MAKEFILE) $(MINILIBX_H)
	@$(MAKE) -s -C $(MINILIBX_DIR)

# Rule to compile bonus
4d: all
	@./$(NAME) tesseract
	@./$(NAME) pentachoron
	@./$(NAME) hexacosicoron

# Test the norminette in my .c files
norm:
	@$(NORM) $(SRC_DIR)
	@$(NORM) $(INC_DIR)
	@$(NORM) $(LIBFT_DIR)

# Clean object files
clean:
	@$(MAKE) clean -s -C $(LIBFT_DIR)
	@$(RM) $(OBJ_DIR)
	@$(PRINT) "${CLEAR}${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Objects were cleaned ${GREEN}successfully${RESET}.\n${RESET}"

# Full clean
fclean: clean
	@$(MAKE) fclean -s -C $(LIBFT_DIR)
	@$(RM) $(NAME)
	@$(PRINT) "${CLEAR}${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}${GREEN}»${RESET} [${PURPLE}${BOLD}${NAME}${RESET}]: Project cleaned ${GREEN}successfully${RESET}.${GREY}\n${RESET}${GREY}────────────────────────────────────────────────────────────────────────────\n${RESET}"

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all 4d clean fclean re
.DEFAULT_GOAL := all
