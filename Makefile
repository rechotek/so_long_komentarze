MAKEFLAGS += -s
NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

UTILS = utils.c error_free.c
SRCS = so_long.c array_map.c check_map/check_map.c check_map/check_characters.c check_map/check_rectangular.c \
		check_map/check_border.c check_map/check_way.c start_game/start_game.c start_game/fill_textures.c \
		start_game/events.c $(UTILS)
OBJS = $(SRCS:.c=.o)

LIB_DIRS = libs/libft libs/ft_printf libs/minilibx
LIBS = ft ftprintf mlx Xext X11
LDFLAGS_LIBS = $(addprefix -L, $(LIB_DIRS)) $(addprefix -l, $(LIBS))

##MINILIBX_REPO = https://github.com/42Paris/minilibx-linux.git
##MINILIBX_DIR = libs/minilibx

all: $(MINILIBX_DIR) $(LIBS) $(NAME)

$(MINILIBX_DIR):
	@if [ ! -d "$(MINILIBX_DIR)" ]; then \
		git clone $(MINILIBX_REPO) $(MINILIBX_DIR); \
	fi

$(LIBS):
	$(foreach dir, $(LIB_DIRS), make -C $(dir);)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LDFLAGS_LIBS) -o $@
	$(MAKE) clean

clean:
	$(RM) $(OBJS)
	$(foreach dir, $(LIB_DIRS), $(RM) $(dir)/*.a)

fclean: clean
	$(RM) $(NAME)

.PHONY: all clean fclean re $(MINILIBX_DIR)