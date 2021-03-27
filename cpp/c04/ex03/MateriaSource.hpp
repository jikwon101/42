#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	int			buffersize;
	AMateria*	buffer[4];
public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(MateriaSource const & src);
	MateriaSource& operator=(MateriaSource const & src);
	virtual void		learnMateria(AMateria *);
	virtual AMateria*	createMateria(std::string const & type);
	virtual int			getBuffersize(void);
};

#endif
