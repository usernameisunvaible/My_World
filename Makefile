##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

SRC	=	sources/main.c	\
		sources/hud/create_buttons.c	\
		sources/hud/button_action.c	\
		sources/hud/create_hud_sprite.c	\
		sources/hud/create_slide_bars.c	\
		sources/hud/hud.c	\
		sources/map.c	\
		sources/vertex.c	\
		sources/grow_map.c	\
		sources/hud/sound.c	\
		sources/hud/create_hud_text.c	\
		sources/int_into_str.c	\
		sources/non_iso_grow_tool.c	\
		sources/iso_grow_tool.c	\
		sources/grow_tools.c	\
		sources/flat_tool.c	\
		sources/tools.c	\
		sources/move_map.c	\
		sources/open.c	\
		sources/save.c	\
		sources/is_clickable.c	\
		sources/keys.c	\
		sources/save_as_ui.c	\
		sources/open_ui.c	\
		engine/sprite.c	\
		engine/textures.c	\
		engine/my_strlen.c	\
		engine/time.c	\
		engine/define_rect.c	\
		engine/init.c	\
		engine/button.c	\
		engine/define_vector.c	\
		engine/button_infos.c	\
		engine/str_comp.c	\
		engine/slide_bar.c	\
		engine/slide_bar_infos.c	\
		engine/text.c	\
		engine/framebuffer.c	\
		engine/drawing.c	\
		engine/define_vertex.c	\
		engine/square.c	\
		sources/vertex_color.c	\
		engine/text_infos.c	\
		sources/hud/button_action_two.c	\
		sources/hud/button_action_three.c	\
		sources/map_color.c

OBJ	=	$(SRC:.c=.o)
CFLAGS	+=	-g

NAME	=	my_world

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -lcsfml-graphics -lcsfml-window -lcsfml-system \
	-lcsfml-audio -lm
	rm $(OBJ)

all:	$(NAME)

clean:
	rm -fr $(OBJ)

fclean:	clean
	rm -fr $(NAME)

re:	fclean all
