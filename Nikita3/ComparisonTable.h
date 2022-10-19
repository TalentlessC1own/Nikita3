#pragma once

#include <memory>
#include "Names.h"
#include "ISort.h"
#include <vector>
#include <list>
#include "Sorts.h"
#include "Matrix.h"


void ComparisonTable(std::vector<std::shared_ptr<ISort>>& sorts_case, std::vector < std::shared_ptr<Matrix>>& sorts_matrices);