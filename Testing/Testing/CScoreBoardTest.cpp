#include "pch.h"
#include "CppUnitTest.h"
#include "ScoreBoard.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CScoreBoardTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestScoreBoardConstructor)
		{
			CScoreBoard ScoreBoard;

			// Test an empty scoreboard
			Assert::IsTrue(ScoreBoard.GetClock() == L"0:00");
			Assert::IsTrue(ScoreBoard.GetTuitionUSD() == L"$0");


		}

		TEST_METHOD(TestScoreBoardUpdate)
		{
			CScoreBoard ScoreBoard;

			ScoreBoard.Update(1);

			// test the addition of 1 second
			Assert::IsTrue(ScoreBoard.GetClock() == L"0:01");

			ScoreBoard.Update(10);

			// test greater than 10 seconds format under one minute
			Assert::IsTrue(ScoreBoard.GetClock() == L"0:11");

			ScoreBoard.Update(49);

			// test minute format
			Assert::IsTrue(ScoreBoard.GetClock() == L"1:00");

			ScoreBoard.Update(10);

			// test minute formt for 10 second format
			Assert::IsTrue(ScoreBoard.GetClock() == L"1:10");

		}

	};
}