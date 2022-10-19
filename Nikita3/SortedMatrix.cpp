#include "SortedMatrix.h"

std::vector<std::vector<int>> SortedMatrix::SortColums(std::vector<std::vector<int>> matrix, std::shared_ptr<ISort> sort)
{
	std::vector<int> tempCol;
	for (int i = 1; i < numberOfColums; i += 2)
	{
		tempCol = GetColum(matrix, i, numberOfLines);
		sort -> Sort(tempCol, numberOfLines);
		SetColum(matrix, tempCol, i, numberOfLines);
	}
	return matrix;
}

std::vector<std::vector<int>> SortedMatrix::SortLines(std::vector<std::vector<int>> matrix, std::shared_ptr<ISort> sort)
{
	for (int i = 0; i < numberOfLines; i += 2)
	{
		sort -> Sort(matrix[i], numberOfColums);
	}
	return matrix;
}

int SortedMatrix::GetNumberOflines()
{
	return numberOfLines;
}

int SortedMatrix::GEtNumberOfColums()
{
	return numberOfColums;
}

std::vector<std::vector<int>> SortedMatrix::GetMatrixColums()
{
	return matrixColums;
}

std::vector<std::vector<int>> SortedMatrix::GetMatrixLines()
{
	return matrixLines;
}

void SortedMatrix::Show()
{
	
	std::cout << "Sorted Colums" << std::endl;
	for (int i = 0; i < numberOfLines; i++)
	{
		for (int j = 0; j < numberOfColums; j++)
		{
			std::cout << matrixColums[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << "\n\n" << std::endl;
	std::cout << "Sorted Lines" << std::endl;
	for (int i = 0; i < numberOfLines; i++)
	{
		for (int j = 0; j < numberOfColums; j++)
		{
			std::cout << matrixLines[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << "\n\n" << std::endl;
}
