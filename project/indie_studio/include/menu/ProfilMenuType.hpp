//
// ProfilMenuType.hpp for prof in /home/ndejean/EPITECH/cpp_indie_studio/Menu/includes
//
// Made by nicolas dejean
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Fri Jun  9 11:32:25 2017 nicolas dejean
// Last update Tue Jun 13 12:45:26 2017 nicolas dejean
//

#ifndef PROFILEMENUTYPE_HPP_
#define PROFILEMENUTYPE_HPP_

#include "AMenuType.hpp"

class				ProfilMenuType : public AMenuType
{
public:
  ProfilMenuType(irr::IrrlichtDevice* const device);
  virtual ~ProfilMenuType() = default;
  ProfilMenuType(const ProfilMenuType& cp) = delete;
  ProfilMenuType				&operator=(const ProfilMenuType& cp) = delete;

  virtual void				setMenu(std::unordered_map<TEXTURE_TYPE,
						irr::video::ITexture *> textureList);
  virtual void				setButtons(std::unordered_map<TEXTURE_TYPE,
						   irr::video::ITexture *> texttureList);
  void					enterProfil();
};

#endif /* !PROFILEMENUTYPE_HPP_ */
