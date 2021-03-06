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
	if (row > hall.getRows() || row <= 0 || seat > hall.getSeatsOnRow() || seat<=0)
	{
		std::cout << "Wrong row or seat imput!" << std::endl;
		return false;
	}
	if (seats[row][seat] == booked)
	{
		std::cout << "Seat is aldready booked." << std::endl;
		return false;
	}
	else if (seats[row ][seat ] == paid)
	{
		
		std::cout << "Seat is already bought." << std::endl;
		return false;
	}
	else
	{
		seats[row ][seat ] = booked;
		note[row ][seat ] = _note;
		freeSeats--;
		setId(row, seat);
		std::cout << "Seat booked succesfuly." << std::endl;
		return true;
	}
	
}

bool Event::unbookSeat(int row, int seat)
{
	if (row > hall.getRows() || row <= 0 || seat > hall.getSeatsOnRow() || seat <= 0)
	{
		std::cout << "Wrong row or seat imput!" << std::endl;
		return false;
	}
	if (seats[row][seat] == booked)
	{
		seats[row][seat] = def;
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
	if (row > hall.getRows() || row <= 0 || seat > hall.getSeatsOnRow() || seat <= 0)
	{
		return false;
	}
	if (seats[row][seat] == booked)
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
	if (row > hall.getRows() || row <= 0 || seat > hall.getSeatsOnRow() || seat <= 0)
	{
		std::cout << "Wrong row or seat imput!" << std::endl;
		return false;
	}
	if (seats[row][seat] == booked)
	{
		if (note[row][seat] == _note)
		{
			freeSeats--;
			soldSeats++;
			seats[row][seat] = paid;
			std::cout << "Seat bought successfully!" << std::endl;
			return true;
		}
		else
		{
			std::cout << "Seat is already reserved." << std::endl;
			return false;
		}
	}
	else if (seats[row][seat] == paid)
	{
		std::cout << "Seat is already paid." << std::endl;
		return false;
	}
	else
	{
		seats[row][seat] = paid;
		note[row][seat] = _note;
		freeSeats--;
		soldSeats++;
		setId(row, seat);
		std::cout << "Seat bought successfully!" << std::endl;
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
	for (int i = 1; i < hall.getRows(); i++)
	{
		for (int j = 1; j < hall.getSeatsOnRow(); j++)
		{
			if (seats[i][j] !=booked && seats[i][j]!=paid)
			{
				//std::cout << "Row " << i << " seat " << j << " is free." << std::endl;
				std::cout << j << "  ";
			}
			else if(!(seats[i][j] != booked && seats[i][j] != paid)&& j<10)
			{
				std::cout << "X  ";
			}
			else if (!(seats[i][j] != booked && seats[i][j] != paid) && j > 100)
			{
				std::cout << "X  ";
			}
			else
			{
				std::cout << "XX  ";
			}
			
		}
		
		std::cout<<"Row: "<<i<<std::endl;
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
				std::cout << "Row " << i << " seat " << j << " is booked." << std::endl;
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
				std::cout << "Row " << i  << " seat " << j << " is bought."<<std::endl;
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

