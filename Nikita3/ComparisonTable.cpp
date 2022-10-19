#include "ComparisonTable.h"
#include <algorithm>

void ComparisonTable(std::vector<std::shared_ptr<ISort>>& sorts_case, std::vector < std::shared_ptr<Matrix>>& sorts_matrices)
{
	sorts_case.emplace_back(std::make_shared<QuickSort>());
	sorts_case.emplace_back(std::make_shared<SelectionSort>());
	sorts_case.emplace_back(std::make_shared<ShellSort>());
	sorts_case.emplace_back(std::make_shared<BubbleSort>());
	sorts_case.emplace_back(std::make_shared<InsertionSort>());
	
	std::cout << "\t\tComparison" << "\t" << "Swap" << std::endl;
	
	for (int i = 0; i < sorts_case.size(); i++)
	{
		

		std::vector<int> temp_diagonal_elements = sorts_matrices[i]->GetDiagonalElements();

		sorts_case[i]->Sort(temp_diagonal_elements, std::min(sorts_matrices[i]->GetNumberOflines(), sorts_matrices[i]->GetNumbersOfColums()));


		sorts_case[i]->PrintCounters();
		sorts_matrices[i]->ChangeDiagonalElements(temp_diagonal_elements);
	}
}
