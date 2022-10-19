#pragma once
#include "ISort.h"

class SelectionSort : public ISort
{
public:
	

	void PrintCounters() override;

	void Sort(std::vector<int>& arr, int size) override;


};

