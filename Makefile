NAME = so_long

# Compile

CC = clang
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
BUFFER = 64

# MINILIBX

MLX_DIR = minilibx-linux
MLX = libmlx.a

# LIBFT

LIBFT_DIR = libft
LIBFT = libft.a

# Path

DIR_BUILD = build/
DIR_SRCS = srcs/
DIR_HEADERS = headers/


SRCS_SO_LONG = main.c \
		error/error.c \
		utils/utils.c utils/utils_ft.c \
		close.c file.c initialize.c settings.c parsing.c
SRCS = $(addprefix $(DIR_SRCS), $(SRCS_SO_LONG:.c=.o))

OBJS = $(addprefix $(DIR_BUILD), $(patsubst %.c,%.o,$(SRCS)))

Black = \e[1;30m
Red = \e[1;31m
Green = \e[1;32m
Yellow = \e[1;33m
Blue = \e[1;34m
Magenta = \e[1;35m
Cyan = \e[1;36m
Light_gray = \e[1;37m
Dark_gray = \e[1;90m
White = \e[1;97m
End = \e[1;0m

all :	$(LIBFT) start $(NAME)
		@echo "$(Green)__________$(NAME) OK____________$(End)"

$(LIBFT) :
	@make -sC $(LIBFT_DIR)

$(DIR_BUILD)% :
	@mkdir -p $@
	@echo "$(Blue)$@ Created$(End)"

.SECONDEXPANSION:


$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(LIBFT_DIR) -lft -L $(MLX_DIR) -lmlx -lm -lbsd -lX11 -lXext
	@echo "$(Green)MAKE\033[5C->\033[5C$@$(End)"

$(OBJS) : $(DIR_BUILD)%.o:%.c | $$(@D)/
		@mkdir -p $(DIR_BUILD)
		@echo "$(Cyan)BUILDING\033[5C->\033[5C$<$(End)"
		@${CC} $(CFLAGS) -D BUFFER_SIZE=$(BUFFER) -I $(DIR_HEADERS) -I $(LIBFT_DIR) -I $(MLX_DIR) -c $< -o $@

start:
	@echo "$(Green)__________$(NAME)____________$(End)"

clean :
	@make clean -sC $(LIBFT_DIR)
	@rm -rf $(DIR_BUILD)
	@echo "$(Red)REMOVE SO_LONG\033[3C->\033[5C$(DIR_BUILD)$(End)"



fclean :
	@make fclean -sC $(LIBFT_DIR)
	@rm -rf $(NAME)
	@rm -rf $(DIR_BUILD)
	@echo "$(Red)REMOVE SO_LONG\033[3C->\033[5C$(DIR_BUILD)$(End)"
	@echo "$(Red)REMOVE SO_LONG\033[3C->\033[5C$(NAME)$(End)"

re : fclean all

.PHONY : all clean fclean re
