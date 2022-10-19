#include "ISort.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include "ShellSort.h"
#include "SelectionSort.h"
#include "MatrixInput.h"
#include "InitialMatrixFileOutput.h"
#include "SaveData.h"


enum class Answer 
{
	Yes = 1,
	No

};


int main()
{
	int const sortsCount = 5;
	std::cout << "Nikita 415 var 4 kr 3 " << std::endl
		<< "Sort " << std::endl;
	while (true)
	{
		std::vector < std::shared_ptr<ISort>> sortsCase;
		std::vector < std::shared_ptr<SortedMatrix>> sortsMatrices;
		std::vector<std::vector<int>> matrix;

		sortsCase.emplace_back(std::make_shared<BubbleSort>());
		sortsCase.emplace_back(std::make_shared<QuickSort>());
		sortsCase.emplace_back(std::make_shared<SelectionSort>());
		sortsCase.emplace_back(std::make_shared<ShellSort>());
		sortsCase.emplace_back(std::make_shared<InsertionSort>());
		
		InputMode mode =static_cast<InputMode>( MatrixInput(matrix));

		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < matrix[0].size(); j++)
			{
				std::cout << matrix[i][j] << "\t";
			}
			std::cout << std::endl;
		}
		for (int i = 0; i < sortsCount; i++)
		{
			sortsMatrices.emplace_back(std::make_shared<SortedMatrix>(matrix, sortsCase[i]));
			sortsCase[i]->PrintCounters();
			sortsMatrices[i]->Show();
		}
		
		if (mode == InputMode::ConsoleByHand || mode == InputMode::ConsoleRandom)
		{
			std::cout << "Do you want to save the original matrix data to a file ?" << std::endl;
			std::cout << "1 - yes\n2 - no" << std::endl;
			Answer initialChoice = static_cast<Answer>(InputCheck::CheckMenu(2));
			if (initialChoice == Answer::Yes)
				InitialMatrixFileOutput(matrix);
		}
		std::cout << "Do you want to save the sort comparison table to a file ?" << std::endl;
		std::cout << "1 - yes\n2 - no" << std::endl;
		Answer dataChoice = static_cast<Answer>(InputCheck::CheckMenu(2));
		if(dataChoice == Answer::Yes)
			SaveData(sortsCase, sortsMatrices);

		std::cout << "Continue?" << std::endl;
		std::cout << "1 - yes\n2 - no" << std::endl;
		Answer continueChoice = static_cast<Answer> (InputCheck::CheckMenu(2));
		if (continueChoice ==Answer::No) return 0;		
	}
	
}