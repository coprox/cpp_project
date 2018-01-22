//
// LoadMenuType.cpp for load in /home/ndejean/EPITECH/cpp_indie_studio/Menu
//
// Made by nicolas dejean
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Fri Jun  2 17:59:12 2017 nicolas dejean
// Last update Sun Jun 18 20:43:26 2017 nicolas dejean
//

#include "LoadMenuType.hpp"

#include <iostream>
LoadMenuType::LoadMenuType(irr::IrrlichtDevice* const device): AMenuType(device)
{}

void					LoadMenuType::setButtons(std::unordered_map<TEXTURE_TYPE,
						irr::video::ITexture *> textureList)
{
  wchar_t				map[54];
  size_t				id = 500;
  size_t				ord = 1;
  size_t				ver = 0;
  uint16_t				nb_level = _settings.getNbLevel();

  if (nb_level > 10)
    nb_level = 10;
  for (size_t i = 0; i < nb_level; i++, ver++)
  {
    std::string				map_name = "LEVEL " + std::to_string(i + 1);
    std::copy(map_name.begin(), map_name.end(), map);
    map[map_name.length()] = 0;
    if (ver % 4 == 0)
    {
      ord += 1;
      ver = 0;
    }
    _loadButtons[i] = _env->addButton(irr::core::rect<irr::s32>(MID(MID(BUTTON_SIZE_X)) * ord + BUTTON_SIZE_X * (ord - 1),
  								BUTTON_DISTANCE_Y * (ver + 1) + (BUTTON_SIZE_Y * ver),
  								MID(MID(BUTTON_SIZE_X)) * ord + BUTTON_SIZE_X * ord,
  								(BUTTON_DISTANCE_Y * (ver + 1)) + (BUTTON_SIZE_Y * (ver + 1))),
  				      0, (id + i),
  				      map, L"Choose this MaD MaP !!");
    _loadButtons[i]->setImage(textureList[BUTTON]);
  }
}

void					LoadMenuType::setMenu(std::unordered_map<TEXTURE_TYPE,
						irr::video::ITexture *> textureList)
{
  _env->clear();
  _env->addImage(textureList[BACKGROUND], irr::core::position2d<irr::s32>(0, 0));
  setButtons(textureList);
}
