#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include "../Testy_jednostkowe/Testy_jednostkowe.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			std::vector<int> array;
			array.push_back(10);
			array.push_back(9);
			array.push_back(5);
			array.push_back(8);
			float a = mediana(array);
			Microsoft::VisualStudio::CppUnitTestFramework::Assert::AreEqual(8, int(a));

		}
	
	};
}
