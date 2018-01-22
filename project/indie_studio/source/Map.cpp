//
// Map.cpp for indie in /home/margue_m/rendu/tmp/cpp_indie_studio/Game
//
// Made by Mattéo Margueritte
// Login   <margue_m@epitech.net>
//
// Started on  Fri Jun  2 19:23:16 2017 Mattéo Margueritte
// Last update Sat Jun 17 20:51:26 2017 girard
//

#include "Map.hpp"

Map::Map(irr::IrrlichtDevice * const device,
	 std::string const &mapFile):
  _mapLoader(mapFile), _driver(device->getVideoDriver()),
  _smgr(device->getSceneManager()),
  _envSelector(_smgr->createMetaTriangleSelector())
{
  _driver->setFog(irr::video::SColor(0, 0, 0, 0), irr::video::EFT_FOG_LINEAR,
		  150, 400, .02f, true, true);
  _smgr->setAmbientLight(irr::video::SColorf(0.3f,0.3f,0.3f,0.3f));
  initMap();
  initObjects();
}

Map::~Map(void)
{
}

void			Map::initMap(void)
{
  irr::scene::IMesh	*mapMesh;

  mapMesh = _smgr->getMesh(_mapLoader.getMapName().c_str());
  _map = _smgr->addMeshSceneNode(mapMesh);
  if (!_map)
    throw std::runtime_error(std::string("Could not load : "
					 + _mapLoader.getMapName()));
  _map->setPosition(irr::core::vector3df(0,0,0));
  _mapSelector = _smgr->createTriangleSelector(mapMesh, _map);
  _map->setTriangleSelector(_mapSelector);
  _map->setName("map");
  _map->setMaterialFlag(irr::video::EMF_FOG_ENABLE, true);
  _map->setMaterialFlag(irr::video::EMF_NORMALIZE_NORMALS, true);
}

void			Map::initObjects(void)

{
  std::vector<MapLoader::ObjInfo>	objs;
  irr::scene::ISceneNode		*node;
  irr::scene::ITriangleSelector		*selector;
  bool					has_exit = false;

  objs = _mapLoader.getObjects();
  if (!objs.empty())
    for (auto &it : objs)
      {
	node = _smgr->addMeshSceneNode(_smgr->getMesh(it.path.c_str()));
	if (!node)
	  throw std::runtime_error(std::string("Could not load an object : "
					       + it.path));
	node->setPosition(irr::core::vector3df(it.pos.first, 4, it.pos.second));
	node->setName(irr::core::stringc(it.name.c_str()));
	selector = _smgr->createTriangleSelectorFromBoundingBox(node);
	if (!selector)
	  throw std::runtime_error("Selector creation failed");
	node->setTriangleSelector(selector);
	_envSelector->addTriangleSelector(selector);
	if (it.name.compare("exit_cube") == 0)
	  {
	    node->setMaterialType(irr::video::EMT_TRANSPARENT_ALPHA_CHANNEL);
	    has_exit = true;
	  }
	selector->drop();
	_objects[it.name] = node;
      }
  if (has_exit == false)
    throw std::runtime_error("Invalid map : no exit");
}

std::pair<float, float> const			&Map::getPlayerStartPos(void) const
{
  return (_mapLoader.getStartPos());
}

std::unordered_map<std::string, irr::scene::ISceneNode *>
&Map::getObjects(void)
{
  return (_objects);
}

irr::scene::ITriangleSelector			*Map::getMapCollision(void) const
{
  return (_mapSelector);
}

irr::scene::IMetaTriangleSelector		*Map::getEnvCollision(void) const
{
  return (_envSelector);
}
