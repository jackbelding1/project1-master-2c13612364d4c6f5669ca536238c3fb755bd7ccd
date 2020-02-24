#include "pch.h"
#include "CppUnitTest.h"
#include "Game.h"
#include "Player.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

/// initialX for player
double initialX = 200;
/// initialY for player
double initialY = 200;

namespace Testing
{
	TEST_CLASS(CPlayerTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestPlayerConstructor)
		{
			CGame game;
			CPlayer player(&game);
			//Assert player is at starting position from constructor
			// "<" necessary for testing doubles
			Assert::IsTrue(player.GetX() - initialX < 0.0001);
			Assert::IsTrue(player.GetY() - initialY < 0.0001);
		}

		TEST_METHOD(TestPlayerVelocity)
		{
			CGame game;
			CPlayer player(&game);
			//Assert player starting with initial velocity
			// "<" necessary for testing doubles
			Assert::IsTrue(player.GetVelocityX() < 0.0001);
			Assert::IsTrue(player.GetVelocityY() < 0.0001);
		}

	};
}