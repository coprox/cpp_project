//
// MenuSaveFile.cpp for save in /home/ndejean/EPITECH/indie/source/menu
//
// Made by nicolas dejean
// Login   <benjamin.girard@epitech.eu>
//
// Started on  Tue Jun 13 14:55:01 2017 nicolas dejean
// Last update Sun Jun 18 19:28:04 2017 nicolas dejean
//

#include "Menu.hpp"
#include <iostream>

void					Menu::clearFile(const std::string& name)
{
  std::string			str = "media/save/" + name + "_save.save";
  std::ofstream			writeSave(str.c_str(), std::ofstream::out | std::ofstream::trunc);
  writeSave.close();
}

void					Menu::setInfoInFile(const std::string& name,
							    const std::string& type,
							    const std::string& value)
{
  std::string			str = "media/save/" + name + "_save.save";
  std::ofstream			writeSave(str.c_str(), std::ofstream::out | std::ofstream::app);

  writeSave << type << value << "\n";
  writeSave.close();
}

const char				*Menu::getInfoFromFile(const std::string& name,
						      const std::string& type)
{
  std::string                   str = "media/save/" + name + "_save.save";
  std::string			val;
  std::ifstream                 readSave(str.c_str(), std::ifstream::in);
  std::string                   line;

  while (readSave.good())
  {
    std::getline(readSave, line);
    if (line.find(type) != std::string::npos)
      break ;
  }
  for (size_t i = type.length();
       line.c_str()[i] != '\n' && line.c_str()[i] != '\0'; i++)
    val += line.c_str()[i];
  readSave.close();
  return val.c_str();
}

void				Menu::createSaveFile(const std::string& name)
{
  setInfoInFile(name, name);
  setInfoInFile(name, FILE_NBR_MAP, "1");
  setInfoInFile(name, FILE_NBR_PLAYER, "1");
  setInfoInFile(name, FILE_JOYSTICK, "0");
  setInfoInFile(name, FILE_FULLSCREEN, "0");

  setInfoInFile(name, FILE_CHARACTER_ONE, "0");
  setInfoInFile(name, FILE_CHARACTER_TWO, "0");
  setInfoInFile(name, FILE_CHARACTER_THREE, "0");
  setInfoInFile(name, FILE_CHARACTER_FOUR, "0");

  setInfoInFile(name, FILE_KEYS_PLAYER_ONE_UP, "Z");
  setInfoInFile(name, FILE_KEYS_PLAYER_ONE_DOWN, "S");
  setInfoInFile(name, FILE_KEYS_PLAYER_ONE_LEFT, "Q");
  setInfoInFile(name, FILE_KEYS_PLAYER_ONE_RIGHT, "D");
  setInfoInFile(name, FILE_KEYS_PLAYER_ONE_ATTACK, "A");

  setInfoInFile(name, FILE_KEYS_PLAYER_TWO_UP, "G");
  setInfoInFile(name, FILE_KEYS_PLAYER_TWO_DOWN, "B");
  setInfoInFile(name, FILE_KEYS_PLAYER_TWO_LEFT, "V");
  setInfoInFile(name, FILE_KEYS_PLAYER_TWO_RIGHT, "N");
  setInfoInFile(name, FILE_KEYS_PLAYER_TWO_ATTACK, " ");

  setInfoInFile(name, FILE_KEYS_PLAYER_THREE_UP, "O");
  setInfoInFile(name, FILE_KEYS_PLAYER_THREE_DOWN, "L");
  setInfoInFile(name, FILE_KEYS_PLAYER_THREE_LEFT, "K");
  setInfoInFile(name, FILE_KEYS_PLAYER_THREE_RIGHT, "M");
  setInfoInFile(name, FILE_KEYS_PLAYER_THREE_ATTACK, "I");

  setInfoInFile(name, FILE_KEYS_PLAYER_FOUR_UP, "Z");
  setInfoInFile(name, FILE_KEYS_PLAYER_FOUR_DOWN, "S");
  setInfoInFile(name, FILE_KEYS_PLAYER_FOUR_LEFT, "Q");
  setInfoInFile(name, FILE_KEYS_PLAYER_FOUR_RIGHT, "D");
  setInfoInFile(name, FILE_KEYS_PLAYER_FOUR_ATTACK, "A");

  _opt.setNbLevel(1);
}

void				Menu::findSaveFile(const std::string& name)
{
  std::string                   str = "media/save/" + name + "_save.save";
  std::ifstream                 readSave(str.c_str(), std::ifstream::in);

  if (!readSave.good())
  {
    readSave.close();
    return createSaveFile(name);
  }
  _opt.setUserName(name);
  _opt.setJoystick(atoi(getInfoFromFile(name, FILE_JOYSTICK)));
  _opt.setNbLevel(atoi(getInfoFromFile(name, FILE_NBR_MAP)));
  _opt.setFullscreen(atoi(getInfoFromFile(name, FILE_FULLSCREEN)));

  _opt._playerOne.setUpKey(getInfoFromFile(name, FILE_KEYS_PLAYER_ONE_UP));
  _opt._playerOne.setDownKey(getInfoFromFile(name, FILE_KEYS_PLAYER_ONE_DOWN));
  _opt._playerOne.setLeftKey(getInfoFromFile(name, FILE_KEYS_PLAYER_ONE_LEFT));
  _opt._playerOne.setRightKey(getInfoFromFile(name, FILE_KEYS_PLAYER_ONE_RIGHT));
  _opt._playerOne.setAttackKey(getInfoFromFile(name, FILE_KEYS_PLAYER_ONE_ATTACK));

  _opt._playerTwo.setUpKey(getInfoFromFile(name, FILE_KEYS_PLAYER_TWO_UP));
  _opt._playerTwo.setDownKey(getInfoFromFile(name, FILE_KEYS_PLAYER_TWO_DOWN));
  _opt._playerTwo.setLeftKey(getInfoFromFile(name, FILE_KEYS_PLAYER_TWO_LEFT));
  _opt._playerTwo.setRightKey(getInfoFromFile(name, FILE_KEYS_PLAYER_TWO_RIGHT));
  _opt._playerTwo.setAttackKey(getInfoFromFile(name, FILE_KEYS_PLAYER_TWO_ATTACK));

  _opt._playerThree.setUpKey(getInfoFromFile(name, FILE_KEYS_PLAYER_THREE_UP));
  _opt._playerThree.setDownKey(getInfoFromFile(name, FILE_KEYS_PLAYER_THREE_DOWN));
  _opt._playerThree.setLeftKey(getInfoFromFile(name, FILE_KEYS_PLAYER_THREE_LEFT));
  _opt._playerThree.setRightKey(getInfoFromFile(name, FILE_KEYS_PLAYER_THREE_RIGHT));
  _opt._playerThree.setAttackKey(getInfoFromFile(name, FILE_KEYS_PLAYER_THREE_ATTACK));

  _opt._playerFour.setUpKey(getInfoFromFile(name, FILE_KEYS_PLAYER_FOUR_UP));
  _opt._playerFour.setDownKey(getInfoFromFile(name, FILE_KEYS_PLAYER_FOUR_DOWN));
  _opt._playerFour.setLeftKey(getInfoFromFile(name, FILE_KEYS_PLAYER_FOUR_LEFT));
  _opt._playerFour.setRightKey(getInfoFromFile(name, FILE_KEYS_PLAYER_FOUR_RIGHT));
  _opt._playerFour.setAttackKey(getInfoFromFile(name, FILE_KEYS_PLAYER_FOUR_ATTACK));

  readSave.close();
}

void				Menu::overwriteSaveFile(const std::string &name)
{
  clearFile(name);
  setInfoInFile(name, name);

  setInfoInFile(name, FILE_NBR_MAP, std::to_string(_opt.getNbLevel()));
  setInfoInFile(name, FILE_JOYSTICK, std::to_string(_opt.getJoystick()));
  setInfoInFile(name, FILE_NBR_PLAYER, std::to_string(_opt.getNbPlayer()));
  setInfoInFile(name, FILE_FULLSCREEN, std::to_string(_opt.getFullscreen()));

  setInfoInFile(name, FILE_CHARACTER_ONE, std::to_string(_opt._playerOne.getCharacter()));
  setInfoInFile(name, FILE_CHARACTER_TWO, std::to_string(_opt._playerTwo.getCharacter()));
  setInfoInFile(name, FILE_CHARACTER_THREE, std::to_string(_opt._playerThree.getCharacter()));
  setInfoInFile(name, FILE_CHARACTER_FOUR, std::to_string(_opt._playerFour.getCharacter()));

  setInfoInFile(name, FILE_KEYS_PLAYER_ONE_UP, _opt._playerOne.getUpKey());
  setInfoInFile(name, FILE_KEYS_PLAYER_ONE_DOWN, _opt._playerOne.getDownKey());
  setInfoInFile(name, FILE_KEYS_PLAYER_ONE_LEFT, _opt._playerOne.getLeftKey());
  setInfoInFile(name, FILE_KEYS_PLAYER_ONE_RIGHT, _opt._playerOne.getRightKey());
  setInfoInFile(name, FILE_KEYS_PLAYER_ONE_ATTACK, _opt._playerOne.getAttackKey());

  setInfoInFile(name, FILE_KEYS_PLAYER_TWO_UP, _opt._playerTwo.getUpKey());
  setInfoInFile(name, FILE_KEYS_PLAYER_TWO_DOWN, _opt._playerTwo.getDownKey());
  setInfoInFile(name, FILE_KEYS_PLAYER_TWO_LEFT, _opt._playerTwo.getLeftKey());
  setInfoInFile(name, FILE_KEYS_PLAYER_TWO_RIGHT, _opt._playerTwo.getRightKey());
  setInfoInFile(name, FILE_KEYS_PLAYER_TWO_ATTACK, _opt._playerTwo.getAttackKey());

  setInfoInFile(name, FILE_KEYS_PLAYER_THREE_UP, _opt._playerThree.getUpKey());
  setInfoInFile(name, FILE_KEYS_PLAYER_THREE_DOWN, _opt._playerThree.getDownKey());
  setInfoInFile(name, FILE_KEYS_PLAYER_THREE_LEFT, _opt._playerThree.getLeftKey());
  setInfoInFile(name, FILE_KEYS_PLAYER_THREE_RIGHT, _opt._playerThree.getRightKey());
  setInfoInFile(name, FILE_KEYS_PLAYER_THREE_ATTACK, _opt._playerThree.getAttackKey());

  setInfoInFile(name, FILE_KEYS_PLAYER_FOUR_UP, _opt._playerFour.getUpKey());
  setInfoInFile(name, FILE_KEYS_PLAYER_FOUR_DOWN, _opt._playerFour.getDownKey());
  setInfoInFile(name, FILE_KEYS_PLAYER_FOUR_LEFT, _opt._playerFour.getLeftKey());
  setInfoInFile(name, FILE_KEYS_PLAYER_FOUR_RIGHT, _opt._playerFour.getRightKey());
  setInfoInFile(name, FILE_KEYS_PLAYER_FOUR_ATTACK, _opt._playerFour.getAttackKey());
}
