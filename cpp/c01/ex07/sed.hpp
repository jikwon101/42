#ifndef SED_HPP
# define SED_HPP

#include <iostream>
#include <fstream>

class Sed
{
private:
	std::string _old;
	std::string _new;
	std::string buff;
	std::string file;
public:
	void setInfo(std::string file, std::string _old, std::string _new);
	void sed(void);
	int	readFile();
	void writeFile();
};
#endif
