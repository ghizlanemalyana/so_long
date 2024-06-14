NAME = so_long

SRCS = $(shell find src -name "*.c") lib/get_next_line/get_next_line.c lib/get_next_line/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
LIBRARY = -lmlx -framework OpenGL -framework AppKit
INC = includes/so_long.h
CFLAGS = #-Wall -Wextra -Werror 
LIBFT = lib/libft/libft.a
FT_PRINTF = lib/ft_printf/libftprintf.a

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT) $(FT_PRINTF)
	cc $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) $(LIBRARY) -o $(NAME)

%.o : %.c $(INC)
	cc $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C lib/libft/

$(FT_PRINTF):
	make -C lib/ft_printf/

clean :
	make clean -C lib/libft/
	make clean -C lib/ft_printf/
	$(RM) $(OBJS)

fclean : clean
	make fclean -C lib/libft/
	make fclean -C lib/ft_printf/
	$(RM) $(NAME)

re : fclean all