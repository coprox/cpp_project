//
// ChangeKeysMenuType.cpp for change in /home/ndejean/EPITECH/indie/source/menu
//
// Made by nicolas dejean
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Thu Jun 15 16:31:27 2017 nicolas dejean
// Last update Thu Jun 15 17:24:39 2017 nicolas dejean
//

#include "ChangeKeysMenuType.hpp"

ChangeKeysMenuType::ChangeKeysMenuType(irr::IrrlichtDevice* const device):
  AMenuType(device)
{}

void				ChangeKeysMenuType::setMenu(std::unordered_map<TEXTURE_TYPE,
					irr::video::ITexture *> textureList)
{
  _env->addImage(textureList[CHANGE_KEY], irr::core::position2d<irr::s32>(0, 0));
}
