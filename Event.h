#ifndef EVENT_H
#define EVENT_H

#pragma once
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
	status getSeatStatus(int row, int seat) const { return seats[row][seat]; }
	std::string getTicketId(int row, int seat) const { return ticketid[row][seat]; }
	std::string getNote(int row, int seat) const { return note[row][seat]; }
	void setName(std::string _name);
	void setId(int row, int seat);
	void setDate(Date _date);
	void setHall(Hall id);
	bool bookSeat(int row, int seat, std::string _note);
	void setFreeSeats(int _freeseats) { freeSeats = _freeseats; };
	void setSoldSeats(int _soldseats) {soldSeats = _soldseats;}
	bool unbookSeat(int row, int seat);
	bool isBooked(int row, int seat);
	bool buySeat(int row, int seat, std::string _note);
	void print() const;
	void printFree() const;
	void printBooked() const;
	void printBought() const;
	void init(); 
	

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

#endif