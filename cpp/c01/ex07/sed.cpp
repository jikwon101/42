#include "sed.hpp"

int Sed::sed(std::string file, std::string oldstr, std::string newstr)
{	
	int ret;
	
	std::cout << this << std::endl;
	setInfo(file, oldstr, newstr);
	if (readFile() == false)
	{
		std::cout << "Error opening file." << std::endl;
		return (false);
	}
	replaceByLine();
	ret = writeFile();
	return (ret);
}

void Sed::setInfo(std::string file, std::string oldstr, std::string newstr)
{
	this->file = file;
	this->_old = oldstr;
	this->_new = newstr;
}

void Sed::replaceByLine(void)
{
	size_t start_pos = 0;

	start_pos = this->buff.find(this->_old, start_pos);
	while (start_pos != std::string::npos)
	{
		this->buff.replace(start_pos, this->_old.length(), this->_new);
		start_pos += this->_new.length();
		start_pos = this->buff.find(this->_old, start_pos);
	}
	return ;
}

int Sed::readFile(void)
{
	std::ifstream read_file;
	std::string temp;

	read_file.open(this->file);
	if (read_file.fail())
		return (false);
	while (!read_file.eof())
	{
		getline(read_file, temp);
		this->buff += temp;
		if (!read_file.eof())
			this->buff += "\n";
	}
	read_file.close();
	return (true);
}

int Sed::writeFile(void)
{
	std::string title;
	std::ofstream write_file;

	title = this->file;
	title += ".replace";
	write_file.open(title);
	if (write_file.fail())
	{
		std::cout << "Error creating file" << std::endl;
		return (false);
	}
	write_file.write(this->buff.c_str(), this->buff.length());
	write_file.close();
	return (true);
}
