#include "pch.h"
#include "CppUnitTest.h"
#include "../Project7.2r/Source.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int** arr = new int* [2];
			arr[0] = new int[2] { 1, 2 };
			arr[1] = new int[2] { 0, 2 };

			int min_index = 0;
			FindMinElemCol(arr, 0, 2, 0, min_index);
			Assert::AreEqual(1, min_index);
		}
	};
}