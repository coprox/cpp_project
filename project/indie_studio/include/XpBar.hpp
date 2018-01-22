//
// XpBar.hpp for XpBar in /home/degana_r/indie/include
//
// Made by de Ganay Renaud
// Login   <degana_r@epitech.net>
//
// Started on  Sat Jun 17 21:59:33 2017 de Ganay Renaud
// Last update Sun Jun 18 00:55:46 2017 de Ganay Renaud
//


#ifndef XPBAR_HPP_
# define XPBAR_HPP_

#include <vector>
#include <string>
#include "irrlicht.h"

static const irr::io::path				XP_BAR = "media/textures/xp_bar.png";
//static const irr::io::path				BLACK_BOX = "media/textures/black_box_new_new.png";

class							XpBar
{
private:
    irr::IrrlichtDevice					*_device;
    irr::video::ITexture				*_xpBarText;
    irr::video::ITexture				*_blackBoxText;
    std::vector<irr::gui::IGUIImage *>			_blackBoxes;
    irr::core::vector2d<irr::s32>			_pos;

public:
    XpBar(irr::IrrlichtDevice * const device, irr::scene::ISceneNode * const node);
    XpBar(const XpBar &cp) = delete;
    ~XpBar(void) = default;
    XpBar						&operator=(const XpBar &cp) = delete;


    void							updateXp(const size_t life);
    void							initXp(void);
    void							fullXp(void);
};

# endif /* XPBAR_HPP_ */
