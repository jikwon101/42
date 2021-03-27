#include "Squad.hpp"

/*
** Coplien's Form
*/
Squad::Squad()
{
	num_of_units = 0;
	units = nullptr;
}

Squad::Squad(Squad const & src)
{
	this->num_of_units = src.num_of_units;
	this->units = new ISpaceMarine*[src.num_of_units];
	for (int i = 0; i < src.num_of_units ; i++)
	{
		units[i] = src.units[i]->clone();
	}
}

Squad::~Squad()
{
	for (int i = 0; i < num_of_units ;i++)
	{
		delete units[i];
	}
	delete [] units;
}

Squad& Squad::operator=(Squad const & src)
{
	int i;

	if (this == &src)
		return (*this);
	if (this->num_of_units != 0)
	{

		for (i = 0 ; i < num_of_units ; i++)
		{
			delete (this->units)[i];
		}
		delete [] units;
	}
	this->num_of_units = src.num_of_units;
	this->units = new ISpaceMarine*[src.num_of_units];
	for (int i = 0; i < src.num_of_units ; i++)
	{
		units[i] = src.units[i]->clone();
	}
	return (*this);
}

/*
** Getter
*/
int Squad::getCount() const
{
	return (this->num_of_units);
}

ISpaceMarine* Squad::getUnit(int idx) const
{
	if (idx < 0 || idx >= num_of_units)
	{
		return (nullptr);
	}
	return (this->units[idx]);
}

/*
** Member Function
*/
bool Squad::isInUnits(ISpaceMarine *unit)
{
	for (int i = 0; i < this->num_of_units ; i++)
	{
		if (unit == this->units[i])
			return (true);
	}
	return (false);
}

int Squad::push(ISpaceMarine *unit)
{
	int i;
	ISpaceMarine **temp;
	
	if (unit == nullptr)
		return (this->num_of_units);
	if (isInUnits(unit) == true)
		return (this->num_of_units);
	temp = new ISpaceMarine*[num_of_units + 1];
	for (i = 0 ; i < num_of_units ; i++)
	{
		temp[i] = this->units[i];
	}
	temp[i] = unit;
	if (units != nullptr)
		delete [] units;
	this->units = temp;
	this->num_of_units++;
	return (this->num_of_units);
}
