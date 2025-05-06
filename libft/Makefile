# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpaselt <jpaselt@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 15:04:29 by jpaselt           #+#    #+#              #
#    Updated: 2025/05/06 16:36:15 by jpaselt          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libft.a
CC          = gcc
FLAGS       = -Wall -Wextra -Werror

OBJ_DIR     = obj

SOURCES     = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
              ft_memset.c  ft_bzero.c  ft_memcpy.c  ft_memmove.c  ft_strlcpy.c  ft_strlcat.c \
              ft_strcpy.c ft_strcat.c \
              ft_toupper.c  ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
              ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
              ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
              ft_putendl_fd.c ft_putnbr_fd.c \
              get_next_line.c get_next_line_utils.c

BONUS       = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstadd_back.c \
              ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstlast.c

OBJS        = $(SOURCES:%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS  = $(BONUS:%.c=$(OBJ_DIR)/%.o)

HEADER      = libft.h
RM          = rm -f

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS) $(BONUS_OBJS)
	ar rcs $(NAME) $^

$(OBJ_DIR)/%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

bonus: all

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus