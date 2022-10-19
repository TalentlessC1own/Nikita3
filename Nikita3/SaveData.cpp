#include "SaveData.h"
#include <fstream>
#include"InputCheck.h"
#include"SaveData.h"
#include "SortedMatrix.h"

void SaveData(std::vector<std::shared_ptr<ISort>>& sortsCase, std::vector < std::shared_ptr<SortedMatrix>> sortsMatrices)
{
	const int this_file = 1;
	std::string name;
	std::ofstream  FileRecorder;
	FileRecorder.exceptions(std::ofstream::badbit | std::ofstream::failbit);
	std::ifstream CheckFileExist;
	CheckFileExist.exceptions(std::ifstream::badbit | std::ifstream::failbit);


	while (true)
	{
		std::cout << "Enter file name or full way." << std::endl << "ENTER:";
		std::getline(std::cin, name);
		if (name.find(".txt") >= std::string::npos) {
			std::cout << "Wrong data type\n" << std::endl;
			continue;
		}
		try
		{
			CheckFileExist.open(name);
			std::cout << "A file with the same name already exists. " << std::endl
				<< "1 - Save in this file " << std::endl
				<< "2 - Chose another name " << std::endl;
			int var = InputCheck::CheckMenu(2);
			if (var == this_file)
			{
				FileRecorder.open(name);
				CheckFileExist.close();
			}
			else
			{
				CheckFileExist.close();
				continue;
			}
		}
		catch (const std::exception&)
		{
			try
			{
				FileRecorder.open(name);
			}
			catch (const std::exception&)
			{
				std::cout << "Access error" << std::endl;
				continue;
			}

		}
		break;

	}
	std::vector<std::vector<int>> matrixColums = sortsMatrices[0]->GetMatrixColums();
	std::vector<std::vector<int>> matrixLines = sortsMatrices[0] ->GetMatrixLines();

	FileRecorder<< std::string(15,' ') << "Comparison" << "\t" << "Swap" << std::endl;
	for (int i = 0; i < sortsCase.size(); i++)
	{
		std::string temp_name = typeid(*sortsCase[i]).name();
		temp_name.erase(0, 6);
		FileRecorder << temp_name << std::string(15 - temp_name.size(),' ') << sortsCase[i]->GetComprasionCounter() << "\t\t\t" << sortsCase[i]->GetSwapCountrt() << std::endl;;
	}
	FileRecorder << "\nSorted even colums" << std::endl;
	for (int i = 0; i < sortsMatrices[0]->GetNumberOflines(); i++)
	{
		for (int j = 0; j < sortsMatrices[0]->GEtNumberOfColums(); j++)
		{
			FileRecorder << matrixColums[i][j] << "\t";
		}
		FileRecorder << std::endl;
	}

	FileRecorder << "Sorted odd lines" << std::endl;
	for (int i = 0; i < sortsMatrices[0]->GetNumberOflines(); i++)
	{
		for (int j = 0; j < sortsMatrices[0]->GEtNumberOfColums(); j++)
		{
			FileRecorder << matrixColums[i][j] << "\t";
		}
		FileRecorder << std::endl;
	}
		
	FileRecorder.close();
}
