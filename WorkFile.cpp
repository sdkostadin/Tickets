#include <iostream>
#include "WorkFile.h"
#include "System.h"


void WorkFile::_open(std::string path,System& s)
{
	file.open(path);
	if (file.is_open())
	{
		std::cout << "File successfully opened.";
		std::ifstream ReadFile(path);
		getline(ReadFile, content, '@');
		filetoString(s);
	}
	else
	{
		std::cout << "File unsuccessfully opened!";
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
}

void WorkFile::_saveas(std::string place)
{
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
	std::vector<std::string> hallid;
	std::vector<std::string> date;
	std::vector<std::string> name;
	std::istringstream readWords(content);
	std::string word;
	std::string num;
	int number;
	Event currEvent;
	while (readWords >> word)
	{
		Words.push_back(word);
	}
	
	for (size_t i = 0; i < Words.size(); i++)
	{
		if (Words[i] == "hall")
		{
			
			num = Words[i + 1];
			std::istringstream readNums(num);
			int intnum;
			std::vector<int>nums;
			while (readNums >> intnum)
			{
				nums.push_back(intnum);
			}
			currEvent.getHall().setId(nums[0]);
			nums.clear();
			

		}
		if (Words[i] == "date")
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
		}
		if (Words[i] == "name")
		{
			int start = i + 1;
			int end;
			std::string name;
			for (int j = 0; j < Words.size(); j++)
			{
				if (i + j > Words.size())
				{
					break;
				}
				if (Words[i + j] == "$" || Words[i + j] == "@")
				{
					end = i + j;
					break;
				}
			}
			for (size_t h = start; h < end; h++)
			{
				name += Words[h];
			}
		
			currEvent.setName(name);
		}
		if (Words[i] == "$")
		{
			s.createEvent(currEvent);
		}
	}
}
