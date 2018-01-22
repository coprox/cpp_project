##
## Makefile for irc in /home/margue_m/rendu/tmp/good_root_INDIE
## 
## Made by Mattéo Margueritte
## Login   <margue_m@epitech.net>
## 
## Started on  Mon Jun 12 16:03:41 2017 Mattéo Margueritte
## Last update Sun Jun 18 20:40:01 2017 Mattéo Margueritte
##

BLUE		=	\033[1;34m

CYAN		=	\033[1;36m

RED		=	\033[1;31m

RESET		=	\033[0m

DIR		=	source/

MENU		=	source/menu/

SRC		=	$(MENU)Menu.cpp					\
			$(MENU)AMenuType.cpp				\
			$(MENU)CreditsMenuType.cpp			\
			$(MENU)LoadMenuType.cpp				\
			$(MENU)MainMenuType.cpp				\
			$(MENU)OptionMenuType.cpp			\
			$(MENU)ProfilMenuType.cpp			\
			$(MENU)StartGameMenuType.cpp			\
			$(MENU)MenuSaveFile.cpp				\
			$(MENU)ChangeKeysMenuType.cpp			\
			$(MENU)CharacterSelectionMenuType.cpp		\
			$(MENU)PlayerSettings.cpp			\
			$(MENU)Settings.cpp				\
			$(DIR)Sound.cpp					\
			$(DIR)VideoPlayer.cpp				\
			$(DIR)Camera.cpp				\
			$(DIR)Game.cpp					\
			$(DIR)GameLevel.cpp				\
			$(DIR)PlayersGame.cpp				\
			$(DIR)initPlayers.cpp				\
			$(DIR)main.cpp					\
	  		$(DIR)Map.cpp					\
	  		$(DIR)MapLoader.cpp				\
	  		$(DIR)MyEventReceiver.cpp			\
			$(DIR)Timer.cpp					\
			$(DIR)ACharacter.cpp				\
			$(DIR)Mage.cpp					\
			$(DIR)Hunter.cpp				\
			$(DIR)Warrior.cpp				\
			$(DIR)Projectile.cpp				\
			$(DIR)AGenerator.cpp				\
			$(DIR)ArachneGenerator.cpp			\
			$(DIR)Arachne.cpp				\
			$(DIR)LifeBar.cpp				\
			$(DIR)XpBar.cpp					\

RM		=	rm -f

CXXFLAGS	+=	-W -Wall -Wextra -std=c++14 -Wfatal-errors

CXXFLAGS	+=	-I include -I include/menu -isystem include/irrlicht -I include/irrKlang

LDFLAGS		+=	-L./lib -lIrrlicht -L./lib -lGL -lXxf86vm -lX11 ./lib/libIrrKlang.so

I_DIR		=	include/

CFLAGS		+=	-I $(I_DIR)

GXX		=	g++

OBJS		=	$(SRC:.cpp=.o)

NAME		=	indie

ECHO		=	echo -e

%.o: %.cpp
	@$(GXX) $(CXXFLAGS) -c -o $@ $<
	@$(ECHO) "${BLUE}[${CYAN}OK${BLUE}]" $@ "${RESET}"

all: $(NAME) $(CLIENT)

debug: CXXFLAGS += -g3
debug: fclean $(NAME)

$(NAME): $(OBJS)
	@$(GXX) -o $(NAME) $(OBJS) $(LDFLAGS)
	@$(ECHO) "${RED}${NAME} ${BLUE}Compiled${RESET}"

clean:
	@$(RM) $(OBJS)
	@$(ECHO) "${RED}Objects${BLUE} Cleaned${RESET}"

fclean: clean
	@$(RM) $(NAME)
	@$(ECHO) "${RED}${NAME} ${BLUE} Cleaned${RESET}"

re: fclean all

.PHONY: all clean fclean re
