#include "System.h"

System::~System()
{
	for (size_t i = 0; i < events.size(); i++)
	{
		delete events[i];
	}
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
		std::cout << "Successfully added event" << std::endl;
		return true;
	}

	
	std::cout << "Event was not added!" << std::endl;
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
			std::cout << "Free Seats are: " << events[i]->getFreeSeats() << std::endl;
			events[i]->printFree();
			
		}
	}
}

bool System::book(int row, int seat, const Date& date, std::string name, std::string note)
{
	for (size_t i = 0; i < events.size(); i++)
	{
		if (events[i]->getDate() == date && events[i]->getName() == name)
		{
			events[i]->bookSeat(row, seat, note);
			return true;
		}
	}
	return false;
}

bool System::unbook(int row, int seat, const Date& date, std::string name)
{
	for (size_t i = 0; i < events.size(); i++)
	{
		if (events[i]->getDate() == date && events[i]->getName() == name)
		{
			events[i]->unbookSeat(row, seat);
			return true;
		}
	}
	return false;
}

bool System::buy(int row, int seat, const Date& date, std::string name, std::string note)
{
	for (size_t i = 0; i < events.size(); i++)
	{
		if (events[i]->getDate() == date && events[i]->getName() == name)
		{
			events[i]->buySeat(row, seat, note);
			return true;
		}
	}
	return false;
}

bool System::check(std::string _ticketid)
{
	for (size_t i = 0; i <events.size() ; i++)
	{
		for (int j = 0; j < events[i]->getHall().getRows(); j++)
		{
			for (int k = 0; k < events[i]->getHall().getSeatsOnRow(); k++)
			{
				if (events[i]->getTicketId(j, k) == _ticketid)
				{
					std::cout << "Ticket for event: " << events[i]->getName() <<
						" on date " << events[i]->getDate() << " on row " << j  << " seat " << k <<std::endl;
					return true;
				}
			}
		}
	}
	return false;
	std::cout << "There is no ticket with that id!"<< std::endl;
}

void System::report(const Date& from, const Date& to, int Id)
{
	for (size_t i = 0; i < events.size(); i++)
	{
		if (events[i]->getDate() >= from && events[i]->getDate() <= to
			&& events[i]->getHall().getId() == Id)
		{
			events[i]->print();
			std::cout << "Bought tickets: " << events[i]->getSoldSeats()<<std::endl;
			events[i]->printBought();
		}
	}

}

void System::report(const Date& from, const Date& to)
{
	for (size_t i = 0; i < events.size(); i++)
	{
		if (events[i]->getDate() >= from && events[i]->getDate() <= to)
		{
			events[i]->print();
			std::cout << "Bought tickets: " << events[i]->getSoldSeats() << std::endl;
			events[i]->printBought();
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

void System::tenPercent(const Date& from, const Date& to) const
{
	for (size_t i = 0; i < events.size(); i++)
	{
		if (events[i]->getDate() >= from && events[i]->getDate() <= to)
		{
			double helper = events[i]->getSoldSeats()/ events[i]->getHall().getAllSeats() ;
			if (helper < 0.1 || events[i]->getSoldSeats()==0)
			{
				events[i]->print();
				std::cout << "Bought tickets: " << events[i]->getSoldSeats()<< " from " << events[i]->getHall().getAllSeats() <<std::endl;
			}
		}
	}
}

bool System::SortEvents()
{
	std::sort(events.begin(), events.end(),
		[](Event* a, Event* b) { return a->getSoldSeats() > b->getSoldSeats(); });
	for (size_t i = 0; i < events.size(); i++)
	{
		events[i]->print();
		std::cout << events[i]->getSoldSeats() << " bought  tickets, from " << events[i]->getHall().getAllSeats() <<std::endl;
	}
	return true;
}



bool System::isBooked2(int row, int seat, const Date& date, std::string name)
{
	for (size_t i = 0; i < events.size(); i++)
	{
		if (events[i]->getDate() == date && events[i]->getName() == name)
		{
			if (events[i]->isBooked(row, seat))
			{
				return true;
			}
		}
	}
	return false;
}




