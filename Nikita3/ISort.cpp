
#include "ISort.h"
#include "Names.h"

int ISort::GetComprasionCounter()
{
	return comparisonCounter;
}

int ISort::GetSwapCountrt()
{
	return swapCounter;
}

void ISort::PrintCounters()
{
	std::cout << "Comparisions" << "\t\t" << "swaps" << std::endl;
	std::cout << "\t" << comparisonCounter << "\t\t" << swapCounter << std::endl;
}


