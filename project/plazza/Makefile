##
## Makefile for y in /home/dekamor/rendu_sec/project/cpp_plazza
## 
## Made by Dkamor
## Login   <corentin.bellamy@epitech.eu>
## 
## Started on  Tue Apr 25 17:38:31 2017 Dkamor
## Last update Sun Apr 30 16:00:02 2017 Dkamor
##


NAME		=	plazza

DIR		=	src/

SRCS		=	$(DIR)main.cpp \
			$(DIR)User.cpp \
			$(DIR)Process.cpp \
			$(DIR)Mutex.cpp \
			$(DIR)Thread.cpp \
			$(DIR)Regex.cpp

OBJS		=	$(SRCS:.cpp=.o)

CC		=	g++ 

CPPFLAGS	+=	-lpthread -Wfatal-errors -W -Wall -Werror -std=c++17 -I./include

RM		=	rm -rfv

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CPPFLAGS)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
