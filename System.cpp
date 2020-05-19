#include "System.h"

System::~System()
{

}

bool System::createEvent(const Event& event)
{
	for (size_t i = 0; i < events.size(); i++)
	{
		if (event.getDate() == events[i]->getDate() &&
			event.getHall().getId() == events[i]->getHall().getId())
		{
			std::cout << "There is already an event in this hall on that date" << std::endl;
			return false;
		}
	}
	if (getEvent(event.getName()) == nullptr) 
	{
		events.push_back(new Event(event));
		std::cout << "Successfully added event";
		return true;
	}

	return false;
}


Event* System::getEvent(std::string name) const
{
	for (size_t i = 0; i < events.size(); i++)
	{
		if (events[i]->getName().compare(name) == 0)
		{
			return events[i];
		}
	}
	return nullptr;
}

void System::freeSeats(const Date& date, std::string name)
{
	for (size_t i = 0; i < events.size(); i++)
	{
		if (events[i]->getDate() == date && events[i]->getName() == name)
		{
			events[i]->print();
			events[i]->printSeatStatus();
			std::cout << "Free Seats are: " << events[i]->getFreeSeats() << std::endl;
		}
	}
}

void System::book(int row, int seat, const Date& date, std::string name, std::string note)
{
	for (size_t i = 0; i < events.size(); i++)
	{
		if (events[i]->getDate() == date && events[i]->getName() == name)
		{
			events[i]->bookSeat(row, seat);
			std::cout << "Seat booked." << std::endl;
			break;
		}
	}
}

void System::unbook(int row, int seat, const Date& date, std::string name)
{
	for (size_t i = 0; i < events.size(); i++)
	{
		if (events[i]->getDate() == date && events[i]->getName() == name)
		{
			events[i]->unbookSeat(row, seat);
			std::cout << "Seat unbooked." << std::endl;
			break;
		}
	}
}

void System::buy(int row, int seat, const Date& date, std::string name)
{
	for (size_t i = 0; i < events.size(); i++)
	{
		if (events[i]->getDate() == date && events[i]->getName() == name)
		{
			events[i]->buySeat(row, seat);
			std::cout << "Seat bought." << std::endl;
			break;
		}
	}
}

void System::report(const Date& from, const Date& to, int Id)
{
	for (size_t i = 0; i < events.size(); i++)
	{
		if (events[i]->getDate() >= from && events[i]->getDate() <= to
			&& events[i]->getHall().getId() == Id)
		{
			std::cout << events[i];
		}
	}

}

void System::report(const Date& from, const Date& to)
{
	for (size_t i = 0; i < events.size(); i++)
	{
		if (events[i]->getDate() >= from && events[i]->getDate() <= to)
		{
			std::cout << events[i];
		}
	}

}

void System::bookings(const std::string name, const Date& date)
{
	for (size_t i = 0; i < events.size(); i++)
	{
		if (events[i]->getDate() == date && events[i]->getName() == name)
		{
			events[i]->print();
			events[i]->printBooked();
		}
	}
}

void System::bookings(const std::string name)
{
	for (size_t i = 0; i < events.size(); i++)
	{
		if (events[i]->getName() == name)
		{
			events[i]->print();
			events[i]->printBooked();
		}
	}
}

void System::bookings(const Date& date)
{
	for (size_t i = 0; i < events.size(); i++)
	{
		if (events[i]->getDate() == date )
		{
			events[i]->print();
			events[i]->printBooked();
		}
	}
}


