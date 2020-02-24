#include "pch.h"
#include "CppUnitTest.h"
#include "Game.h"
#include "Player.h"
#include "Floor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CFloorTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(FloorCollisionTest)
		{
			CGame game;
			CPlayer player(&game);
			CFloor floor(&game);

			floor.SetX(200);
			floor.SetY(200);
			player.SetX(200);
			player.SetY(200);

			// Test true when item and player on top of each other
			bool result = floor.CollisionTest(&player);
			Assert::IsTrue(result);

			player.SetX(0);
			player.SetY(200);

			// Test false when to the right
			result = floor.CollisionTest(&player);
			Assert::IsFalse(result);

			player.SetX(400);
			player.SetY(200);

			// Test false when to the left
			result = floor.CollisionTest(&player);
			Assert::IsFalse(result);

			player.SetX(200);
			player.SetY(0);

			// Test false when above
			result = floor.CollisionTest(&player);
			Assert::IsFalse(result);

			player.SetX(200);
			player.SetY(400);

			// Test false when below
			result = floor.CollisionTest(&player);
			Assert::IsFalse(result);
		}

	};
}