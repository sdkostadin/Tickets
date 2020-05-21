#include <iostream>
#include <vector>
#include <string>

#include "WorkFile.h"


int main()
{
	System s;
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
					Event ev(date, halls[i], name);
					s.createEvent({ ev });
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
			s.book(row, seat, date, name, note);
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
			s.unbook(row, seat, date, name);
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
			if (s.isBooked2(row, seat, date, name))
			{
				std::cin >> note;
				s.buy(row, seat, date, name, note);
				std::cout << std::endl;


			}
			else
			{
				s.buy(row, seat, date, name, note);
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
			if (d == 'Y' && n == 'Y')
			{
				std::cin >> day;
				std::cin.get();
				std::cin >> month;
				std::cin.get();
				std::cin >> year;
				std::cin >> name;
				date.setDay(day);
				date.setMonth(month);
				date.setYear(year);
				s.bookings(name, date);
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
				s.bookings(date);
			}
			else if (d == 'N' && n == 'Y')
			{

				std::cin >> name;

				s.bookings(name);
			}


		}
		else if (command == "check")
		{
			std::string ticketid;
			std::cin >> ticketid;
			s.check(ticketid);
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
			s.freeSeats(date, name);
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
				s.report(from, to, ID);
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
				s.report(from, to);
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
			s.tenPercent(from, to);
		}
		else if (command == "popular")
		{
		s.SortEvents();
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

	} while (command != "exit");
	work._exit();

	
}