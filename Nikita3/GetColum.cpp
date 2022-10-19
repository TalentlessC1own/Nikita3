#include "GetColum.h"

std::vector<int> GetColum(std::vector<std::vector<int>> matrix, int colum, int lines)
{
	std::vector<int> tempColum;
	for (int i = 0; i < lines; i++)
	{
		tempColum.push_back(matrix[i][colum]);
	}
	return tempColum;
}

void SetColum(std::vector<std::vector<int>>& matrix, std::vector<int> colum, int columNumber, int lines)
{
	for (int i = 0; i < lines; i++)
	{
		matrix[i][columNumber] = colum[i];
	}
}
