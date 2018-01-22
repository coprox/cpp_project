//
// StartGameMenuType.hpp for in in /home/ndejean/EPITECH/cpp_indie_studio/Menu/includes
//
// Made by nicolas dejean
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Sat Jun  3 08:53:34 2017 nicolas dejean
// Last update Tue Jun 13 12:46:20 2017 nicolas dejean
//

#ifndef STARTGAMEMENUTYPE_HPP_
#define STARTGAMEMENUTYPE_HPP_

#include "AMenuType.hpp"

class				StartGameMenuType : public AMenuType
{
public:
  StartGameMenuType(irr::IrrlichtDevice* const device);
  ~StartGameMenuType() = default;
  StartGameMenuType(const StartGameMenuType& cp) = delete;
  StartGameMenuType			&operator=(const StartGameMenuType& cp) = delete;

  virtual void				setMenu(std::unordered_map<TEXTURE_TYPE,
						irr::video::ITexture *> textureList);
  virtual void				setButtons(std::unordered_map<TEXTURE_TYPE,
						   irr::video::ITexture *> texttureList);
  virtual void				HowManyPlayer(std::unordered_map<TEXTURE_TYPE,
						      irr::video::ITexture *> texttureList);
};

#endif /* STARTGAMEMENUTYPE_HPP_ */
