//
// CreditsMenuType.hpp for credi in /home/ndejean/EPITECH/cpp_indie_studio/Menu/includes
//
// Made by nicolas dejean
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Sat Jun  3 09:49:46 2017 nicolas dejean
// Last update Tue Jun 13 12:53:50 2017 nicolas dejean
//

#ifndef CREDITSMENUTYPE_HPP_
#define CREDITSMENUTYPE_HPP_

#include "AMenuType.hpp"

class				CreditsMenuType : public AMenuType
{
public:
  CreditsMenuType(irr::IrrlichtDevice* const device): AMenuType(device){}
  ~CreditsMenuType() = default;
  CreditsMenuType(const CreditsMenuType& cp) = delete;
  CreditsMenuType			&operator=(const CreditsMenuType& cp) = delete;

  virtual void				setMenu(std::unordered_map<TEXTURE_TYPE,
						irr::video::ITexture *> textureList);
  virtual void				setButtons(std::unordered_map<TEXTURE_TYPE,
						   irr::video::ITexture *> textureList);
};

#endif /* CREDITSMENUTYPE_HPP_ */
