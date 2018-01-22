//
// AMenuType.hpp for  in /home/tetard/eptechY2/CPP/cpp_indie_studio
//
// Made by girard
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Wed May 31 14:59:38 2017 girard
// Last update Sat Jun 17 19:08:03 2017 nicolas dejean
//

#ifndef AMENUTYPE_HPP_
# define AMENUTYPE_HPP_

#include <memory>
#include "irrlicht.h"

#include <unordered_map>
#include "Settings.hpp"
#include "GlobalVar.hpp"

class					AMenuType
{
protected:
  irr::gui::IGUIEditBox			*_profilBox;
  Settings				_settings;

  std::unordered_map<size_t, irr::gui::IGUIButton *> _loadButtons;
  std::unordered_map<OPTION_TYPE, irr::gui::IGUIButton *> _optionButtons;
  std::unordered_map<CONTROL_TYPE, irr::gui::IGUIButton *> _controlButtons;
  std::unordered_map<PROFIL_TYPE, irr::gui::IGUIButton *> _profilButtons;
  std::unordered_map<START_TYPE, irr::gui::IGUIButton *> _playButtons;
  std::unordered_map<MENU_TYPE, irr::gui::IGUIButton *> _menuButtons;
  std::unordered_map<CHARACTER_TYPE, irr::gui::IGUIButton *> _characterButtons;

  irr::scene::ISceneManager				*_smgr;
  irr::gui::IGUIEnvironment				*_env;

public:
  AMenuType(irr::IrrlichtDevice* const device);

  virtual ~AMenuType(void) = default;

  AMenuType(const AMenuType &cp) = delete;
  AMenuType					&operator=(const AMenuType &cp) = delete;

  /* MENU_ELEMENTS */
  irr::gui::IGUIFont			*_font;

  virtual void					setMenu(std::unordered_map<TEXTURE_TYPE,
							irr::video::ITexture *> textureList) = 0;
  virtual void					setButtons(std::unordered_map<TEXTURE_TYPE,
  							   irr::video::ITexture *>) = 0;

  virtual void					HowManyPlayer(std::unordered_map<TEXTURE_TYPE,
							      irr::video::ITexture *>) {}

  virtual void					setTabOptions(std::unordered_map<TEXTURE_TYPE,
							      irr::video::ITexture *>) {}

  wchar_t					*stringToWChar(const char *str);

  /* GETTER */
  void						setSettings(const Settings& cp) { _settings = cp; }
  const Settings				&getSettings() const { return (_settings); }
  const wchar_t					*getUserName(void) { return (_profilBox->getText()); }
  const irr::scene::ISceneManager		*getSmgr(void) const { return (_smgr); }
  irr::gui::IGUIEnvironment			*getEnv(void) const { return (_env); }

  std::unordered_map<OPTION_TYPE, irr::gui::IGUIButton *>	&getOptButton(void) {return (_optionButtons); }
  std::unordered_map<PROFIL_TYPE, irr::gui::IGUIButton *>	&getProfilButton(void) {return (_profilButtons); }
  std::unordered_map<START_TYPE, irr::gui::IGUIButton *>	&getStartButton(void) {return (_playButtons); }
  std::unordered_map<CHARACTER_TYPE, irr::gui::IGUIButton *>	&getCharacterButton(void) {return (_characterButtons); }
  std::unordered_map<MENU_TYPE, irr::gui::IGUIButton *>		&getMenuButton(void) {return (_menuButtons); }
};

#endif /* AMENUTYPE_HPP_ */
