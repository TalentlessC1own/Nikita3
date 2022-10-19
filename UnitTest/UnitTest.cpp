#include "../Nikita3/ISort.h"
#include "../Nikita3/ISort.cpp"
#include "../Nikita3/BubbleSort.h"
#include "../Nikita3/BubbleSort.cpp"
#include "../Nikita3/InsertionSort.h"
#include "../Nikita3/InsertionSort.cpp"
#include "../Nikita3/SelectionSort.h"
#include "../Nikita3/SelectionSort.cpp"
#include "../Nikita3/ShellSort.h"
#include "../Nikita3/ShellSort.cpp"
#include "../Nikita3/QuickSort.h"
#include "../Nikita3/QuickSort.cpp"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
	private:
		BubbleSort bubleSort;
		InsertionSort insertionSort;
		SelectionSort selectionSort;
		ShellSort shellSort;
		QuickSort quickSort;
		std::vector <int> result = { 1,2,3,4,5 };
		std::vector <int> start = { 5,4,1,2,3 };
	public:

		TEST_METHOD(BubleTest)
		{
			std::vector <int> temp = start;
			bubleSort.Sort(temp, static_cast<int>(temp.size()));
			Assert::IsTrue(temp == result);

		}

		TEST_METHOD(InsertionTest)
		{
			std::vector <int> temp = start;
			insertionSort.Sort(temp, static_cast<int>(temp.size()));
			Assert::IsTrue(temp == result);

		}

		TEST_METHOD(SelectionTest)
		{
			std::vector <int> temp = start;
			selectionSort.Sort(temp, static_cast<int>(temp.size()));
			Assert::IsTrue(temp == result);

		}

		TEST_METHOD(ShellTest)
		{
			std::vector <int> temp = start;
			shellSort.Sort(temp, static_cast<int>(temp.size()));
			Assert::IsTrue(temp == result);

		}

		TEST_METHOD(QuickTest)
		{
			std::vector <int> temp = start;
			quickSort.Sort(temp, static_cast<int>(temp.size()));
			Assert::IsTrue(temp == result);

		}
	};
};

