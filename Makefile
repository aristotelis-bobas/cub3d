#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: abobas <marvin@codam.nl>                     +#+                      #
#                                                    +#+                       #
#    Created: 2020/01/12 02:10:28 by abobas        #+#    #+#                  #
#    Updated: 2020/02/26 19:29:38 by abobas        ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME = cub3D

NAME_BONUS = cub3D_bonus

SRC := main.c check_input.c error.c \
		struct_1.c struct_2.c struct_3.c struct_4.c struct_5.c \
		parser_1.c parser_2.c parser_3.c parser_4.c \
		parser_5.c parser_6.c parser_7.c parser_8.c \
		hooks_1.c hooks_2.c hooks_3.c \
		image_1.c image_2.c image_3.c \
		sprite_1.c sprite_2.c \
		screenshot.c \
		differential_analysis.c \
		utilities_1.c utilities_2.c \

SRC := $(SRC:%=srcs/%)

SRC_BONUS := main.c check_input.c error.c \
		struct_1.c struct_2.c struct_3.c \
		struct_4.c struct_5.c struct_6.c struct_7.c \
		parser_1.c parser_2.c parser_3.c \
		parser_4.c parser_6.c parser_7.c parser_8.c \
		hooks_1.c hooks_2.c hooks_3.c hooks_4.c hooks_5.c \
		image_1.c image_2.c image_3.c image_4.c \
		sprite_1.c sprite_2.c sprite_3.c sprite_4.c sprite_5.c \
		boss_fight_1.c boss_fight_2.c boss_fight_3.c \
		screenshot.c \
		hud_1.c hud_2.c hud_3.c hud_4.c \
		hud_5.c hud_6.c hud_7.c hud_8.c \
		differential_analysis.c \
		utilities_1.c utilities_2.c \

SRC_BONUS := $(SRC_BONUS:%=bonus/%)

FLAGS = -Wall -Werror -Wextra -lmlx -L . -framework OpenGL -framework Appkit \
		-Ofast -march=native

MLXDIR = ./mlx/

all: $(NAME)

$(NAME):
	make -C $(MLXDIR)
	cp ./mlx/libmlx.dylib .
	make clean -C $(MLXDIR)
	gcc $(FLAGS) $(SRC) -o $(NAME)

$(NAME_BONUS):
	make -C $(MLXDIR)
	cp ./mlx/libmlx.dylib .
	make clean -C $(MLXDIR)
	gcc $(FLAGS) $(SRC_BONUS) -o $(NAME_BONUS)

run:
	./cub3D maps/mandatory.cub

run_bonus:
	./cub3D_bonus maps/bonus.cub

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)
	rm -rf libmlx.dylib
	rm -rf screenshot.bmp

re: fclean all
