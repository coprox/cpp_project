//
// GlobalVar.hpp for  in /home/tetard/eptechY2/CPP/cpp_indie_studio
//
// Made by girard
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Wed May 24 14:48:48 2017 girard
// Last update Sat Jun 17 12:59:02 2017 nicolas dejean
//

#ifndef GLOBALVAR_HPP_
# define GLOBALVAR_HPP_

#include <irrlicht.h>
#include <string>

# define MID(POS) ((POS / 2))

// --- Global window size ----------------------------------- //

static const size_t				WIDTH = 1920;
static const size_t				HEIGHT = 1080;

static const irr::core::dimension2d<irr::u32>	WINDOW_SIZE(WIDTH, HEIGHT);

// --- Path to font ---------------------------------------- //

static const irr::io::path			FONT_PATH = "media/fonts/myfont.xml";

// --- Savefile content ------------------------------------ //

static const std::string			FILE_NBR_MAP = "nbr_map:";
static const std::string			FILE_NBR_PLAYER = "nbr_player:";
static const std::string			FILE_JOYSTICK = "joystick:";
static const std::string			FILE_FULLSCREEN = "fullscreen:";

static const std::string			FILE_CHARACTER_ONE = "characterOne:";
static const std::string			FILE_CHARACTER_TWO = "characterTwo:";
static const std::string			FILE_CHARACTER_THREE = "characterThree:";
static const std::string			FILE_CHARACTER_FOUR = "characterFour:";


static const std::string			FILE_KEYS_PLAYER_ONE_UP = "KEYS_1_UP:";
static const std::string			FILE_KEYS_PLAYER_ONE_DOWN = "KEYS_1_DOWN:";
static const std::string			FILE_KEYS_PLAYER_ONE_LEFT = "KEYS_1_LEFT:";
static const std::string			FILE_KEYS_PLAYER_ONE_RIGHT = "KEYS_1_RIGHT:";
static const std::string			FILE_KEYS_PLAYER_ONE_ATTACK = "KEYS_1_ATTACK:";

static const std::string			FILE_KEYS_PLAYER_TWO_UP = "KEYS_2_UP:";
static const std::string			FILE_KEYS_PLAYER_TWO_DOWN = "KEYS_2_DOWN:";
static const std::string			FILE_KEYS_PLAYER_TWO_LEFT = "KEYS_2_LEFT:";
static const std::string			FILE_KEYS_PLAYER_TWO_RIGHT = "KEYS_2_RIGHT:";
static const std::string			FILE_KEYS_PLAYER_TWO_ATTACK = "KEYS_2_ATTACK:";

static const std::string			FILE_KEYS_PLAYER_THREE_UP = "KEYS_3_UP:";
static const std::string			FILE_KEYS_PLAYER_THREE_DOWN = "KEYS_3_DOWN:";
static const std::string			FILE_KEYS_PLAYER_THREE_LEFT = "KEYS_3_LEFT:";
static const std::string			FILE_KEYS_PLAYER_THREE_RIGHT = "KEYS_3_RIGHT:";
static const std::string			FILE_KEYS_PLAYER_THREE_ATTACK = "KEYS_3_ATTACK:";

static const std::string			FILE_KEYS_PLAYER_FOUR_UP = "KEYS_4_UP:";
static const std::string			FILE_KEYS_PLAYER_FOUR_DOWN = "KEYS_4_DOWN:";
static const std::string			FILE_KEYS_PLAYER_FOUR_LEFT = "KEYS_4_LEFT:";
static const std::string			FILE_KEYS_PLAYER_FOUR_RIGHT = "KEYS_4_RIGHT:";
static const std::string			FILE_KEYS_PLAYER_FOUR_ATTACK = "KEYS_4_ATTACk:";



// --- Menu Global variables ------------------------------- //

enum			MENU_TYPE : int
{
  ENTER_PROFIL,
  MAIN_MENU,
  OPTION,
  CREDITS,
  PLAY_GAME,
  LOAD_MAP,
  QUIT,
  CHANGE_KEYS,
  CHARACTER_SELECTION,
  START_GAME
};

enum			OPTION_TYPE : int
{
  APPLY,
  BACK_OPTION
};

enum			CHARACTER_TYPE : int
{
  WARRIOR_ONE = 0,
  HUNTER_ONE,
  SORCERER_ONE,
  WARRIOR_TWO,
  HUNTER_TWO,
  SORCERER_TWO,
  WARRIOR_THREE,
  HUNTER_THREE,
  SORCERER_THREE,
  WARRIOR_FOUR,
  HUNTER_FOUR,
  SORCERER_FOUR,
  APPLY_CHARACTER,
  BACK_CHARACTER
};

enum			PROFIL_TYPE : int
{
  APPLY_USER,
  EXIT_PROFIL
};

enum			START_TYPE : int
{
  SINGLE_PLAYER = 1,
  TWO_PLAYER,
  THREE_PLAYER,
  FOUR_PLAYER,
  MULTIPLAYER,
  BACK_START
};

enum			TEXTURE_TYPE : int
{
  BACKGROUND,
  LOGO,
  BUTTON,
  CREDITS_GAME,
  BUTTON_CLICKED,
  CHANGE_KEY,
  SINGLEPLAYER_BACKGROUND,
  MULTIPLAYER_TWO_BACKGROUND,
  MULTIPLAYER_THREE_BACKGROUND,
  MULTIPLAYER_FOUR_BACKGROUND
};

enum			CONTROL_TYPE : int
{
  PLAYER_1_UP = 112,
  PLAYER_1_DOWN,
  PLAYER_1_LEFT,
  PLAYER_1_RIGHT,
  PLAYER_1_ATTACK,
  PLAYER_2_UP,
  PLAYER_2_DOWN,
  PLAYER_2_LEFT,
  PLAYER_2_RIGHT,
  PLAYER_2_ATTACK,
  PLAYER_3_UP,
  PLAYER_3_DOWN,
  PLAYER_3_LEFT,
  PLAYER_3_RIGHT,
  PLAYER_3_ATTACK,
  PLAYER_4_UP,
  PLAYER_4_DOWN,
  PLAYER_4_LEFT,
  PLAYER_4_RIGHT,
  PLAYER_4_ATTACK,
  UNDEFINED
};

// Button sizes and texture paths

static const size_t				TEXT_SIZE_X = 300;
static const size_t				TEXT_SIZE_Y = 200;

static const size_t				TAB_SIZE_X = 1300;
static const size_t				TAB_SIZE_Y = 900;

static const size_t				BUTTON_SIZE_X = 300;
static const size_t				BUTTON_SIZE_Y = 94;

static const size_t				TITLE_UP_Y = 100;
static const size_t				TITLE_X = 665;
static const size_t				TITLE_Y = 234;

static const size_t				USERBOX_SIZE_Y = 30;
static const size_t				BUTTON_DISTANCE_Y = 50;

// static const size_t				PLAY_GAME_X = ;

// images for background

static const irr::io::path&				BACKGROUND_IMAGE = "media/textures/menu/brick_menu.jpg";
static const irr::io::path&				LOGO_IMAGE = "media/textures/menu/gauntlet_logo666.png";
static const irr::io::path&				BUTTON_TEXTURE = "media/textures/menu/button_texture.jpg";
static const irr::io::path&				BUTTON_CLICKED_TEXTURE = "media/textures/menu/menu_bright.jpg";
static const irr::io::path&				CREDITS_TEXTURE = "media/textures/menu/credits.png";

static const irr::io::path&				SINGLEPLAYER_TEXTURE = "media/textures/menu/singleplayer_background.jpg";
static const irr::io::path&				MULTIPLAYER_TWO_TEXTURE = "media/textures/menu/multiplayerTwo_background.jpg";
static const irr::io::path&				MULTIPLAYER_THREE_TEXTURE = "media/textures/menu/multiplayerThree_background.png";
static const irr::io::path&				MULTIPLAYER_FOUR_TEXTURE = "media/textures/menu/multiplayerFour_background.png";

static const irr::io::path&				CHANGE_KEY_TEXTURE = "media/textures/menu/change_key.jpg";

// path for sound menu

static const std::string				MENU_SOUND = "media/sound/menu/menu_sound.wav";

#endif /* GLOBALVAR_HPP_ */
