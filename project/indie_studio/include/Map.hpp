//
// Map.hpp for indie in /home/margue_m/rendu/tmp/cpp_indie_studio/Game
//
// Made by Mattéo Margueritte
// Login   <margue_m@epitech.net>
//
// Started on  Fri Jun  2 19:23:13 2017 Mattéo Margueritte
// Last update Sat Jun 17 21:25:49 2017 girard
//

#ifndef MAP_HPP_
# define MAP_HPP_

# include <unordered_map>
# include "MapLoader.hpp"
# include "irrlicht.h"

static std::unordered_map<uint16_t, std::string> MAP_LEVEL =
{
  { 1, "media/maps/map1.gauntlet" },
  { 2, "media/maps/map3.gauntlet" },
  { 3, "media/maps/map2.gauntlet" },
  { 4, "media/maps/map4.gauntlet" },
  { 5, "media/maps/map_no_brain.gauntlet" },
  { 6, "media/maps/map_nico.gauntlet" },
  { 7, "media/maps/map_coco.gauntlet" },
  { 8, "media/maps/map_renaud.gauntlet" },
  { 9, "media/maps/map_ben.gauntlet" },
  { 10, "media/maps/map_boss.gauntlet" },
};

class					Map
{
private:
  MapLoader				_mapLoader;
  irr::video::IVideoDriver		*_driver;
  irr::scene::ISceneManager		*_smgr;
  irr::scene::ITriangleSelector		*_mapSelector;
  irr::scene::IMetaTriangleSelector	*_envSelector;
  irr::scene::ISceneNode		*_map;
  std::unordered_map<std::string, irr::scene::ISceneNode *> _objects;

  void					initObjects(void);
  void					initMap(void);
  void					clearMap(void);
public:
  Map(irr::IrrlichtDevice * const, std::string const &);
  ~Map(void);

  std::pair<float, float> const		&getPlayerStartPos(void) const;
  std::unordered_map<std::string, irr::scene::ISceneNode *> &getObjects(void);
  irr::scene::ITriangleSelector		*getMapCollision(void) const;
  irr::scene::IMetaTriangleSelector	*getEnvCollision(void) const;
};

#endif //MAP_HPP_
