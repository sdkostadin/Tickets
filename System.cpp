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
		std::cout << "Successfully added event";
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
			std::cout << "Seat bought." << std::endl;
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
						" on date " << events[i]->getDate() << " on row " << j + 1 << " seat " << k + 1;
					return true;
				}
				else
				{
					std::cout << "Invalid ID!";
					return false;
				}
			}
		}
	}
	return false;
	std::cout << "There is no ticket with that id!";
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
				std::cout << "Bought tickets: " << events[i]->getSoldSeats()<<std::endl;
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
		std::cout << events[i]->getSoldSeats() << " bought  tickets " << std::endl;
	}
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

void System::run()
{
	std::vector<Hall> halls;
	Hall hall1(1, 50, 20);
	Hall hall2(2, 20, 10);
	Hall hall3(3, 70, 15);
	Hall hall4(4, 80, 20);
	Hall hall5(5, 100, 20);
	Hall hall6(6, 60, 30);
	halls.push_back(hall1);
	halls.push_back(hall2);
	halls.push_back(hall3);
	halls.push_back(hall4);
	halls.push_back(hall5);
	halls.push_back(hall6);
	Date date;
	int day, month, year;
	int row, seat;
	std::string command;
	WorkFile work;

	do
	{
		std::cout << ">>";
		std::cin >> command;
		if (command == "addevent")
		{

			int  id;
			std::string name;
			std::cin >> day;
			std::cin.get();
			std::cin >> month;
			std::cin.get();
			std::cin >> year >> id >> name;
			date.setDay(day);
			date.setMonth(month);
			date.setYear(year);
			for (size_t i = 0; i < halls.size(); i++)
			{
				if (halls[i].getId() == id)
				{
					Event ev (date, halls[i], name);
					createEvent({ ev });
					std::cout << std::endl;
				}
			}
			

		}
		else if (command == "book")
		{
			std::string name, note;
			std::cin >> row >> seat >> day;
			std::cin.get();
			std::cin >> month;
			std::cin.get();
			std::cin >> year >> name >> note;
			date.setDay(day);
			date.setMonth(month);
			date.setYear(year);
			book(row, seat, date, name, note);
			std::cout << std::endl;
			
		}

		else if (command == "unbook")
		{
			std::string name;
			std::cin >> row >> seat >> day;
			std::cin.get();
			std::cin >> month;
			std::cin.get();
			std::cin >> year >> name;
			date.setDay(day);
			date.setMonth(month);
			date.setYear(year);
			unbook(row, seat, date, name);
			std::cout << std::endl;
			
		}
		else if (command == "buy")
		{
			std::string name, note = "";
			std::cin >> row >> seat >> day;
			std::cin.get();
			std::cin >> month;
			std::cin.get();
			std::cin >> year >> name;
			date.setDay(day);
			date.setMonth(month);
			date.setYear(year);
			if (isBooked2(row, seat, date, name))
			{
				std::cin >> note;
				buy(row, seat, date, name, note);
				std::cout << std::endl;
				

			}
			else
			{
				buy(row, seat, date, name, note);
				std::cout << std::endl;
				
			}
		}
		else if (command == "bookings")
		{
			std::string name;
			char d;
			char n;
			std::cout << "Do you want to type date? Y/N " << std::endl;
			std::cin >> d;
			std::cout << "Do you want to type name? Y/N " << std::endl;
			std::cin >> n;
			if (d == 'Y'&& n=='Y')
			{
				std::cin >> day;
				std::cin.get();
				std::cin >> month;
				std::cin.get();
				std::cin >> year;
				std::cin>> name;
				date.setDay(day);
				date.setMonth(month);
				date.setYear(year);
				bookings(name, date);
			}
			else if (d == 'Y' && n == 'N')
			{
				std::cin >> day;
				std::cin.get();
				std::cin >> month;
				std::cin.get();
				std::cin >> year;
				
				date.setDay(day);
				date.setMonth(month);
				date.setYear(year);
				bookings(date);
			}
			else if(d == 'N' && n == 'Y')
			{
				
				std::cin >> name;
				
				bookings(name);
			}
			
			
		}
		else if (command == "check")
		{
		std::string ticketid;
		std::cin >> ticketid;
		check(ticketid);
		}
		else if (command == "freeseats")
		{
		std::string name;
		std::cin >> day;
		std::cin.get();
		std::cin >> month;
		std::cin.get();
		std::cin >> year;
		std::cin >> name;;
		date.setDay(day);
		date.setMonth(month);
		date.setYear(year);
		freeSeats(date,name);
		}
		else if (command == "report")
		{
			Date from;
			Date to;
			char h;
			int day1, month1, year1, day2, month2, year2;
			std::cout << "Do you want to type hall ID? Y/N" << std::endl;
			std::cin >> h;
			if (h == 'Y')
			{
				int ID;
				std::cin >> day1;
				std::cin.get();
				std::cin >> month1;
				std::cin.get();
				std::cin >> year1;
				from.setDay(day1);
				from.setMonth(month1);
				from.setYear(year1);
				std::cin >> day2;
				std::cin.get();
				std::cin >> month2;
				std::cin.get();
				std::cin >> year2;
				to.setDay(day2);
				to.setMonth(month2);
				to.setYear(year2);
				std::cin >> ID;
				report(from, to, ID);
			}
			else
			{
				std::cin >> day1;
				std::cin.get();
				std::cin >> month1;
				std::cin.get();
				std::cin >> year1;
				from.setDay(day1);
				from.setMonth(month1);
				from.setYear(year1);
				std::cin >> day2;
				std::cin.get();
				std::cin >> month2;
				std::cin.get();
				std::cin >> year2;
				to.setDay(day2);
				to.setMonth(month2);
				to.setYear(year2);
				report(from, to);
			}
		}
		else if (command == "underten")
		{
		Date from;
		Date to;
		int day1, month1, year1, day2, month2, year2;
		std::cin >> day1;
		std::cin.get();
		std::cin >> month1;
		std::cin.get();
		std::cin >> year1;
		from.setDay(day1);
		from.setMonth(month1);
		from.setYear(year1);
		std::cin >> day2;
		std::cin.get();
		std::cin >> month2;
		std::cin.get();
		std::cin >> year2;
		to.setDay(day2);
		to.setMonth(month2);
		to.setYear(year2);
		tenPercent(from, to);
		}
		else if (command == "popular")
		{
		SortEvents();
		}
		else if (command == "open")
		{
		
		}
		else if (command == "close")
		{

		}
		else if (command == "save")
		{

		}
		else if (command == "saveas")
		{

		}
		else if (command == "help")
		{
		 work._help();
		}
	
	}
		while (command != "exit");
		work._exit();
	
}




