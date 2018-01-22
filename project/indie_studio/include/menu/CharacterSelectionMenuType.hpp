//
// CharacterSelectionMenuType.hpp for char in /home/ndejean/EPITECH/indie/include/menu
//
// Made by nicolas dejean
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Fri Jun 16 14:51:50 2017 nicolas dejean
// Last update Fri Jun 16 19:09:49 2017 nicolas dejean
//

#ifndef CHARACTERSELECTIONMENUTYPE_HPP_
#define CHARACTERSELECTIONMENUTYPE_HPP_

#include "AMenuType.hpp"

class					CharacterSelectionMenuType : public AMenuType
{
public:
  typedef void (CharacterSelectionMenuType::*charfnct)(std::unordered_map<TEXTURE_TYPE,
						       irr::video::ITexture *> textureList);

  CharacterSelectionMenuType(irr::IrrlichtDevice* const device);
  virtual ~CharacterSelectionMenuType() = default;
  CharacterSelectionMenuType(const CharacterSelectionMenuType& cp) = delete;
  CharacterSelectionMenuType		&operator=(const CharacterSelectionMenuType& cp) = delete;

  virtual void				setMenu(std::unordered_map<TEXTURE_TYPE,
						irr::video::ITexture *> textureList);
  virtual void				setButtons(std::unordered_map<TEXTURE_TYPE,
						   irr::video::ITexture *> textureList);

  std::unordered_map< START_TYPE, charfnct >	_character;

  void					singleplayerButtons(std::unordered_map<TEXTURE_TYPE,
							    irr::video::ITexture *> textureList);
  void					multiplayerTwoButtons(std::unordered_map<TEXTURE_TYPE,
							      irr::video::ITexture *> textureList);
  void					multiplayerThreeButtons(std::unordered_map<TEXTURE_TYPE,
								irr::video::ITexture *> textureList);
  void					multiplayerFourButtons(std::unordered_map<TEXTURE_TYPE,
							       irr::video::ITexture *> textureList);

};

#endif /* !CHARACTERSELECTIONMENUTYPE_HPP_ */
