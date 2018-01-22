//
// MapLoader.cpp for indie in /home/margue_m/rendu/tmp/cpp_indie_studio/Game
//
// Made by Mattéo Margueritte
// Login   <margue_m@epitech.net>
//
// Started on  Fri Jun  2 19:29:13 2017 Mattéo Margueritte
// Last update Mon Jun 12 19:12:35 2017 Mattéo Margueritte
//

#include <sstream>
#include "MapLoader.hpp"

MapLoader::MapLoader(std::string const &filename):
  _mapName(""), _mapData(filename), _hasStart(false)
{
  if (!_mapData.is_open())
    throw std::runtime_error(std::string("Couldn't open : " + filename));
  getData();
}

MapLoader::~MapLoader(void)
{
}

void			MapLoader::loadMap(std::string const &filename)
{
  _mapName.clear();
  _mapData.close();
  _mapData.open(filename);
  _hasStart = false;
  getData();
}

void			MapLoader::getData(void)
{
  std::string		line;
  int			fmt = MAPNAME;

  while (std::getline(_mapData, line))
    {
      if (fmt == MAPNAME)
	_mapName = line;
      else if (fmt == STARTPOS)
	{
	  std::stringstream	stream(line);

	  _hasStart = true;
	  if (std::getline(stream, line, ' '))
	    _startPos.first = std::stoi(line);
	  else
	    throw std::runtime_error("Invalid starting position in map file");
	  if (std::getline(stream, line, ' '))
	    _startPos.second = std::stoi(line);
	  else
	    throw std::runtime_error("Invalid starting position in map file");
	}
      else
	{
	  std::stringstream	stream(line);
	  ObjInfo		data;

	  if (std::getline(stream, line, ' '))
	    data.pos.first = std::stoi(line);
	  else
	    throw std::runtime_error("Invalid Object PosX in map file");
	  if (std::getline(stream, line, ' '))
	    data.pos.second = std::stoi(line);
	  else
	    throw std::runtime_error("Invalid Object PosY in map file");
	  if (std::getline(stream, line, ' '))
	    data.path = line;
	  else
	    throw std::runtime_error("Invalid Object Path in map file");
	  if (std::getline(stream, line, ' '))
	    data.name = line;
	  else
	    throw std::runtime_error("Invalid Object Name in map file");
	  _objects.push_back(data);
	}
      if (fmt != OBJECTS)
	++fmt;
    }
  if (_mapName.empty() == true || _hasStart == false)
    throw std::runtime_error("Invalid Map file");
}

std::vector<MapLoader::ObjInfo> const	&MapLoader::getObjects(void) const
{
  return (_objects);
}

std::pair<float, float> const	&MapLoader::getStartPos(void) const
{
  return (_startPos);
}

std::string const		&MapLoader::getMapName(void) const
{
  return (_mapName);
}
