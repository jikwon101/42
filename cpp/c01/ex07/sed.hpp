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
	void setInfo(std::string file, std::string oldstr, std::string newstr);
	void replaceByLine(void);
	int	readFile();
	int writeFile();

public:
	int sed(std::string file, std::string oldstr, std::string newstr);
};
#endif
