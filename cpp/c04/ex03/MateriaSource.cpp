#include "MateriaSource.hpp"

/*
** Coplien's form
*/
MateriaSource::MateriaSource()
{
	this->buffersize = 0;
	for (int i = 0; i < 4 ; i++)
	{
		this->buffer[i] = nullptr;
	}
}

MateriaSource::~MateriaSource(){}

MateriaSource::MateriaSource(MateriaSource const & src)
{
	this->buffersize = src.buffersize;
	for (int i = 0;  i < 4 ; i++)
	{
		this->buffer[i] = src.buffer[i];
	}
}

MateriaSource& MateriaSource::operator=(MateriaSource const & src)
{
	int i;

	if (this != &src)
	{
		this->buffersize = src.buffersize;
		for (i = 0; i < 4 ; i++)
		{
			this->buffer[i] = src.buffer[i];
		}
	}
	return (*this);
}

int			MateriaSource::getBuffersize(void)
{
	return (this->buffersize);
}

/*
** MemberFunction
*/
void		MateriaSource::learnMateria(AMateria *new_thing)
{
	if (this->buffersize == 4 || new_thing == nullptr )
		return ;
	this->buffer[this->buffersize] = new_thing;
	this->buffersize += 1;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < this->buffersize ; i++)
	{
		if (type.compare(buffer[i]->getType()) == 0)
			return (buffer[i]->clone());
	}
	return (nullptr);
}
