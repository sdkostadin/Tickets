#include "Hall.h"

Hall::Hall(int _id, int _rows , int _SeatsOnRow)
	: id(_id)
	, rows(_rows)
	, SeatsOnRow(_SeatsOnRow)
	
{
}

Hall::Hall(const Hall& other)
{
	copy(other);
}

Hall& Hall::operator=(const Hall& other)
{
	if (this != &other)
	{
		copy(other);
	}

	return *this;
}

void Hall::copy(const Hall& other)
{
	this->id = other.id;
	this->rows = other.rows;
	this->SeatsOnRow = other.SeatsOnRow;
}
