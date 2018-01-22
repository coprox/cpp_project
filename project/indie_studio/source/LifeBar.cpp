//
// lifeBar.cpp for lifeBar in /home/degana_r/indie/source
//
// Made by de Ganay Renaud
// Login   <degana_r@epitech.net>
//
// Started on  Sat Jun 17 19:32:06 2017 de Ganay Renaud
// Last update Sun Jun 18 17:55:36 2017 girard
//

#include <iostream>
#include "LifeBar.hpp"


LifeBar::LifeBar(irr::IrrlichtDevice * const device, irr::scene::ISceneNode * const node,
	 const std::string &player) :
  _device(device),
  _lifeBarText(device->getVideoDriver()->getTexture(LIFE_BAR)),
  _blackBoxText(device->getVideoDriver()->getTexture(BLACK_BOX)),
  _playerText(device->getVideoDriver()->getTexture(_player[player]))
{
  irr::core::matrix4 WVPM = node->getAbsoluteTransformation() * (device->getSceneManager()->getActiveCamera()->getViewMatrix()) * device->getSceneManager()->getActiveCamera()->getProjectionMatrix();
    irr::core::vector3df pos = node->getPosition();
    WVPM.transformVect(pos);
    _pos.X = pos.Z + (_lifeBarText->getSize().Width * 2.5);
    _pos.Y = pos.X + (_lifeBarText->getSize().Height * 2.5);

        device->getGUIEnvironment()->addImage(_playerText, irr::core::vector2d<irr::s32>((_pos.X - _playerText->getSize().Width / 2) + (_lifeBarText->getSize().Width / 2), _pos.Y - _lifeBarText->getSize().Height));
    device->getGUIEnvironment()->addImage(_lifeBarText, irr::core::vector2d<irr::s32>(_pos.X, _pos.Y));
    initBar();
}

void					LifeBar::initBar(void)
{
    irr::core::dimension2d<irr::u32>	dim = _lifeBarText->getSize();
    size_t				sizeBb = _blackBoxText->getSize().Width;
    irr::core::vector2d<irr::s32>	posBb(_pos);

    posBb.X += (dim.Width - (dim.Width * 0.11)) - (_blackBoxes.size() * sizeBb);
    posBb.Y += dim.Height / 3 - 1;
    for (size_t off = 0; off <= MAX_LIFE; off++)
    {
	_blackBoxes.push_back(_device->getGUIEnvironment()->addImage(_blackBoxText, posBb));
	posBb.X -= _blackBoxText->getSize().Width;
	_blackBoxes[off]->setVisible(false);
    }
}


void					LifeBar::updateLife(const size_t life)
{
    fullLife();
    for (auto it = _blackBoxes.begin() + (100 - life); it != _blackBoxes.begin(); it--)
	(*it)->setVisible(true);
}

void					LifeBar::fullLife(void)
{
    for (auto &it : _blackBoxes)
	it->setVisible(false);
}

void					LifeBar::noLife(void)
{
        for (auto &it : _blackBoxes)
	it->setVisible(false);
}
