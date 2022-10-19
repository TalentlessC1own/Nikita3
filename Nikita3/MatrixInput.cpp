#include "MatrixInput.h"
#include <time.h>


int  MatrixInput(std::vector<std::vector<int>>& matrix)
{

	std::cout << "1 - matrix byhand input " << std::endl
		<< "2 - matrix random input " << std::endl
		<< "3 - matrix file input" << std::endl;
	InputMode mode = static_cast<InputMode>(InputCheck::CheckMenu(3));
	switch (mode)
	{
	case InputMode::ConsoleByHand:
		matrix = ConsoleInput();
		break;

	case InputMode::ConsoleRandom:
		matrix = RandomInput();
		break;

	case InputMode::File:
		matrix = FileInput();
		break;

		
	}
	return static_cast<int>(mode);
}

std::vector<std::vector<int>> ConsoleInput()
{
	
		std::cout << "Enter lines ." << std::endl;;
		int lines = InputCheck::CheckIntValuePlus();
		std::cout << "Enter colums ." << std::endl;;
		int colums = InputCheck::CheckIntValuePlus();

		std::vector<std::vector<int>> matrix;

		for (int i = 0; i < lines; i++)
		{
			matrix.push_back(std::vector<int>{});
			for (int j = 0; j < colums; j++)
			{
				std::cout << "Enter [" << i + 1 << "] [" << j + 1 << "] ." << std::endl;
				matrix[i].push_back(InputCheck::CheckIntValue());
			}
		}
		return matrix;
}

std::vector<std::vector<int>> FileInput()
{
	std::string file_name = "";
	std::ifstream file;
	std::vector<std::vector<int>> matrix;
	file.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	while (true)
	{
		std::cout << "Enter file name. " << std::endl << "ENTER : ";
		std::cin >> file_name;
		if (file_name.find(".txt") >= std::string::npos) {
			std::cout << "Wrong data type\n" << std::endl;
			continue;
		}
		try
		{
			file.open(file_name);
			std::cout << "Sucefull file open " << std::endl;
		}
		catch (const std::exception&)
		{
			std::cout << "Incorrect file name or way.Try again ." << std::endl;
			continue;

		}

		try
		{
			int lines = (InputCheck::CheckLineUnsInt(file));
			int colums = (InputCheck::CheckLineUnsInt(file));
		

			for (int i = 0; i < lines; i++)
			{
				matrix.push_back(std::vector<int>{});
				for (int j = 0; j < colums; j++)
				{
					matrix[i].push_back( InputCheck::CheckLineInt(file));
				}
			}
		}
		catch (std::exception&)
		{
			file.close();
			continue;
		}
		std::cin.clear();
		std::cin.ignore();
		file.close();
		return matrix;
	}
}

std::vector<std::vector<int>>  RandomInput() 
{
	srand(static_cast<unsigned>(time(nullptr)));
	std::cout << "Enter lines ." << std::endl;;
	int lines = InputCheck::CheckIntValuePlus();
	std::cout << "Enter colums ." << std::endl;;
	int colums = InputCheck::CheckIntValuePlus();

	std::vector<std::vector<int>>	matrix;

	for (int i = 0; i < lines; i++)
	{
		matrix.push_back(std::vector<int>{});
		for (int j = 0; j < colums; j++)
		{
			matrix[i].push_back(std::rand() % 101 - 50);
		}
	}
	return matrix;
}

