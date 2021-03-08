#include "sed.hpp"

void Sed::setInfo(std::string file, std::string old_str, std::string new_str)
{
	this->file = file;
	this->_old = old_str;
	this->_new = new_str;
}

void Sed::sed(void)
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

void Sed::writeFile(void)
{
	std::string title;
	std::ofstream write_file;

	title = this->file;
	title += ".replace";
	write_file.open(title);
	write_file.write(this->buff.c_str(), this->buff.length());
	write_file.close();
	return ;
}
