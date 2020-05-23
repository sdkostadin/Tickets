#include <iostream>
#include <vector>
#include <string>
#include "System.h"
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
			std::cout << "Add event date: ";
			std::cin >> day;
			std::cin.get();
			std::cin >> month;
			std::cin.get();
			std::cin >> year;
			std::cout << "Add event hall: ";
			std::cin >> id;
			std::cout << "Add event name: ";
			std::cin >> name;
			date.setDay(day);
			date.setMonth(month);
			date.setYear(year);
			if (date.validation())
			{
				for (size_t i = 0; i < halls.size(); i++)
				{
					if (halls[i].getId() == id)
					{
						Event ev(date, halls[i], name);
						s.createEvent({ ev });
						std::cout << std::endl;
						work.newInformation("addevent " + std::to_string(ev.getDate().getDay()) + '.' + std::to_string(ev.getDate().getMonth()) + '.' + std::to_string(ev.getDate().getYear()) + " "
							+ std::to_string(halls[i].getId()) + " " + ev.getName() + '\n');

					}
				}
			}
			else
			{
				std::cout << "Invalid date input." << std::endl;
			}
		}
		else if (command == "book")
		{
			std::string name, note;
			std::cout << "Add row: ";
			std::cin >> row;
			std::cout << "Add seat: ";
			std::cin >> seat;
			std::cout << "Add event date: ";
			std::cin >> day;
			std::cin.get();
			std::cin >> month;
			std::cin.get();
			std::cin >> year;
			std::cout << "Add event name: ";
			std::cin >> name;
			std::cout << "Add note: ";
			std::cin >> note;
			date.setDay(day);
			date.setMonth(month);
			date.setYear(year);
			if (date.validation())
			{
				s.book(row, seat, date, name, note);
				std::cout << std::endl;
				work.newInformation("book " + std::to_string(row) + " " + std::to_string(seat) + " " + std::to_string(date.getDay()) + '.' + std::to_string(date.getMonth()) + '.' + std::to_string(date.getYear()) + " " +
					name  + '\n');
			}
			else
			{
				std::cout << "Invalid date input." << std::endl;
			}
		}

		else if (command == "unbook")
		{
			std::string name;
			std::cout << "Add row: ";
			std::cin >> row;
			std::cout << "Add seat: ";
			std::cin >> seat;
			std::cout << "Add event date: ";
			std::cin >> day;
			std::cin.get();
			std::cin >> month;
			std::cin.get();
			std::cin >> year;
			std::cout << "Add event name: ";
			std::cin >> name;
			date.setDay(day);
			date.setMonth(month);
			date.setYear(year);
			if (date.validation())
			{
				s.unbook(row, seat, date, name);
				std::cout << std::endl;
			}
			else
			{
				std::cout << "Invalid date input." << std::endl;
			}
			

		}
		else if (command == "buy")
		{
			std::string name, note = "";
			std::cout << "Add row: ";
			std::cin >> row;
			std::cout << "Add seat: ";
			std::cin >> seat;
			std::cout << "Add event date: ";
			std::cin >> day;
			std::cin.get();
			std::cin >> month;
			std::cin.get();
			std::cin >> year;
			std::cout << "Add event name: ";
			std::cin >> name;
			date.setDay(day);
			date.setMonth(month);
			date.setYear(year);
			if (date.validation())
			{
				if (s.isBooked2(row, seat, date, name))
				{
					std::cin >> note;
					s.buy(row, seat, date, name, note);
					std::cout << std::endl;
					work.newInformation("buy " + std::to_string(row)+ " " + std::to_string(seat) + " " + std::to_string(date.getDay()) + '.' + std::to_string(date.getMonth()) + '.' + std::to_string(date.getYear()) +
						" " +name + " " + note + '\n');


				}
				else
				{
					s.buy(row, seat, date, name, note);
					work.newInformation("buy " + std::to_string(row) +" "+ std::to_string(seat) + " " + std::to_string(date.getDay()) + '.' + std::to_string(date.getMonth()) + '.' + std::to_string(date.getYear()) 
						+" "+ name + " " + note + " "  + '\n');
					std::cout << std::endl;

				}
			}
			else
			{
				std::cout << "Invalid date input." << std::endl;
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
				std::cout << "Add event date: ";
				std::cin >> day;
				std::cin.get();
				std::cin >> month;
				std::cin.get();
				std::cin >> year;
				std::cout << "Add event name: ";
				std::cin >> name;
				date.setDay(day);
				date.setMonth(month);
				date.setYear(year);
				if (date.validation())
				{
					s.bookings(name, date);
				}
				else
				{
					std::cout << "Invalid date input." << std::endl;
				}
			}
			else if (d == 'Y' && n == 'N')
			{
				std::cout << "Add event date: ";
				std::cin >> day;
				std::cin.get();
				std::cin >> month;
				std::cin.get();
				std::cin >> year;

				date.setDay(day);
				date.setMonth(month);
				date.setYear(year);
				if (date.validation())
				{
					s.bookings(date);
				}
				else
				{
					std::cout << "Invalid date input." << std::endl;
				}
			}
			else if (d == 'N' && n == 'Y')
			{
				std::cout << "Add event name: ";
				std::cin >> name;

				s.bookings(name);
			}


		}
		else if (command == "check")
		{
			std::string ticketid;
			std::cout << "Add ticket ID: ";
			std::cin >> ticketid;
			s.check(ticketid);
		}
		else if (command == "freeseats")
		{
			std::string name;
			std::cout << "Add event date: ";
			std::cin >> day;
			std::cin.get();
			std::cin >> month;
			std::cin.get();
			std::cin >> year;
			std::cout << "Add event name: ";
			std::cin >> name;
			date.setDay(day);
			date.setMonth(month);
			date.setYear(year);
			if (date.validation())
			{
				s.freeSeats(date, name);
			}
			else
			{
				std::cout << "Invalid date input." << std::endl;
			}
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
				std::cout << "From: ";
				std::cin >> day1;
				std::cin.get();
				std::cin >> month1;
				std::cin.get();
				std::cin >> year1;
				from.setDay(day1);
				from.setMonth(month1);
				from.setYear(year1);
				std::cout << "To: ";
				std::cin >> day2;
				std::cin.get();
				std::cin >> month2;
				std::cin.get();
				std::cin >> year2;
				to.setDay(day2);
				to.setMonth(month2);
				to.setYear(year2);
				if (from.validation() && to.validation())
				{
					std::cout << "Add hall ID ";
					std::cin >> ID;
					s.report(from, to, ID);
				}
				else
				{
					std::cout << "Invalid date input." << std::endl;
				}
			}
			else
			{
				std::cout << "From: ";
				std::cin >> day1;
				std::cin.get();
				std::cin >> month1;
				std::cin.get();
				std::cin >> year1;
				from.setDay(day1);
				from.setMonth(month1);
				from.setYear(year1);
				std::cout << "To: ";
				std::cin >> day2;
				std::cin.get();
				std::cin >> month2;
				std::cin.get();
				std::cin >> year2;
				to.setDay(day2);
				to.setMonth(month2);
				to.setYear(year2);
				if (from.validation() && to.validation())
				{
					s.report(from, to);
				}
				else
				{
					std::cout << "Invalid date input." << std::endl;
				}
			}
		}
		else if (command == "underten")
		{
			Date from;
			Date to;
			int day1, month1, year1, day2, month2, year2;
			std::cout << "From: ";
			std::cin >> day1;
			std::cin.get();
			std::cin >> month1;
			std::cin.get();
			std::cin >> year1;
			from.setDay(day1);
			from.setMonth(month1);
			from.setYear(year1);
			std::cout << "To: ";
			std::cin >> day2;
			std::cin.get();
			std::cin >> month2;
			std::cin.get();
			std::cin >> year2;
			to.setDay(day2);
			to.setMonth(month2);
			to.setYear(year2);
			if (from.validation() && to.validation())
			{
				s.tenPercent(from, to);
			}
			else
			{
				std::cout << "Invalid date input." << std::endl;
			}
		}
		else if (command == "popular")
		{
		s.SortEvents();
		}
		else if (command == "open")
		{
		std::string address;
		std::cout << "Add file address: ";
		std::cin >> address;
		work._open(address, s);
		}
		else if (command == "close")
		{
		work._close();
		}
		else if (command == "save")
		{
		work._save();
		}
		else if (command == "saveas")
		{
		std::string address;
		std::cout << "Add file address: ";
		std::cin >> address;
		work._saveas(address);
		}
		else if (command == "help")
		{
			work._help();
		}

	} while (command != "exit");
	work._exit();

	return 0;
}