# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amarchal <amarchal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 15:06:58 by amarchal          #+#    #+#              #
#    Updated: 2022/09/26 10:20:33 by amarchal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		:= sandbox
CC 			:= c++
CFLAGS	 	:= -Wall -Wextra -Werror 
LDFLAGS		:= -lglfw -lGL -lGLEW

DIR_SRCS	:= ./srcs
DIR_OBJS	:= ./objs
DIR_INCS	:= ./incs

LST_SRCS	:=	main.cpp		\
				validators.cpp	\
				utils.cpp		\
				partOnClick.cpp	\
				render.cpp		\
				shaderClass.cpp \
				VAO.cpp			\
				VBO.cpp			\
				EBO.cpp			\
				particule.cpp	\
				Element.cpp		\
				Solid.cpp		\
				Liquid.cpp		\
				Water.cpp		\
				Sand.cpp		\
				Stone.cpp		\
				Void.cpp		\
				Air.cpp		\
				callback.cpp
		
LST_INCS	:=	shaderClass.hpp \
				VAO.hpp			\
				VBO.hpp			\
				EBO.hpp			\
				particule.hpp	\
				Element.hpp		\
				Solid.hpp		\
				Liquid.hpp		\
				Water.hpp		\
				Sand.hpp		\
				Stone.hpp		\
				Air.hpp		\
				Void.hpp		\
				sandbox.hpp
			
LST_OBJS := $(LST_SRCS:.cpp=.o)

SRCS := $(addprefix $(DIR_SRCS)/, $(LST_SRCS))
OBJS := $(addprefix $(DIR_OBJS)/, $(LST_OBJS))
INCS := $(addprefix $(DIR_INCS)/, $(LST_INCS))

all : $(NAME)

$(NAME) : $(OBJS) $(INCS) Makefile
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

$(DIR_OBJS):
		mkdir -p $(DIR_OBJS)

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.cpp $(INCS) Makefile | $(DIR_OBJS)
		$(CC) $(CFLAGS) -c $< -o $@

clean :
		rm -rf $(OBJS)
		rm -rf $(DIR_OBJS)

fclean : clean
		rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re