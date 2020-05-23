#pragma once
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
#include "Event.h"

 
class System
{
public:
	System() = default;
	System(const System& other) = default;
	System& operator=(const System& other) = default;
	~System();
	
	bool createEvent(const Event& event);
	Event* getEvent(std::string name) const;
	void freeSeats(const Date& date, std::string name);
	bool book(int row, int seat, const Date& date, std::string name, std::string note);
	bool unbook(int row, int seat, const Date& date, std::string name);
	bool buy(int row, int seat, const Date& date, std::string name, std::string note);
	bool check(std::string _ticketid);
	void report(const Date& from, const Date& to, int Id);
	void report(const Date& from, const Date& to);
	void bookings(const std::string name, const Date& date);
	void bookings(const std::string name);
	void bookings(const Date& date);
	void tenPercent(const Date& from, const Date& to) const;
	bool SortEvents();
	bool isBooked2(int row, int seat, const Date& date, std::string name);
	void run();


private:

	std::vector<Event*> events;
	
};

