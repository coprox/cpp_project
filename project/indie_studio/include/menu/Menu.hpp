//
// Menu.hpp for  in /home/tetard/eptechY2/CPP/cpp_indie_studio
//
// Made by girard
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Wed May 31 13:21:58 2017 girard
// Last update Sun Jun 18 20:50:17 2017 bellamy corentin
//

#ifndef MENU_HPP_
# define MENU_HPP_

# include <unordered_map>
# include "irrlicht.h"
# include <memory>
# include <fstream>
# include <irrlicht.h>
# include <chrono>
# include <thread>
# include <vector>
# include <algorithm>

# include "AMenuType.hpp"
# include "LoadMenuType.hpp"
# include "MainMenuType.hpp"
# include "CreditsMenuType.hpp"
# include "StartGameMenuType.hpp"
# include "ProfilMenuType.hpp"
# include "OptionMenuType.hpp"
# include "ChangeKeysMenuType.hpp"
# include "CharacterSelectionMenuType.hpp"

# include "Settings.hpp"
# include "GlobalVar.hpp"
# include "Sound.hpp"

class					Menu : public irr::IEventReceiver
{
  typedef void (Menu::*fnct)(const irr::SEvent &event);

private:

  /* SETTINGS*/
  Settings				_tmp_opt;
  Settings				_opt;
  Settings::fkeys			_key;
  CONTROL_TYPE				_key_type;

  /* IRRLICHT AND MENU */
  irr::IrrlichtDevice* const		_device;
  irr::video::IVideoDriver		*_driver;
  MENU_TYPE				_current_type;
  MENU_TYPE				_new_type;
  std::unordered_map<TEXTURE_TYPE, irr::video::ITexture *> _textureList;
  std::unordered_map<MENU_TYPE, std::shared_ptr< AMenuType > > _menuList;

  /* MEMBER FUNCTIONS */
  std::unordered_map< MENU_TYPE, fnct >		_eventMap;

  void					menuEvent(const irr::SEvent &event);
  void					optionEvent(const irr::SEvent &event);
  void					loadEvent(const irr::SEvent &event);
  void					creditsEvent(const irr::SEvent &event);
  void					playEvent(const irr::SEvent &event);
  void					profilEvent(const irr::SEvent &event);
  void					changeKeysEvent(const irr::SEvent &event);
  void					characterSelectionEvent(const irr::SEvent &event);

public:
  Menu(void);
  Menu(const Settings& username);
  ~Menu(void) = default;
  Menu(const Menu &cp) = delete;
  Menu					&operator=(const Menu &cp) = delete;

  bool					runMenu(void);
  virtual bool				OnEvent(const irr::SEvent &event);

  void					removeKeyTaken(const std::string& keys);



  void					findSaveFile(const std::string& name);
  void					createSaveFile(const std::string& name);
  const char				*getInfoFromFile(const std::string& name,
							 const std::string& type);
  void					setInfoInFile(const std::string& name,
						      const std::string& type,
						      const std::string& value = " ");
  void					clearFile(const std::string &name);
  void					overwriteSaveFile(const std::string& name);

  /* GETTER && SETTER */
  const Settings			&getSettings() const { return(_opt); }
  void					setSettings(const Settings& set) { _opt = set; }

};

# endif /* MENU_HPP_ */
