//
// XpBar.cpp for XpBar in /home/degana_r/indie/source
//
// Made by de Ganay Renaud
// Login   <degana_r@epitech.net>
//
// Started on  Sat Jun 17 21:59:42 2017 de Ganay Renaud
// Last update Sun Jun 18 17:59:54 2017 girard
//

#include <iostream>
#include "XpBar.hpp"
#include "LifeBar.hpp"

XpBar::XpBar(irr::IrrlichtDevice * const device, irr::scene::ISceneNode * const node) :
  _device(device),
  _xpBarText(device->getVideoDriver()->getTexture(XP_BAR)),
  _blackBoxText(device->getVideoDriver()->getTexture(BLACK_BOX))
{
    irr::core::matrix4 WVPM = node->getAbsoluteTransformation() * (device->getSceneManager()->getActiveCamera()->getViewMatrix()) * device->getSceneManager()->getActiveCamera()->getProjectionMatrix();
    irr::core::vector3df pos = node->getPosition();
    irr::core::dimension2d<irr::u32>	dim = _xpBarText->getSize();
    size_t				sizeBb = _blackBoxText->getSize().Width;

    WVPM.transformVect(pos);
    _pos.X = pos.Z + (dim.Width * 2.5);
    _pos.Y = pos.X + (dim.Height * 2.5) + dim.Height;

    device->getGUIEnvironment()->addImage(_xpBarText, irr::core::vector2d<irr::s32>(_pos.X, _pos.Y));

    irr::core::vector2d<irr::s32>	posBb(_pos);
    posBb.X += dim.Width * 0.11;
    posBb.Y += dim.Height / 3 - 1;
    for (size_t off = 0; off <= 100; off++)
    {
	_blackBoxes.push_back(_device->getGUIEnvironment()->addImage(_blackBoxText, posBb));
	posBb.X += sizeBb;
    }
}

void					XpBar::updateXp(const size_t xp)
{
    fullXp();
    for (auto it = _blackBoxes.begin() + xp; it != _blackBoxes.end(); it++)
	(*it)->setVisible(true);
}

void					XpBar::fullXp(void)
{
    for (auto &it : _blackBoxes)
	it->setVisible(false);
}
