#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Event.h"
class Ticket
{
public:

	Ticket(int _row = 0, int _seat = 0, const  Event* _event = nullptr);
	
	int getSeat() const { return seat; }
	int getRows() const { return row; }
	const std::string getcode() const { return code; }
	const Event* getEvent() const { return event; }

	void setCode(std::string code);

private:


	int row;
	int seat;
	std::string code;
	const Event* event;
};

