#include "pch.h"
#include "CppUnitTest.h"

#define UNIT_TESTING
#include "../LABA-5.4/LABA-5.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest54
{
	TEST_CLASS(UnitTest54)
	{
	public:

		TEST_METHOD(TestFactor_Diagonal)
		{
			// (k - N)/(k + N) + 1 when k == N -> 0 + 1 = 1.0
			Assert::AreEqual(1.0, f(10, 10), 1e-9);
		}

		TEST_METHOD(TestFactor_Calculation)
		{
			// (14 - 10)/(14 + 10) + 1 = 4/24 + 1 = 1.1666666667
			double expected = 1.0 * (14 - 10) / (14 + 10) + 1.0;
			Assert::AreEqual(expected, f(14, 10), 1e-9);
		}

		TEST_METHOD(TestP0_SingleElement)
		{
			// N = 19, M = 19 -> product of single factor f(19, 19) = 1.0
			Assert::AreEqual(1.0, P0(19, 19), 1e-9);
		}

		TEST_METHOD(TestP1_RecUpAscending)
		{
			// P1 must equal P0
			int N = 15, M = 19;
			double expected = P0(N, M);
			Assert::AreEqual(expected, P1(N, M, N), 1e-9);
		}

		TEST_METHOD(TestP2_RecUpDescending)
		{
			// P2 must equal P0
			int N = 15, M = 19;
			double expected = P0(N, M);
			Assert::AreEqual(expected, P2(N, M, M), 1e-9);
		}

		TEST_METHOD(TestP3_RecDownAscending)
		{
			// P3 must equal P0
			int N = 15, M = 19;
			double expected = P0(N, M);
			Assert::AreEqual(expected, P3(N, M, N, 1.0), 1e-9);
		}

		TEST_METHOD(TestP4_RecDownDescending)
		{
			// P4 must equal P0
			int N = 15, M = 19;
			double expected = P0(N, M);
			Assert::AreEqual(expected, P4(N, M, M, 1.0), 1e-9);
		}
	};
}
