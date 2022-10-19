#pragma once
#include <vector>
#include<memory>
#include"ISort.h"
#include"SortedMatrix.h"

void SaveData(std::vector<std::shared_ptr<ISort>>& sorts_case, std::vector < std::shared_ptr<SortedMatrix>> sortsMatrices);


