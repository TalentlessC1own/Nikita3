#pragma once
#include <iostream>
#include <vector>
#include "ISort.h"
#include "GetColum.h"


class SortedMatrix
{
private:
	int numberOfLines;
	int numberOfColums;
	std::vector<std::vector<int>> matrixColums;
	std::vector<std::vector<int>> matrixLines;
	std::vector<std::vector<int>> SortColums(std::vector<std::vector<int>> matrix, std::shared_ptr<ISort> sort);
	
	std::vector<std::vector<int>> SortLines(std::vector<std::vector<int>> matrix, std::shared_ptr<ISort> sort);
public:
	SortedMatrix( std::vector<std::vector <int>> matrixValue,std::shared_ptr<ISort> sort)
	{
		numberOfLines = static_cast<int>(matrixValue.size());
		numberOfColums =static_cast<int>(matrixValue[0].size());
		matrixColums = SortColums(matrixValue, sort);
		matrixLines = SortLines(matrixValue, sort);
	}
	int GetNumberOflines();
	int GEtNumberOfColums();
	std::vector<std::vector<int>> GetMatrixColums();
	std::vector<std::vector<int>> GetMatrixLines();

	void Show();
};

