#include "WorkFile.h"
#include <iostream>


void WorkFile::_open(std::string path)
{
	file.open(path);
	if (file.is_open())
	{
		std::cout << "File successfully opened.";
		std::ifstream ReadFile(path);
		getline(ReadFile, content, '@');
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
