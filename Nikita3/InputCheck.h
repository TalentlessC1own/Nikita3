#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

class InputCheck
{
private:
	static std::string value_input;
	static int value;
public:
	static int CheckIntValue();
	static int CheckIntValuePlus();
	static int CheckMenu(int items);
	static int CheckLineInt(std::ifstream& file);
	static int CheckLineUnsInt(std::ifstream& file);
};

