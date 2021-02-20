# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/19 23:12:58 by lsuardi           #+#    #+#              #
#    Updated: 2021/02/20 20:59:58 by lsuardi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL =		/bin/sh
.SUFFIXES =	.c .h .o

NAME =		Necklace

SRCD =		src
INCD =		inc
OBJD =		.obj

SRC =		$(addsuffix $(word 1, $(.SUFFIXES)),\
			main\
			necklace\
			utils)
INC =		$(addsuffix $(word 2, $(.SUFFIXES)),\
			necklace)
OBJ =		$(SRC:$(word 1, $(.SUFFIXES))=$(word 3, $(.SUFFIXES)))

CC =		gcc
CFLAGS =	-Wall\
			-Werror\
			-Wextra\
			-I $(INCD)

COUNT =		$(shell cat file.count 2>/dev/null)

ifeq ($(COUNT),)
all:
	@echo $(words $(SRC)) > file.count && $(MAKE) -n | grep $(CC) | wc -l | tr -d ' ' > tmp.txt && rm -f file.count && echo $$(($$(cat tmp.txt) - 1)) > file.count && rm -f tmp.txt && $(MAKE)
else
all: $(NAME)
endif

$(NAME): $(addprefix $(OBJD)/, $(OBJ)) | $(addprefix $(INCD)/, $(INC))
	@rm -f file.count && $(CC) $(CFLAGS) $^ -o $@ && echo '\r\033[2KCompiling [100%]'

$(OBJD):
	@mkdir $@

$(OBJD)/%.o: $(SRCD)/%.c | $(OBJD)
	@./prc.sh && $(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJD) file.count

fclean: clean
	@rm -f $(NAME)

re: fclean all
