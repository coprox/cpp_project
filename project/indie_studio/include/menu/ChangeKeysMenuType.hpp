//
// ChangeKeysMenuType.hpp for change in /home/ndejean/EPITECH/indie/include/menu
//
// Made by nicolas dejean
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Thu Jun 15 16:34:48 2017 nicolas dejean
// Last update Fri Jun 16 12:21:32 2017 nicolas dejean
//

#ifndef CHANGEKEYSMENUTYPE_HPP_
#define CHANGEKEYSMENUTYPE_HPP_

#include "AMenuType.hpp"

class					ChangeKeysMenuType : public AMenuType
{
public:
  ChangeKeysMenuType(irr::IrrlichtDevice* const device);
  ~ChangeKeysMenuType() = default;
  ChangeKeysMenuType(const ChangeKeysMenuType& cp) = delete;
  ChangeKeysMenuType			&operator=(const ChangeKeysMenuType& cp) = delete;

  virtual void				setMenu(std::unordered_map<TEXTURE_TYPE,
						irr::video::ITexture *> textureList);
  virtual void				setButtons(std::unordered_map<TEXTURE_TYPE,
						   irr::video::ITexture *> /*textureList*/) {}
};

#endif /* !CHANGEKEYSMENUTYPE_HPP_ */
