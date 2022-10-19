#include "InputCheck.h"

int InputCheck::value = 0;
std::string InputCheck::value_input = "";

int InputCheck::CheckIntValue()
{
	while (true)
	{
		std::cout << "ENTER : ";
		std::getline(std::cin, value_input);
		try
		{
			value = stoi(value_input);

			return value;
		}
		catch (std::exception&)
		{

			std::cout << "Error. Try again. " << std::endl;

		}

	}
}
int InputCheck::CheckIntValuePlus()
{
	while (true)
	{
		std::cout << "ENTER : ";
		std::getline(std::cin, value_input);
		try
		{
			value = stoi(value_input);

			if (value < 0)
				throw std::exception("NegativeInt");
			else 
				return value;
		}
		catch (std::exception&)
		{

			std::cout << "Error. Try again. " << std::endl;

		}

	}
}

int InputCheck::CheckMenu(int items)
{
	while (true)
	{

		std::cout << "ENTER : ";
		std::getline(std::cin, value_input);

		try
		{
			value = stoi(value_input);
			if (value <= items && value >= 1)
				return value;
			else
				throw value;
		}
		catch (std::exception&)
		{

			std::cout << "Non-existent menu item.Try again. " << std::endl;
		}
		catch (int ex_value)
		{
			std::cout << ex_value << " menu item does not exist.Try again." << std::endl;
		}
	}
}

int InputCheck::CheckLineInt(std::ifstream& file)
{

	std::string temp_v = "";
	int temp_i = 0;

	try
	{
		std::getline(file, temp_v);
	}
	catch (const std::exception&)
	{
		std::cout << "There is not enough data in the file or incorrect file filling form.  " << std::endl;

		throw  std::exception("Wrong data");

	}
	try
	{
		temp_i = stoi(temp_v);
		return temp_i;
	}
	catch (const std::exception&)
	{
		std::cout << "Wrong data type.  " << std::endl;

		throw std::exception("Wrong data");
	}
}

int InputCheck::CheckLineUnsInt(std::ifstream& file)
{
	std::string temp_v = "";
	int temp_i = 0;

	try
	{
		std::getline(file, temp_v);
	}
	catch (const std::exception&)
	{
		std::cout << "There is not enough data in the file or incorrect file filling form.  " << std::endl;

		throw  std::exception("Wrong data");
		
	}
	try
	{
		temp_i = stoi(temp_v);
		if (temp_i < 0)

		{
			throw  std::exception("Wrong data");
		}
		else
			return temp_i;
	}
	catch (const std::exception&)
	{
		std::cout << "Wrong data type.  " << std::endl;

		throw std::exception("Wrong data");
	}
}

