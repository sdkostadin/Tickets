#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>
#include "System.h"
class WorkFile
{
public:

	WorkFile() = default;
	WorkFile(const WorkFile& other) = delete;
	WorkFile& operator=(const WorkFile& other) = delete;
	void _open(std::string path, System& s);
	void _close();
	void _save();
	void _saveas(std::string place);
	void _help();
	void _exit();
	void filetoString(System& s);
private:

	std::fstream file;
	std::string fileName;
	std::string content;
	
};

