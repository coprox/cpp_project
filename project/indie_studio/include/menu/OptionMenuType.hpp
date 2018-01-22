//
// OptionMenuType.hpp for me in /home/tetard/eptechY2/CPP/cpp_indie_studio
//
// Made by girard
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Wed May 31 14:27:32 2017 girard
// Last update Sat Jun 17 19:11:49 2017 nicolas dejean
//

#ifndef OPTIONMENUTYPE_HPP_
#define OPTIONMENUTYPE_HPP_
#include "AMenuType.hpp"

class					OptionMenuType : public AMenuType
{
public:
  OptionMenuType(irr::IrrlichtDevice* const device);

  virtual ~OptionMenuType(void) = default;
  OptionMenuType(const OptionMenuType& cp) = delete;
  OptionMenuType			&operator=(const OptionMenuType &cp) = delete;

  std::unordered_map< std::string, std::string >	_print;

  /* MENU_ELEMENT */
  virtual void				setMenu(std::unordered_map<TEXTURE_TYPE,
						irr::video::ITexture *> textureList);
  virtual void				setButtons(std::unordered_map<TEXTURE_TYPE,
							   irr::video::ITexture *>);
  virtual void				setTabOptions(std::unordered_map<TEXTURE_TYPE,
						      irr::video::ITexture *>);

  const char				*printKeys(const std::string& keys);
};

#endif /* !OPTIONMENUTYPE_HPP */
