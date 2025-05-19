# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: migarrid <migarrid@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/28 19:51:37 by migarrid          #+#    #+#              #
#    Updated: 2025/04/12 03:28:23 by migarrid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre de la biblioteca
NAME = libft_plus.a

# Compilador y opciones
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Colores
DEFAULT = \033[0;39m
GREEN = \033[0;92m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m

# Comandos
PRINTF = printf
RM = rm -f

# Archivos fuente obligatorios
SRCS =	libft/ft_isalpha.c \
		libft/ft_isdigit.c \
		libft/ft_isalnum.c \
		libft/ft_isascii.c \
		libft/ft_isprint.c \
		libft/ft_strlen.c \
		libft/ft_memset.c \
		libft/ft_bzero.c \
		libft/ft_memcpy.c \
		libft/ft_memmove.c \
		libft/ft_strlcpy.c \
		libft/ft_strlcat.c \
		libft/ft_toupper.c \
		libft/ft_tolower.c \
		libft/ft_strchr.c \
		libft/ft_strrchr.c \
		libft/ft_strcmp.c \
		libft/ft_strncmp.c \
		libft/ft_memchr.c \
		libft/ft_memcmp.c \
		libft/ft_strnstr.c \
		libft/ft_atoi.c \
		libft/ft_atol.c \
		libft/ft_calloc.c \
		libft/ft_strdup.c \
		libft/ft_substr.c \
		libft/ft_strjoin.c \
		libft/ft_strtrim.c \
		libft/ft_split.c \
		libft/ft_itoa.c \
		libft/ft_strmapi.c \
		libft/ft_striteri.c \
		libft/ft_putchar_fd.c \
		libft/ft_putstr_fd.c \
		libft/ft_putendl_fd.c \
		libft/ft_putnbr_fd.c \
		libft/ft_lstnew_bonus.c \
		libft/ft_lstadd_front_bonus.c \
		libft/ft_lstsize_bonus.c \
		libft/ft_lstlast_bonus.c \
		libft/ft_lstadd_back_bonus.c \
		libft/ft_lstdelone_bonus.c \
		libft/ft_lstclear_bonus.c \
		libft/ft_lstiter_bonus.c \
		libft/ft_lstmap_bonus.c \
		ft_printf/ft_printf_bonus.c \
		ft_printf/ft_apply_flags_bonus.c \
		ft_printf/ft_apply_hash_bonus.c \
		ft_printf/ft_apply_left_align_bonus.c \
		ft_printf/ft_apply_plus_bonus.c \
		ft_printf/ft_apply_precision_bonus.c \
		ft_printf/ft_apply_space_bonus.c \
		ft_printf/ft_apply_zero_pad_bonus.c \
		ft_printf/ft_apply_min_width_bonus.c \
		ft_printf/ft_print_char_bonus.c \
		ft_printf/ft_print_str_bonus.c \
		ft_printf/ft_print_ptr_bonus.c \
		ft_printf/ft_print_num_bonus.c \
		ft_printf/ft_print_unsigned_bonus.c \
		ft_printf/ft_print_hex_bonus.c \
		ft_printf/ft_itoa_base_bonus.c \
		ft_printf/ft_utoa_bonus.c \
		get_next_line/get_next_line_bonus.c \


# Objetos obligatorios
OBJS = $(SRCS:.c=.o)

# Variables de progreso
SRC_COUNT_TOT := $(shell echo -n $(SRCS) | wc -w)
ifeq ($(shell test $(SRC_COUNT_TOT) -le 0; echo $$?),0)
	SRC_COUNT_TOT := $(shell echo -n $(SRCS) | wc -w)
endif
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))

# Regla principal: compilar la biblioteca
all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

# Regla para compilar archivos .c a .o con barra de progreso
%.o: %.c libft_plus.h Makefile
	@$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
	@$(PRINTF) "\r%100s\r[ %d/%d (%d%%) ] Compiling $(BLUE)$<$(DEFAULT)..." "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
	@$(CC) $(CFLAGS) -I. -c -o $@ $<

# Limpiar objetos
clean:
	@$(RM) $(OBJS)

# Limpiar todo (objetos + biblioteca)
fclean: clean
	@$(RM) $(NAME)
	@$(RM) ../$(NAME)

# Recompilar todo desde cero sin bonus
re: fclean all

# Asegurar que las reglas se ejecuten como comandos del make
.PHONY: all clean fclean re bonus rebonus
