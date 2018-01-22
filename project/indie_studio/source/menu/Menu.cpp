//
// Menu.cpp for  in /home/tetard/eptechY2/CPP/cpp_indie_studio
//
// Made by girard
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Thu Jun  1 14:45:27 2017 girard
// Last update Sun Jun 18 20:25:37 2017 nicolas dejean
//

#include <iostream>
#include "Menu.hpp"

extern Sound sound;

Menu::Menu(void) :
  _tmp_opt(),
  _opt(),
  _key(NULL),
  _key_type(UNDEFINED),
  _device(irr::createDevice(irr::video::EDT_OPENGL, _opt.getDeskres(), 32,
  			    false, false, false, 0)),
  _driver(_device->getVideoDriver()),
  _current_type(ENTER_PROFIL),
  _new_type(_current_type),
  _textureList({
      { BACKGROUND, _driver->getTexture(BACKGROUND_IMAGE)},
      { LOGO, _driver->getTexture(LOGO_IMAGE)},
      { BUTTON, _driver->getTexture(BUTTON_TEXTURE) },
      { BUTTON_CLICKED, _driver->getTexture(BUTTON_CLICKED_TEXTURE) },
      { CREDITS_GAME, _driver->getTexture(CREDITS_TEXTURE) },
      { SINGLEPLAYER_BACKGROUND, _driver->getTexture(SINGLEPLAYER_TEXTURE) },
      { MULTIPLAYER_TWO_BACKGROUND, _driver->getTexture(MULTIPLAYER_TWO_TEXTURE) },
      { MULTIPLAYER_THREE_BACKGROUND, _driver->getTexture(MULTIPLAYER_THREE_TEXTURE) },
      { MULTIPLAYER_FOUR_BACKGROUND, _driver->getTexture(MULTIPLAYER_FOUR_TEXTURE) },
      { CHANGE_KEY, _driver->getTexture(CHANGE_KEY_TEXTURE) }
    }),
  _menuList({
      { MAIN_MENU, std::make_shared< MainMenuType >(_device) },
      { OPTION, std::make_shared< OptionMenuType >(_device) },
      { PLAY_GAME, std::make_shared< StartGameMenuType >(_device) },
      { CREDITS, std::make_shared< CreditsMenuType >(_device) },
      { ENTER_PROFIL, std::make_shared< ProfilMenuType >(_device) },
      { LOAD_MAP, std::make_shared< LoadMenuType >(_device) },
      { CHARACTER_SELECTION, std::make_shared< CharacterSelectionMenuType >(_device) },
      { CHANGE_KEYS, std::make_shared< ChangeKeysMenuType >(_device) }
    }),
  _eventMap({
      { MAIN_MENU, (&Menu::menuEvent) },
      { OPTION, (&Menu::optionEvent) },
      { PLAY_GAME, (&Menu::playEvent) },
      { CREDITS, (&Menu::creditsEvent) },
      { ENTER_PROFIL, (&Menu::profilEvent) },
      { LOAD_MAP, (&Menu::loadEvent) },
      { CHARACTER_SELECTION, (&Menu::characterSelectionEvent) },
      { CHANGE_KEYS, (&Menu::changeKeysEvent) }
    })
{
   _device->setWindowCaption(L"Gauntlet");
   sound.setSound(MENU_SOUND, true);
}

Menu::Menu(const Settings& settings) :
  _tmp_opt(),
  _opt(),
  _key(NULL),
  _key_type(UNDEFINED),
  _device(irr::createDevice(irr::video::EDT_OPENGL, _opt.getDeskres(), 32,
			    false, false, false, 0)),
  _driver(_device->getVideoDriver()),
  _current_type(MAIN_MENU),
  _new_type(_current_type),
  _textureList({
      { BACKGROUND, _driver->getTexture(BACKGROUND_IMAGE)},
      { LOGO, _driver->getTexture(LOGO_IMAGE)},
      { BUTTON, _driver->getTexture(BUTTON_TEXTURE) },
      { BUTTON_CLICKED, _driver->getTexture(BUTTON_CLICKED_TEXTURE) },
      { CREDITS_GAME, _driver->getTexture(CREDITS_TEXTURE) },
      { SINGLEPLAYER_BACKGROUND, _driver->getTexture(SINGLEPLAYER_TEXTURE) },
      { MULTIPLAYER_TWO_BACKGROUND, _driver->getTexture(MULTIPLAYER_TWO_TEXTURE) },
      { MULTIPLAYER_THREE_BACKGROUND, _driver->getTexture(MULTIPLAYER_THREE_TEXTURE) },
      { MULTIPLAYER_FOUR_BACKGROUND, _driver->getTexture(MULTIPLAYER_FOUR_TEXTURE) },
      { CHANGE_KEY, _driver->getTexture(CHANGE_KEY_TEXTURE) }
    }),
  _menuList({
      { MAIN_MENU, std::make_shared< MainMenuType >(_device) },
      { OPTION, std::make_shared< OptionMenuType >(_device) },
      { PLAY_GAME, std::make_shared< StartGameMenuType >(_device) },
      { CREDITS, std::make_shared< CreditsMenuType >(_device) },
      { ENTER_PROFIL, std::make_shared< ProfilMenuType >(_device) },
      { LOAD_MAP, std::make_shared< LoadMenuType >(_device) },
      { CHARACTER_SELECTION, std::make_shared< CharacterSelectionMenuType >(_device) },
      { CHANGE_KEYS, std::make_shared< ChangeKeysMenuType >(_device) }
    }),
  _eventMap({
      { MAIN_MENU, (&Menu::menuEvent) },
      { OPTION, (&Menu::optionEvent) },
      { PLAY_GAME, (&Menu::playEvent) },
      { CREDITS, (&Menu::creditsEvent) },
      { ENTER_PROFIL, (&Menu::profilEvent) },
      { LOAD_MAP, (&Menu::loadEvent) },
      { CHARACTER_SELECTION, (&Menu::characterSelectionEvent) },
      { CHANGE_KEYS, (&Menu::changeKeysEvent) }
    })
{
   _device->setWindowCaption(L"Gauntlet");
   _opt = settings;
   _tmp_opt = settings;
   _opt._playerOne.setCharacter(WARRIOR_ONE);
   _opt._playerTwo.setCharacter(WARRIOR_ONE);
   _opt._playerThree.setCharacter(WARRIOR_ONE);
   _opt._playerFour.setCharacter(WARRIOR_ONE);
   sound.setSound(MENU_SOUND, true);
}

bool				Menu::runMenu(void)
{
  _menuList[_current_type]->setMenu(_textureList);
  while (_device->run())
  {
    _driver->beginScene();
    _device->setEventReceiver(this);
    _menuList[_current_type]->getEnv()->drawAll();
    _driver->endScene();
    if (_current_type != _new_type)
    {
      _current_type = _new_type;
      return (runMenu());
    }
  }
  sound.setPause();
  _device->drop();
  if (_current_type == START_GAME || _new_type == START_GAME)
    return (true);
  return (false);
}

void				Menu::menuEvent(const irr::SEvent& event)
{
  if (event.EventType == irr::EET_KEY_INPUT_EVENT &&
      event.KeyInput.Key == irr::KEY_ESCAPE &&
      event.KeyInput.PressedDown == false)
    _device->closeDevice();

  else if (event.EventType == irr::EET_GUI_EVENT)
  {
    irr::s32			id = event.GUIEvent.Caller->getID();
    switch(id)
    {
    case 1:
      if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
      {
	_menuList[_new_type]->getMenuButton()[PLAY_GAME]->setImage(_textureList[BUTTON_CLICKED]);
	_new_type = PLAY_GAME;
      }
      break;
    case 2:
      if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
      {
	_menuList[_new_type]->getMenuButton()[OPTION]->setImage(_textureList[BUTTON_CLICKED]);
  	_new_type = OPTION;
      }
      break;
    case 3:
      if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED) {
	_menuList[_new_type]->getMenuButton()[CREDITS]->setImage(_textureList[BUTTON_CLICKED]);
	_new_type = CREDITS;
      }
      break;
    case 4:
      if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
      	_device->closeDevice();
      break;
    default:
      break;
    }
    _menuList[_new_type]->setSettings(_opt);
    _tmp_opt = _opt;
  }
}

void				Menu::changeKeysEvent(const irr::SEvent& event)
{
  if (event.EventType == irr::EET_KEY_INPUT_EVENT &&
      event.KeyInput.Key == irr::KEY_ESCAPE &&
      event.KeyInput.PressedDown == false)
  {
    _new_type = OPTION;
    return _menuList[_new_type]->setSettings(_tmp_opt);
  }

  else if (event.EventType == irr::EET_KEY_INPUT_EVENT &&
	   event.KeyInput.Key != irr::KEY_ESCAPE)
  {
    _new_type = OPTION;
    std::string			str(1, static_cast<unsigned char>(event.KeyInput.Key));
    removeKeyTaken(str);
    if (_key_type <= PLAYER_1_ATTACK)
      (this->_tmp_opt._playerOne.*_key)(str);
    else if (_key_type <= PLAYER_2_ATTACK)
      (this->_tmp_opt._playerTwo.*_key)(str);
    else if (_key_type <= PLAYER_3_ATTACK)
      (this->_tmp_opt._playerThree.*_key)(str);
    else if (_key_type <= PLAYER_4_ATTACK)
      (this->_tmp_opt._playerFour.*_key)(str);
    _menuList[_new_type]->setSettings(_tmp_opt);
  }
}

void				Menu::optionEvent(const irr::SEvent& event)
{
  if (event.EventType == irr::EET_KEY_INPUT_EVENT &&
      event.KeyInput.Key == irr::KEY_ESCAPE &&
      event.KeyInput.PressedDown == false)
    _new_type = MAIN_MENU;

  /* FOR CONTROL CHANGE */
  else if (event.EventType == irr::EET_GUI_EVENT)
  {
    irr::s32			id = event.GUIEvent.Caller->getID();
    switch(id)
    {
    case 100:
      if (event.GUIEvent.EventType == irr::gui::EGET_CHECKBOX_CHANGED)
	_tmp_opt.setFullscreen(((irr::gui::IGUICheckBox*)event.GUIEvent.Caller)->isChecked());
      break;
    case 101:
      if (event.GUIEvent.EventType == irr::gui::EGET_CHECKBOX_CHANGED)
	_tmp_opt.setJoystick(((irr::gui::IGUICheckBox*)event.GUIEvent.Caller)->isChecked());
      break;
    case 110:
      if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
      {
	/* SAVE BOOl TO SETTINGS*/
	_menuList[_new_type]->getOptButton()[APPLY]->setImage(_textureList[BUTTON_CLICKED]);
	_opt = _tmp_opt;
	overwriteSaveFile(_opt.getUserName());
 	_new_type = MAIN_MENU;
      }
      break;
    case 111:
      if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
      {
	_menuList[_new_type]->getOptButton()[BACK_OPTION]->setImage(_textureList[BUTTON_CLICKED]);
	_tmp_opt = _opt;
  	_new_type = MAIN_MENU;
      }
      break;
    default:
      break;
    }

    /* FOR CONTROL CHANGE */
    for (auto it = _opt._replace.begin(); it != _opt._replace.end(); ++it)
      if (id == it->first)
      {
	if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
	{
	  _key_type = it->first;
	  _key = it->second;
	  _new_type = CHANGE_KEYS;
	}
      }
    _menuList[_new_type]->setSettings(_opt);
  }
}

void				Menu::creditsEvent(const irr::SEvent& event)
{
  if (event.EventType == irr::EET_KEY_INPUT_EVENT &&
      event.KeyInput.Key == irr::KEY_ESCAPE &&
      event.KeyInput.PressedDown == false)
    _new_type = MAIN_MENU;
  else if (event.EventType == irr::EET_GUI_EVENT) {
    if (event.GUIEvent.Caller->getID() == 300)
      if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
	_new_type = MAIN_MENU;
    _menuList[_new_type]->setSettings(_opt);
  }
}

void				Menu::loadEvent(const irr::SEvent& event)
{
  if (event.EventType == irr::EET_KEY_INPUT_EVENT &&
      event.KeyInput.Key == irr::KEY_ESCAPE &&
      event.KeyInput.PressedDown == false)
    _new_type = CHARACTER_SELECTION;
    else if (event.EventType == irr::EET_GUI_EVENT)
  {
    irr::s32			id = event.GUIEvent.Caller->getID();
    int				i;
    for (i = 500; i <= id; i++);
    if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
    {
      _opt.setLevel(i - 500);
      _new_type = START_GAME;
      _device->closeDevice();
    }
  }
}

void				Menu::profilEvent(const irr::SEvent& event)
{
  if (event.EventType == irr::EET_KEY_INPUT_EVENT &&
      event.KeyInput.Key == irr::KEY_ESCAPE &&
      event.KeyInput.PressedDown == false)
    _device->closeDevice();
  else if (event.EventType == irr::EET_GUI_EVENT)
  {
    irr::s32			id = event.GUIEvent.Caller->getID();
    switch(id)
    {
    case 410:
      if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
      {
	_menuList[_new_type]->getProfilButton()[APPLY_USER]->setImage(_textureList[BUTTON_CLICKED]);
	std::wstring str(_menuList[_new_type]->getUserName());
	std::string name(str.begin(), str.end());
	_opt.setUserName(name);
	findSaveFile(name);
	_new_type = MAIN_MENU;
      }
      break;
    case 411:
      if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
	_device->closeDevice();
      break;
    default:
      break;
    }
    _menuList[_new_type]->setSettings(_opt);
    _tmp_opt = _opt;
  }
}

void				Menu::characterSelectionEvent(const irr::SEvent& event)
{
  static CHARACTER_TYPE		saveChar1 = WARRIOR_ONE;
  static CHARACTER_TYPE		saveChar2 = WARRIOR_TWO;
  static CHARACTER_TYPE		saveChar3 = WARRIOR_THREE;
  static CHARACTER_TYPE		saveChar4 = WARRIOR_FOUR;

  if (event.EventType == irr::EET_KEY_INPUT_EVENT &&
      event.KeyInput.Key == irr::KEY_ESCAPE &&
      event.KeyInput.PressedDown == false) {
    _new_type = PLAY_GAME;
    saveChar1 = WARRIOR_ONE;
    saveChar2 = WARRIOR_TWO;
    saveChar3 = WARRIOR_THREE;
    saveChar4 = WARRIOR_FOUR;
  }
    else if (event.EventType == irr::EET_GUI_EVENT)
  {
    irr::s32			id = event.GUIEvent.Caller->getID();
    switch(id)
    {
    case 710:
      if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
      {
	/* SAVE CHARACTER IN SETTINGS AND IN SAVE FILE */
	_new_type = LOAD_MAP;
	_opt = _tmp_opt;
	saveChar1 = WARRIOR_ONE;
	saveChar2 = WARRIOR_TWO;
	saveChar3 = WARRIOR_THREE;
	saveChar4 = WARRIOR_FOUR;
	overwriteSaveFile(_opt.getUserName());
      }
      break;
    case 711:
      if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED) {
	saveChar1 = WARRIOR_ONE;
	saveChar2 = WARRIOR_TWO;
	saveChar3 = WARRIOR_THREE;
	saveChar4 = WARRIOR_FOUR;
	_new_type = PLAY_GAME;
      }
      break;
      /* PLAYER ONE CHARACTER */
    case 712:
      if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
      {
	_menuList[_new_type]->getCharacterButton()[saveChar1]->setImage(_textureList[BUTTON]);
	_menuList[_new_type]->getCharacterButton()[WARRIOR_ONE]->setImage(_textureList[BUTTON_CLICKED]);
	saveChar1 = WARRIOR_ONE;
      	_tmp_opt._playerOne.setCharacter(WARRIOR_ONE);
      }
      break;
    case 713:
      if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
      {
	_menuList[_new_type]->getCharacterButton()[saveChar1]->setImage(_textureList[BUTTON]);
	_menuList[_new_type]->getCharacterButton()[HUNTER_ONE]->setImage(_textureList[BUTTON_CLICKED]);
	saveChar1 = HUNTER_ONE;
	_tmp_opt._playerOne.setCharacter(HUNTER_ONE);
      }
      break;
    case 714:
      if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
      {
	_menuList[_new_type]->getCharacterButton()[saveChar1]->setImage(_textureList[BUTTON]);
	_menuList[_new_type]->getCharacterButton()[SORCERER_ONE]->setImage(_textureList[BUTTON_CLICKED]);
	saveChar1 = SORCERER_ONE;
	_tmp_opt._playerOne.setCharacter(SORCERER_ONE);
      }
      break;
      /* PLAYER TWO CHARACTER */
    case 715:
      if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
      {
	_menuList[_new_type]->getCharacterButton()[saveChar2]->setImage(_textureList[BUTTON]);
	_menuList[_new_type]->getCharacterButton()[WARRIOR_TWO]->setImage(_textureList[BUTTON_CLICKED]);
	saveChar2 = WARRIOR_TWO;
	_tmp_opt._playerTwo.setCharacter(WARRIOR_ONE);
      }
      break;
    case 716:
      if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
      {
	_menuList[_new_type]->getCharacterButton()[saveChar2]->setImage(_textureList[BUTTON]);
	_menuList[_new_type]->getCharacterButton()[HUNTER_TWO]->setImage(_textureList[BUTTON_CLICKED]);
	saveChar2 = HUNTER_TWO;
	_tmp_opt._playerTwo.setCharacter(HUNTER_ONE);
      }
      break;
    case 717:
      if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
      {
	_menuList[_new_type]->getCharacterButton()[saveChar2]->setImage(_textureList[BUTTON]);
	_menuList[_new_type]->getCharacterButton()[SORCERER_TWO]->setImage(_textureList[BUTTON_CLICKED]);
	saveChar2 = SORCERER_TWO;
	_tmp_opt._playerTwo.setCharacter(SORCERER_ONE);
      }
      break;
      /* PLAYER THREE CHARACTER */
    case 718:
      if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
      {
	_menuList[_new_type]->getCharacterButton()[saveChar3]->setImage(_textureList[BUTTON]);
	_menuList[_new_type]->getCharacterButton()[WARRIOR_THREE]->setImage(_textureList[BUTTON_CLICKED]);
	saveChar3 = WARRIOR_THREE;
	_tmp_opt._playerThree.setCharacter(WARRIOR_ONE);
      }
      break;
    case 719:
      if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
      {
	_menuList[_new_type]->getCharacterButton()[saveChar3]->setImage(_textureList[BUTTON]);
	_menuList[_new_type]->getCharacterButton()[HUNTER_THREE]->setImage(_textureList[BUTTON_CLICKED]);
	saveChar3 = HUNTER_THREE;
	_tmp_opt._playerThree.setCharacter(HUNTER_ONE);
      }
      break;
    case 720:
      if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
      {
	_menuList[_new_type]->getCharacterButton()[saveChar3]->setImage(_textureList[BUTTON]);
	_menuList[_new_type]->getCharacterButton()[SORCERER_THREE]->setImage(_textureList[BUTTON_CLICKED]);
	saveChar3 = SORCERER_THREE;
	_tmp_opt._playerThree.setCharacter(SORCERER_ONE);
      }
      break;
      /* PLAYER FOUR CHARACTER */
    case 721:
      if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
      {
	_menuList[_new_type]->getCharacterButton()[saveChar4]->setImage(_textureList[BUTTON]);
	_menuList[_new_type]->getCharacterButton()[WARRIOR_FOUR]->setImage(_textureList[BUTTON_CLICKED]);
	saveChar4 = WARRIOR_FOUR;
	_tmp_opt._playerFour.setCharacter(WARRIOR_ONE);
      }
      break;
    case 722:
      if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
      {
	_menuList[_new_type]->getCharacterButton()[saveChar4]->setImage(_textureList[BUTTON]);
	_menuList[_new_type]->getCharacterButton()[HUNTER_FOUR]->setImage(_textureList[BUTTON_CLICKED]);
	saveChar4 = HUNTER_FOUR;
	_tmp_opt._playerFour.setCharacter(HUNTER_ONE);
      }
      break;
    case 723:
      if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
      {
	_menuList[_new_type]->getCharacterButton()[saveChar4]->setImage(_textureList[BUTTON]);
	_menuList[_new_type]->getCharacterButton()[SORCERER_FOUR]->setImage(_textureList[BUTTON_CLICKED]);
	saveChar4 = SORCERER_FOUR;
	_tmp_opt._playerFour.setCharacter(SORCERER_ONE);
      }
      break;
    default:
      break;
    }
  }
  _menuList[_new_type]->setSettings(_opt);
}

void				Menu::playEvent(const irr::SEvent& event)
{
  if (event.EventType == irr::EET_KEY_INPUT_EVENT &&
      event.KeyInput.Key == irr::KEY_ESCAPE &&
      event.KeyInput.PressedDown == false)
    _new_type = MAIN_MENU;
    else if (event.EventType == irr::EET_GUI_EVENT)
  {
    irr::s32			id = event.GUIEvent.Caller->getID();
    switch(id)
    {
    case 200:
      if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
      {
	_menuList[_new_type]->getStartButton()[SINGLE_PLAYER]->setImage(_textureList[BUTTON_CLICKED]);
	_opt.setNbPlayer(1);
	_new_type = CHARACTER_SELECTION;
      }
      break;
    case 201:
      if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
      {
	_menuList[_new_type]->getStartButton()[MULTIPLAYER]->setImage(_textureList[BUTTON_CLICKED]);
	_new_type = PLAY_GAME;
	_menuList[_new_type]->HowManyPlayer(_textureList);
      }
      break;
    case 202:
      if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
      {
	_menuList[_new_type]->getStartButton()[TWO_PLAYER]->setImage(_textureList[BUTTON_CLICKED]);
	_opt.setNbPlayer(2);
	_new_type = CHARACTER_SELECTION;
      }
      break;
    case 203:
      if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
      {
	_menuList[_new_type]->getStartButton()[THREE_PLAYER]->setImage(_textureList[BUTTON_CLICKED]);
	_opt.setNbPlayer(3);
	_new_type = CHARACTER_SELECTION;
      }
      break;
    case 204:
      if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
      {
	_menuList[_new_type]->getStartButton()[FOUR_PLAYER]->setImage(_textureList[BUTTON_CLICKED]);
	_opt.setNbPlayer(4);
	_new_type = CHARACTER_SELECTION;
      }
      break;
    case 210:
      if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED)
      {
	_menuList[_new_type]->getStartButton()[BACK_START]->setImage(_textureList[BUTTON_CLICKED]);
  	_new_type = MAIN_MENU;
      }
      break;
    default:
      break;
    }
    _menuList[_new_type]->setSettings(_opt);
    _tmp_opt = _opt;
  }
}

bool				Menu::OnEvent(const irr::SEvent &event)
{
  auto				it = _eventMap.find(_current_type);
  fnct				f;
  if (it != _eventMap.end())
  {
    f = it->second;
    (this->*f)(event);
  }
  return (false);
}

void					Menu::removeKeyTaken(const std::string& key)
{
  std::unordered_map< std::string, CONTROL_TYPE >               checkKeys = {
    { _tmp_opt._playerOne.getUpKey(), PLAYER_1_UP },
    { _tmp_opt._playerOne.getDownKey(), PLAYER_1_DOWN },
    { _tmp_opt._playerOne.getLeftKey(), PLAYER_1_LEFT },
    { _tmp_opt._playerOne.getRightKey(), PLAYER_1_RIGHT },
    { _tmp_opt._playerOne.getAttackKey(), PLAYER_1_ATTACK },

    { _tmp_opt._playerTwo.getUpKey(), PLAYER_2_UP },
    { _tmp_opt._playerTwo.getDownKey(), PLAYER_2_DOWN },
    { _tmp_opt._playerTwo.getLeftKey(), PLAYER_2_LEFT },
    { _tmp_opt._playerTwo.getRightKey(), PLAYER_2_RIGHT },
    { _tmp_opt._playerTwo.getAttackKey(), PLAYER_2_ATTACK },

    { _tmp_opt._playerThree.getUpKey(), PLAYER_3_UP },
    { _tmp_opt._playerThree.getDownKey(), PLAYER_3_DOWN },
    { _tmp_opt._playerThree.getLeftKey(), PLAYER_3_LEFT },
    { _tmp_opt._playerThree.getRightKey(), PLAYER_3_RIGHT },
    { _tmp_opt._playerThree.getAttackKey(), PLAYER_3_ATTACK },

    { _tmp_opt._playerFour.getUpKey(), PLAYER_4_UP },
    { _tmp_opt._playerFour.getDownKey(), PLAYER_4_DOWN },
    { _tmp_opt._playerFour.getLeftKey(), PLAYER_4_LEFT },
    { _tmp_opt._playerFour.getRightKey(), PLAYER_4_RIGHT },
    { _tmp_opt._playerFour.getAttackKey(), PLAYER_4_ATTACK },
  };

  Settings::fkeys				f;
  auto						get = checkKeys.find(key);
  if (get != checkKeys.end())
  {
    for (auto it = _opt._replace.begin(); it != _opt._replace.end(); ++it)
      if (get->second == it->first)
      {
	f = it->second;
	if (it->first <= PLAYER_1_ATTACK)
	  (this->_tmp_opt._playerOne.*f)("");
	else if (it->first <= PLAYER_2_ATTACK)
	  (this->_tmp_opt._playerTwo.*f)("");
	else if (it->first <= PLAYER_3_ATTACK)
	  (this->_tmp_opt._playerThree.*f)("");
	else if (it->first <= PLAYER_4_ATTACK)
	  (this->_tmp_opt._playerFour.*f)("");
	break;
      }
  }
}
