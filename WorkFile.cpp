#include "WorkFile.h"
#include <iostream>

WorkFile::WorkFile()
{

}

void WorkFile::open()
{
}

void WorkFile::save()
{
}

void WorkFile::save_as()
{
}

void WorkFile::help()
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

void WorkFile::exit()
{
}
