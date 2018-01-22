//
// LoadMenuType.hpp for loa in /home/ndejean/EPITECH/cpp_indie_studio/Menu/includes
//
// Made by nicolas dejean
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Fri Jun  2 17:59:39 2017 nicolas dejean
// Last update Tue Jun 13 12:44:47 2017 nicolas dejean
//

#ifndef LOADMENUTYPE_HPP_
#define LOADMENUTYPE_HPP_

#include "AMenuType.hpp"

class				LoadMenuType : public AMenuType
{
public:
  LoadMenuType(irr::IrrlichtDevice* const device);
  virtual ~LoadMenuType() = default;
  LoadMenuType(const LoadMenuType& cp) = delete;
  LoadMenuType			&operator=(const LoadMenuType& cp);

  virtual void				setMenu(std::unordered_map<TEXTURE_TYPE,
						irr::video::ITexture *> textureList);
  virtual void				setButtons(std::unordered_map<TEXTURE_TYPE,
						   irr::video::ITexture *> textureList);
};

#endif /* !LOADMENUTYPE_HPP_ */
