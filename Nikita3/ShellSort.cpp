#include "ShellSort.h"

void ShellSort::PrintCounters()
{
    std::cout << "Shellsort" << std::endl;
    ISort::PrintCounters();
}

void ShellSort::Sort(std::vector<int>& arr, int size)
{
    for (int gap = size/2; gap > 0; gap/=2)
        for (int i = gap; i < size; i++)
        {
            int temp = arr[i];
            int j;
            comparisonCounter++;
            for (j = i; j >= gap && abs(arr[j - gap]) > abs(temp); j -= gap)
            {
                swapCounter++;
                arr[j] = arr[j - gap];
                if (j == gap)
                    comparisonCounter--;
            }

            arr[j] = temp;
        } 
}
