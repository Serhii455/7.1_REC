#include "pch.h"
#include "CppUnitTest.h"
#include "../Pr_7.1_REC/7.1_REC.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            int rowCount = 3;
            int colCount = 3;
            int** Z = new int* [rowCount];
            for (int i = 0; i < rowCount; i++)
                Z[i] = new int[colCount];


            Z[0][0] = 1; Z[0][1] = 2; Z[0][2] = 3;
            Z[1][0] = 4; Z[1][1] = 5; Z[1][2] = 6;
            Z[2][0] = 7; Z[2][1] = 8; Z[2][2] = 9;


            int g = Sum(Z, rowCount, colCount);


            for (int i = 0; i < rowCount; i++)
                delete[] Z[i];
            delete[] Z;

            Assert::AreEqual(g, 0);

		}
	};
}
