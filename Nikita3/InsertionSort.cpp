#include "InsertionSort.h"

void InsertionSort::PrintCounters()
{
	std::cout << "Insertionsort" << std::endl;
	ISort::PrintCounters();
}

void InsertionSort::Sort(std::vector<int>& arr, int size)
{
    for (int k = 1; k < size; k++)
    {
       
        int temp = arr[k];
        int j = k - 1;
        comparisonCounter++;
        while (j >= 0 && abs(temp) < abs(arr[j]))
        {
            comparisonCounter++;
            swapCounter++;
            arr[j + 1] = arr[j];
            j --;
            if(j==0)
                comparisonCounter--;

        }
       arr[j + 1] = temp;
    }
}
