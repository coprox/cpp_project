//
// MapLoader.hpp for indie in /home/margue_m/rendu/tmp/cpp_indie_studio/Game
//
// Made by Mattéo Margueritte
// Login   <margue_m@epitech.net>
//
// Started on  Fri Jun  2 19:29:09 2017 Mattéo Margueritte
// Last update Mon Jun 12 19:05:41 2017 Mattéo Margueritte
//

#ifndef MAPLOADER_HPP_
# define MAPLOADER_HPP_

# include <string>
# include <vector>
# include <utility>
# include <fstream>

class			MapLoader
{
public:
  struct		ObjInfo
  {
    std::pair<float, float>	pos;
    std::string		path;
    std::string		name;
  };
private:

  enum			MapFormat
  {
    MAPNAME = 0,
    STARTPOS,
    OBJECTS
  };

  std::string		_mapName;
  std::vector<ObjInfo>	_objects;
  std::pair<float, float>	_startPos;
  std::ifstream		_mapData;
  bool			_hasStart;

  void			getData(void);
public:
  MapLoader(std::string const &);
  ~MapLoader(void);

  void				loadMap(std::string const &);
  std::vector<ObjInfo> const	&getObjects(void) const;
  std::string const		&getMapName(void) const;
  std::pair<float, float> const	&getStartPos(void) const;
};

#endif //MAPLOADER_HPP_
