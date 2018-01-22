//
// lifeBar.hpp for lifeBar in /home/degana_r/indie/include
//
// Made by de Ganay Renaud
// Login   <degana_r@epitech.net>
//
// Started on  Sat Jun 17 19:32:26 2017 de Ganay Renaud
// Last update Sun Jun 18 00:11:10 2017 de Ganay Renaud
//

#ifndef LIFEBAR_HPP_
# define LIFEBAR_HPP_

#include <vector>
#include <string>
#include <unordered_map>
#include "irrlicht.h"

static const size_t					MAX_LIFE = 100;
static const irr::io::path				LIFE_BAR = "media/textures/health_bar_new_new.png";
static const irr::io::path				BLACK_BOX = "media/textures/black_box_new_new.png";
static const irr::io::path				PLAYER_1 = "media/textures/P1_new.png";
static const irr::io::path				PLAYER_2 = "media/textures/P2_new.png";
static const irr::io::path				PLAYER_3 = "media/textures/P3_new.png";
static const irr::io::path				PLAYER_4 = "media/textures/P4_new.png";
static std::unordered_map<std::string, irr::io::path>	_player =
{
    {"P1", PLAYER_1},
    {"P2", PLAYER_2},
    {"P3", PLAYER_3},
    {"P4", PLAYER_4}
};

class							LifeBar
{
private:
    irr::IrrlichtDevice					*_device;
    irr::video::ITexture				*_lifeBarText;
    irr::video::ITexture				*_blackBoxText;
    irr::video::ITexture				*_playerText;
    std::vector<irr::gui::IGUIImage *>			_blackBoxes;
    irr::core::vector2d<irr::s32>			_pos;

public:
    LifeBar(irr::IrrlichtDevice * const device, irr::scene::ISceneNode * const node,
	    const std::string &player);
    LifeBar(const LifeBar &cp) = delete;
    ~LifeBar(void) = default;
    LifeBar						&operator=(const LifeBar &cp) = delete;

    void							initBar(void);
    void							updateLife(const size_t life);
    void							fullLife(void);
    void							noLife(void);
};

# endif /* LIFEBAR_HPP_ */
