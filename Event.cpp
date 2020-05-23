#include "Event.h"
#include <cstring>
#include "Hall.h"
#include <iostream>



Event::Event(Date _date, Hall _hall, std::string _name)
	: date(_date)
	, hall(_hall)
	, name(_name)
	
	
{
	init();
}

Event& Event::operator=(const Event& other)
{
	// TODO: insert return statement here
	if (this != &other)
	{
		copy(other);
	}

	return *this;
}

Event::~Event()
{
}

void Event::setName(std::string _name)
{
	name = _name;
}

void Event::setId(int row, int seat)
{
	ticketid[row][seat] = std::to_string(row) + std::to_string(seat) + std::to_string(hall.getId())
		 + std::to_string(date.getDay()) + std::to_string(date.getMonth()) + std::to_string(date.getYear());
}


void Event::setDate(Date _date)
{
	if (_date.validation())
	{
		date = _date;
	}
}

bool Event::bookSeat(int row, int seat, std::string _note)
{
	if (seats[row - 1][seat - 1] == booked)
	{
		std::cout << "Seat is aldready booked." << std::endl;
		return false;
	}
	else if (seats[row - 1][seat - 1] == paid)
	{
		
		std::cout << "Seat is already bought." << std::endl;
		return false;
	}
	else
	{
		seats[row - 1][seat - 1] = booked;
		note[row - 1][seat - 1] = _note;
		setId(row, seat);
		std::cout << "Seat booked succesfuly." << std::endl;
		return true;
	}
	
}

bool Event::unbookSeat(int row, int seat)
{
	if (seats[row - 1][seat - 1] == booked)
	{
		seats[row - 1][seat - 1] = def;
		freeSeats++;
		std::cout << "Seat unbooked succesfuly." << std::endl;
		return true;
	}
	else
	{
		std::cout << "Seat is not booked!" << std::endl;
		return false;
	}
}

bool Event::isBooked(int row, int seat)
{
	if (seats[row - 1][seat - 1] == booked)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Event::buySeat(int row, int seat, std::string _note)
{
	if (seats[row - 1][seat - 1] == booked)
	{
		if (note[row - 1][seat - 1] == _note)
		{
			freeSeats--;
			soldSeats++;
			seats[row][seat] = paid;
			return true;
		}
		else
		{
			std::cout << "Seat is already reserved." << std::endl;
			return false;
		}
	}
	else if (seats[row - 1][seat - 1] == paid)
	{
		std::cout << "Seat is already paid." << std::endl;
		return false;
	}
	else
	{
		seats[row][seat] = paid;
		note[row - 1][seat - 1] = _note;
		freeSeats--;
		soldSeats++;
		setId(row, seat);
		return true;
	}
	
}

void Event::print() const
{
	std::cout << "Event: " << name << " on date: ";
	std::cout<< date.getDay()<<"."<< date.getMonth() << "." <<date.getYear();
	std::cout<< " in hall: " << hall.getId() << std::endl;
}

void Event::printFree() const
{
	for (int i = 0; i < hall.getRows(); i++)
	{
		for (int j = 0; j < hall.getSeatsOnRow(); j++)
		{
			if (seats[i][j] !=booked && seats[i][j]!=paid)
			{
				std::cout << "Row " << i << " seat " << j << " is free." << std::endl;
			}
			
		}
	}
}

void Event::printBooked() const
{
	for (int i = 0; i < hall.getRows(); i++)
	{
		for (int j = 0; j < hall.getSeatsOnRow(); j++)
		{
			if (seats[i][j] == booked)
			{
				std::cout << "Row " << i+1 << " seat " << j+1 << " is booked." << std::endl;
			}
		}
	}
}

void Event::printBought() const
{
	for (int i = 0; i < hall.getRows(); i++)
	{
		for (int j = 0; j < hall.getSeatsOnRow(); j++)
		{
			if (seats[i][j] == paid)
			{
				std::cout << "Row " << i + 1 << " seat " << j + 1 << " is bought."<<std::endl;
			}
		}
	}
}

void Event::init()
{
	note.resize(hall.getRows());
	for (int i = 0; i < hall.getRows(); i++)
	{
		note[i].resize(hall.getSeatsOnRow());
	}

	for (int i = 0; i < hall.getRows(); i++)
	{
		for (int j = 0; j < hall.getSeatsOnRow(); j++)
		{
			note[i][j].push_back('-');
		}
	}


	ticketid.resize(hall.getRows());
	for (int i = 0; i < hall.getRows(); i++)
	{
		ticketid[i].resize(hall.getSeatsOnRow());
	}

	for (int i = 0; i < hall.getRows(); i++)
	{
		for (int j = 0; j < hall.getSeatsOnRow(); j++)
		{
			ticketid[i][j].push_back('-');
		}
	}


	seats.resize(hall.getRows());
	for (int i = 0; i < hall.getRows(); i++)
	{
		seats[i].resize(hall.getSeatsOnRow());
	}

	for (int i = 0; i < hall.getRows(); i++)
	{
		for (int j = 0; j < hall.getSeatsOnRow(); j++)
		{
			seats[i][j] = def;
		}
	}
	soldSeats = 0;
	freeSeats = hall.getAllSeats();
}

void Event::setHall(Hall id)
{
	hall = id;
}



void Event::copy(const Event& other)
{
	this->name = other.name;
	this->date = other.date;
	this->hall = other.hall;
	this->freeSeats = other.freeSeats;
	this->soldSeats = other.soldSeats;
	this->ticketid = other.ticketid;
	this->note = other.note;
	this->seats = other.seats;
}

void Event::clear()
{

}






