#include "BubbleSort.h"

void BubbleSort::PrintCounters()
{
	std::cout << "Bubblesort" << std::endl;
	ISort::PrintCounters();
}

void BubbleSort::Sort(std::vector<int>& arr, int size)
{
	bool end = true;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			comparisonCounter++;
			if (abs(arr[j]) > abs(arr[j + 1]))
			{
				swapCounter++;
				std::swap(arr[j], arr[j + 1]);
				end = false;
			}

		}
		if (end)return;
	}
}
