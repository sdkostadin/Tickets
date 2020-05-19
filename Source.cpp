#include <iostream>
#include "Ticket.h"
#include <vector>
#include "WorkFile.h"
#include <string>
#include "Date.h"
#include "System.h"

int main()
{
	Event events[5];
	Hall hall1(1, 10, 10);
	Date date1(13, 3, 2020);
	Date date2(10, 5, 2013);
	std::string ss = "allabala";
	std::cout << hall1.getRows() << std::endl;
	
	

	
	
	
	WorkFile work;
	work.help();

	


	Date as;
	as.setDay(3);
	as.setMonth(3);
	as.setYear(2003);
	Date ad;
	ad.setDay(3);
	ad.setMonth(3);
	ad.setYear(2005);
	
	if (as <= ad)
	{
		std::cout << 134134134311312123 << std::endl;
	}
	else
	{
		std::cout << "kur"<<std::endl;
	}
	if (as >= ad)
	{
		std::cout << 134134134311312123 << std::endl;
	}
	else
	{
		std::cout << "kur" << std::endl;
	}
	if (as == ad)
	{
		std::cout << 134134134311312123 << std::endl;
	}
	else
	{
		std::cout << "kur" << std::endl;
	}
	if (as < ad)
	{
		std::cout << 134134134311312123 << std::endl;
	}
	else
	{
		std::cout << "kur" << std::endl;
	}
	if (as > ad)
	{
		std::cout << 134134134311312123 << std::endl;
	}
	else
	{
		std::cout << "kur" << std::endl;
	}

}