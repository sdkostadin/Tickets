#include "Event.h"
#include <cstring>
#include "Hall.h"
#include <iostream>



Event::Event(Date _date, Hall _hall, std::string _name)
	: date(_date)
	, hall(_hall)
	, name(_name)
	,soldSeats(0)
	,freeSeats(hall.getAllSeats())
{
	note.resize(200);
	for (int i = 0; i < 200; i++)
	{
		note[i].resize(200);
	}
	
	

	ticketid.resize(200);
	for (int i = 0; i < 200; i++)
	{
		ticketid[i].resize(200);
	}

	

	seats.resize(200);
	for (int i = 0; i < 200; i++)
	{
		seats[i].resize(200);
	}



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

void Event::setId(int row, int seat)
{
	ticketid[row - 1][seat - 1] = std::to_string(row) + "/" + std::to_string(seat) + "/" + std::to_string(hall.getId())
		+ "/" + std::to_string(date.getDay()) + "/" + std::to_string(date.getMonth()) + "/" + std::to_string(date.getYear());
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
		std::cout << "Seat booked succesfuly.";
		return true;
	}
	
}

bool Event::unbookSeat(int row, int seat)
{
	if (seats[row - 1][seat - 1] == booked)
	{
		seats[row - 1][seat - 1] = def;
		freeSeats++;
		std::cout << "Seat unbooked succesfuly.";
		return true;
	}
	else
	{
		std::cout << "Seat is not booked!";
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
			seats[row - 1][seat - 1] = paid;
			std::cout << "Seat bought succesfuly.";
			return true;
		}
		else
		{
			std::cout << "Seat is reserved." << std::endl;
			return false;
		}
	}
	else if (seats[row - 1][seat - 1] == paid)
	{
		std::cout << "Seat is paid." << std::endl;
		return false;
	}
	else
	{
		seats[row - 1][seat - 1] = paid;
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

void Event::printSeatStatus() const
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (seats[i - 1][j - 1] == def)
			{
				std::cout << "Row " << i << " seat " << j << " is free." << std::endl;
			}
			else if (seats[i - 1][j - 1] == booked)
			{
				std::cout << "Row " << i << " seat " << j << " is reserved." << std::endl;
			}
			else if (seats[i - 1][j - 1] == paid)
			{
				std::cout << "Row " << i << " seat " << j << " is already paid." << std::endl;
			}
		}
	}
}

void Event::printBooked() const
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (seats[i][j] == booked)
			{
				std::cout << "Row " << i+1 << " seat " << j+1 << std::endl;
			}
		}
	}
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






