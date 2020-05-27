#include <iostream>
#include "Date.h"

Date::Date()
{
	_day = 0;
	_month = 0;
	_year = 0;
}

Date::Date(int day, int month, int year)
	: _day(day)
	, _month(month)
	, _year(year)
{

}

Date& Date::operator=(const Date& other)
{
	// TODO: insert return statement here
	if (this != &other) {
		clear();
		copy(other);
	}
	return *this;
}


Date::~Date()
{
	clear();
}

void Date::setDay(int day)
{
	_day = day;
}

void Date::setMonth(int month)
{
	_month = month;
}

void Date::setYear(int year)
{
	_year = year;
}


bool Date::operator<(const Date& other) const
{
	if (this -> _year < other._year)
	{
		return true;
	}
	else if (this->_year > other._year)
	{
		return false;
	}
	else
	{
		if (this->_month < other._month)
		{
			return true;
		}
		else if (this->_month > other._month)
		{
			return false;
		}
		else
		{
			if (this->_day < other._day)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

bool Date::operator>(const Date& other) const
{
	if (this->_year > other._year)
	{
		return true;
	}
	else if (this->_year < other._year)
	{
		return false;
	}
	else
	{
		if (this->_month > other._month)
		{
			return true;
		}
		else if (this->_month < other._month)
		{
			return false;
		}
		else
		{
			if (this->_day > other._day)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}


void Date::copy(const Date& other)
{
	this->_day = other._day;
	this->_month = other._month;
	this->_year = other._year;
}

void Date::clear()
{
	_day = 0;
	_month = 0;
	_year = 0;

}

bool Date::validation()
{
	int helper = 0;
	if (!_year)
	{
		return false;
	}
	if (_month < 1 || _month > 12)
	{
		return false;
	}
	//Leap year is devisible by 4, 100, 400
	bool leap = false;
	if ((_year % 400 == 0) &&
		(_year % 100 == 0) &&
		(_year % 4 == 0))
	{
		leap = true;
	}
	if (leap && _month == 2)
	{
		helper = 29;
	}
	else if (_month == 2 && !leap )
	{
		helper = 28;
	}
	if (_month == 1 || _month == 3 ||
		_month == 5 ||
		_month == 7 ||
		_month == 8 ||
		_month == 10 ||
		_month == 12)
	{
		helper = 31;
	}
	else
	{
		helper = 30;
	}
	if (_day > helper || _day < 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Date::operator==(const Date& other) const
{
	return this->_day == other._day && this->_month == other._month && this->_year == other._year;
}

bool Date::operator<=(const Date& other) const
{
	return !(*this > other);
}

bool Date::operator>=(const Date& other) const
{
	return !(*this < other);
}

void Date::print() const
{
	std::cout << _day << '.' << _month << '.' << _year;
}

std::ostream& operator<<(std::ostream& out, const Date& obj)
{
	// TODO: insert return statement here
	out << obj.getDay() << "." << obj.getMonth() << "." << obj.getYear();
	return out;
}
