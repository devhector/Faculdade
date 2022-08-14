NAME = esc

LIBFT_PATH		= /libft
LIBFT			= $(LIBFT_PATH)/libft.a

INCLUDE_PATH	= includes

CC 				= @gcc
CFLAGS			= -Wall -Werror -Wextra -g

LFLAGS			=-L $(LIBFT_PATH) -lft

CFLAGS			+= $(addprefix -I , $(INCLUDE_PATH))

vpath %.h $(INCLUDE_PATH) $(LIBFT_PATH)

vpath %.c	src 

SRC =	main.c 

RM = @rm -rf

OBJ_DIR = obj

OBJ =	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(OBJ)
	@echo "Creating $(NAME)"
	$(CC) -o $(NAME) $(OBJ) $(LFLAGS)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH) bonus

$(OBJ_DIR)/%.o: %.c
	@echo "Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

v:	all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes \
	 --verbose -q ./$(NAME)

r:	all
	clear
	./$(NAME)

debug: all
	@gdb $(NAME)

.PHONY: all clean fclean re r v debug