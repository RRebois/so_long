# VARIABLES
NAME		=	so_long

CC			=	cc

RM			=	rm -rf

FLAGS		=	-Wall -Wextra -Werror

HEADER		=	so_long.h

HEADER_B	=	so_long_bonus.h

LIBFT		=	libft.a

MLX_LIB		=	libmlx.a

MLX_LNK		=	-L mlx -lmlx -framework OpenGL -framework AppKit

LEAKS		=	-fsanitize=address -g3

# DIRECTORIES
D_HEADER	=	incs/

D_HEADER_B	=	incs_bonus/

D_SRCS		=	SRCS/

D_SRCS_BONUS	=	SRCS_BONUS/

D_OBJS		=	objs/

D_OBJS_BONUS	=	objs_b/

D_LIBFT		=	libft/

D_MLX		=	mlx/


# FILES SO_LONG
LST_SRCS		=	main.c \
					extract_data.c \
					check.c \
					check_path.c \
					image_map.c \
					hooks.c \
					moveup.c \
					movedown.c \
					moveleft.c \
					moveright.c \
					count.c \
					close.c \
					image_door.c \
					move.c

LST_SRCS_BONUS	=	main_bonus.c \
					check_path_bonus.c \
					check_bonus.c \
					extract_data_bonus.c \
					image_map_bonus.c \
					image_extra_bonus.c \
					hooks_bonus.c \
					close_bonus.c \
					move_bonus.c \
					moveup_bonus.c \
					movedown_bonus.c \
					moveleft_bonus.c \
					moveright_bonus.c \
					count_bonus.c \
					image_door_bonus.c

LST_OBJS	=	$(LST_SRCS:.c=.o)

LST_OBJS_BONUS	=	$(LST_SRCS_BONUS:.c=.o)

SRCS		=	$(addprefix $(D_SRCS), $(LST_SRCS))

SRCS_BONUS	=	$(addprefix $(D_SRCS_BONUS), $(LST_SRCS_BONUS))

INCS		=	$(addprefix $(D_HEADER), $(HEADER))

INCS_B		=	$(addprefix $(D_HEADER_B), $(HEADER_B))

OBJS		=	$(addprefix $(D_OBJS), $(LST_OBJS))

OBJS_BONUS	=	$(addprefix $(D_OBJS_BONUS), $(LST_OBJS_BONUS))

LIBFTLIB	=	$(addprefix $(D_LIBFT), $(LIBFT))

MLXLIB		=	$(addprefix $(D_MLX), $(MLX_LIB))


# RULES
all		:	lib $(NAME)

lib :
		$(MAKE) -C $(D_LIBFT)
		$(MAKE) -C $(D_MLX)

$(NAME)	:	$(OBJS)
			$(CC) $(LEAKS) $(OBJS) $(LIBFTLIB) $(MLX_LNK) -o $(NAME)

$(D_OBJS)%.o	:	$(D_SRCS)%.c $(INCS) Makefile $(LIBFTLIB) $(MLXLIB)
					mkdir -p $(D_OBJS)
					$(CC) $(FLAGS) -I $(INCS) -c $< -o $@

clean	:
			$(RM) $(OBJS)
			$(RM) $(OBJS_BONUS)
			$(RM) $(D_OBJS)
			$(RM) $(D_OBJS_BONUS)
			$(MAKE) clean -C $(D_LIBFT)
			$(MAKE) clean -C $(D_MLX)

fclean	:
			$(MAKE) clean
			$(RM) $(NAME)
			$(MAKE) fclean -C $(D_LIBFT)

re		:	fclean all

bonus	:	$(OBJS_BONUS) lib
			$(CC) $(LEAKS) $(OBJS_BONUS) $(LIBFTLIB) $(MLX_LNK) -o $(NAME)

$(D_OBJS_BONUS)%.o	:	$(D_SRCS_BONUS)%.c $(INCS_B) Makefile $(LIBFTLIB) $(MLXLIB)
						mkdir -p $(D_OBJS_BONUS)
						$(CC) $(FLAGS) -I $(INCS_B) -c $< -o $@

.PHONY	:	all clean fclean re lib bonus
