#pragma once
#include <ctime>
#include <vector>
#include <string>
#include "Hall.h"
#include "Date.h"

enum status
{
	def,
	paid,
	booked,
	unbooked
};

class Event
{

public:
	Event(Date _date = {}, Hall _hall = {}, std::string _name = "untitled");
	Event& operator=(const Event& other);
	~Event();

	
	Date getDate() const { return date; }
	const std::string getName() const { return name; }
	Hall getHall() const { return hall; }
	int getRows() const { return hall.getRows(); }
	int getSeatsOnRow() const { return hall.getSeatsOnRow(); }
	int getFreeSeats() const { return freeSeats; }
	int getSoldSeats() const { return soldSeats; }
	status getSeatStatus(int row, int seat) const { return seats[row-1][seat-1]; }
	std::string getTicketId(int row, int seat) const { return ticketid[row - 1][seat - 1]; }
	std::string getNote(int row, int seat) const { return note[row - 1][seat - 1]; }
	void setId(int row, int seat);
	void bookSeat(int row, int seat);
	void unbookSeat(int row, int seat);
	void buySeat(int row, int seat);
	void print() const;
	void printSeatStatus() const;
	void printBooked() const;
	

private:

	std::string name;
	Hall hall;
	Date date;
	int freeSeats;
	int soldSeats;
	std::vector<std::vector<std::string>> note;
	std::vector<std::vector<std::string>> ticketid;
	std::vector<std::vector<status>> seats;
	

	
	
	void copy(const Event& other);
	void clear();
};

