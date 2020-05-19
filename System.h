#pragma once
#include <vector>
#include "Event.h"
#include "Hall.h"
#include <iostream>
class System
{
public:
	~System();
	
	bool createEvent(const Event& event);
	Event* getEvent(std::string name) const;
	void freeSeats(const Date& date, std::string name);
	void book(int row, int seat, const Date& date, std::string name, std::string note);
	void unbook(int row, int seat, const Date& date, std::string name);
	void buy(int row, int seat, const Date& date, std::string name);
	void report(const Date& from, const Date& to, int Id);
	void report(const Date& from, const Date& to);
	void bookings(const std::string name, const Date& date);
	void bookings(const std::string name);
	void bookings(const Date& date);

private:

	std::vector<Event*> events;
	
	
	
	

};

