NAME = so_long
SRCS =	get_next_line.c \
		get_next_line_utils.c \
		ft_check_map.c \
		ft_parse_map.c \
		ft_draw.c moves.c \
		ft_error_handle.c \
		ft_display_end_of_game.c \
		keys.c \
		moves2.c \
		ft_moves_counter.c \
		ft_check_file_name.c \
		main.c \

OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(MLX) $(OBJS)
all : $(NAME)
clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all
.PHONY : all clean flcean re
