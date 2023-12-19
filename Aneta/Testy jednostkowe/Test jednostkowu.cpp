#include "pch.h"
#include "CppUnitTest.h"
#include <algorithm>

#include "../Inżynieria oprogramowania/kalkulator.cpp";

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testjednostkowu
{
	TEST_CLASS(Testjednostkowu)
	{
	public:
		
		TEST_METHOD(TestLogarytm)
		{
			float wynik = ObliczLN(243);
			Assert::AreEqual(float(log(243)), wynik);
		}
		TEST_METHOD(TestMediana)
		{
			int tab[DLUGOSC_TABLICY] = { 1, 76,3,2,8,6,7,3,55,10 };
			float wynik1 = 6.5;
			float wynik2 = obliczMediane(tab);
			Assert::AreEqual(wynik1, wynik2);
			

		}

		TEST_METHOD(TestEksponent)
		{
			float wynik1 = obliczEksponent(2);
			float wynik2 = 7.38906;
			Assert::AreEqual(wynik1, wynik2, 1);


		}
	};
}
