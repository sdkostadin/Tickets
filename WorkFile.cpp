#include <iostream>
#include "WorkFile.h"
#include "System.h"


void WorkFile::_open(std::string path,System& s )
{
	file.open(path);
	if (file.is_open())
	{
		std::cout << "File successfully opened."<<std::endl;
		std::ifstream ReadFile(path);
		getline(ReadFile, content, '@');
		filetoString(s);
	}
	else
	{
		std::cout << "File unsuccessfully opened!"<<std::endl;
	}

}
void WorkFile::_close()
{
	if (file.is_open())
	{
		file.close();
		std::cout << "Succesfully closed " << fileName << std::endl;
	}
	else
	{
		std::cout << "File not opened!" << std::endl;
	}
}

void WorkFile::_save()
{
	writeInFile(fileName);
	std::cout << "Changes are made successfully!" << std::endl;
}

void WorkFile::_saveas(std::string place)
{
	
	std::ofstream newFile(place);
	writeInFile(place);
	std::cout << "New file was made successfully!" << std::endl;
}

void WorkFile::_help()
{
	std::cout
		<< "The following commands are supported: "<<std::endl
		<< "open <file>	opens <file>" << std::endl
		<< "close			closes currently opened file" << std::endl
		<< "save			saves the currently open file" << std::endl
		<< "saveas <file>	saves the currently open file in <file>" << std::endl
		<< "help			prints this information" << std::endl
		<< "exit			exists the program" << std::endl;
		
}

void WorkFile::_exit()
{
	if (file.is_open())
	{
		file.close();
	}
	std::cout << "Ending program!" << std::endl;
	return;
}

void WorkFile::filetoString(System& s)
{
	std::vector<std::string>Words;
	std::istringstream readWords(content);
	std::string word;
	Event currEvent;
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
	while (readWords >> word)
	{
		Words.push_back(word);
	}
	
	for (size_t i = 0; i < Words.size(); i++)
	{
		if (Words[i] == "addevent")
		{
			std::string date = Words[i + 1];
			Date res;
			for (size_t i = 0; i < date.length(); i++)
			{
				if (date[i] == '.')
				{
					date[i] = ' ';
				}
			}
			std::vector<int>numbers;
			int number;
			std::istringstream readNums(date);
			while (readNums >> number)
			{
				numbers.push_back(number);
			}
			res.setDay(numbers[0]);
			res.setMonth(numbers[1]);
			res.setYear(numbers[2]);
			currEvent.setDate(res);
			currEvent.setName(Words[i + 3]);
			int id = std::stoi(Words[i + 2]);
			for (size_t i = 0; i < halls.size(); i++)
			{
				if (halls[i].getId() == id)
				{
					currEvent.setHall(halls[i]);
					currEvent.init();
					s.createEvent(currEvent);
				}
			}
		}
		
		if (Words[i] == "book")
		{
			int row = std::stoi(Words[i + 1]);
			int col = std::stoi(Words[i + 2]);
			std::string date = Words[i + 3];
			Date res;
			for (size_t i = 0; i < date.length(); i++)
			{
				if (date[i] == '.')
				{
					date[i] = ' ';
				}
			}
			std::vector<int>numbers;
			int number;
			std::istringstream readNums(date);
			while (readNums >> number)
			{
				numbers.push_back(number);
			}
			res.setDay(numbers[0]);
			res.setMonth(numbers[1]);
			res.setYear(numbers[2]);
			s.book(row, col, res, Words[i + 4], Words[i + 5]);
		}
		if (Words[i] == "buy")
		{
			int row = std::stoi(Words[i + 1]);
			int col = std::stoi(Words[i + 2]);
			std::string date = Words[i + 3];
			Date res;
			for (size_t i = 0; i < date.length(); i++)
			{
				if (date[i] == '.')
				{
					date[i] = ' ';
				}
			}
			std::vector<int>numbers;
			int number;
			std::istringstream readNums(date);
			while (readNums >> number)
			{
				numbers.push_back(number);
			}
			res.setDay(numbers[0]);
			res.setMonth(numbers[1]);
			res.setYear(numbers[2]);
			s.buy(row, col, res, Words[i + 4], Words[i + 5]);
		}
	}
	
}

void WorkFile::writeInFile(std::string path)
{
	std::ofstream write(path);
	write << newWritings;
	write << content << "@" << std::endl;
}

void WorkFile::newInformation(std::string info)
{
	newWritings += info;
}
