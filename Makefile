# **************************************************************************** #
#                                  CONFIGURATION                               #
# **************************************************************************** #

NAME        = so_long
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror

SRC_DIR     = src
OBJ_DIR     = src/obj
LIBFT_DIR   = libft
MLX_DIR     = minilibx-linux

LIBFT       = $(LIBFT_DIR)/libft.a
MLX         = $(MLX_DIR)/libmlx.a

# **************************************************************************** #
#                                SOURCE FILES                                  #
# **************************************************************************** #

SRCS        = $(wildcard $(SRC_DIR)/*.c)
OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ_DIR) $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -L$(MLX_DIR) -lXext -lX11 -lm -lXrandr -lXcursor -lGL -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(MLX_DIR) -I$(SRC_DIR) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
