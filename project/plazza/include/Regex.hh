#ifndef REGEX_HH_
# define REGEX_HH_

#include <iostream>
#include <regex>
#include <fstream>
#include "User.hpp"

# define M_EMAIL "[\\w.]+@[\\w.]+"
# define M_PHONE "(\\d{2}\\s?){4}\\d{2}"
# define M_IP "((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)"

class Regex
{
public:
  Regex(const std::string&, const IUser::information&);
  std::string	get_buffer() const;
  std::regex	get_reg() const;
  bool		get_file() const;
  void		set_it(int i);
  int		Parse();
  void		Print();
  void		Print_file();
  bool		Search(std::string);
  void		Caesar();
  void		Xor();
  ~Regex();
private:
  std::regex			_reg;
  std::string			_buffer;
  bool				_file = false;
  std::vector<std::string>	_vector;
};

#endif /* ! REGEX_HH_ */
