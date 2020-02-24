#include "pch.h"
#include "CppUnitTest.h"
#include "Game.h"
#include "BusStop.h"
#include "Door.h"
#include "Floor.h"
#include "Money.h"
#include "TuitionIncrease.h"
#include "Villain.h"
#include "Wall.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	class CTestVisitor : public CItemVisitor
	{
	public:
		virtual void VisitVillain(CVillain* villain) override { mVillains++; }

		int mVillains = 0;
	};

	TEST_CLASS(CGameTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestGameConstructor)
		{
			CGame game;
		}
		
		TEST_METHOD(TestAddItem)
		{
			CGame game;
			Assert::IsTrue(game.GetSize()== 0);
			
			auto item = std::shared_ptr<CItem>();
			
			game.AddItem(item);
			Assert::IsTrue(game.GetSize()==1);
			auto item2 = std::shared_ptr<CItem>();
			game.AddItem(item2);
			Assert::IsTrue(game.GetSize()==2);
			
			
		}

		TEST_METHOD(TestClearItems)
		{
			CGame game;
			auto item = std::shared_ptr<CItem>();
			game.AddItem(item);
			game.ClearItems();
			Assert::IsTrue(game.GetSize()==0);
			auto item2 = std::shared_ptr<CItem>();
			game.AddItem(item);
			game.AddItem(item2);
			game.ClearItems();
			Assert::IsTrue(game.GetSize()==0);
			
		}

		TEST_METHOD(TestCGameVisitor)
		{
			// Construct a city object
			CGame game;

			// Add some tiles of each time
			auto item1 = std::make_shared<CBusStop>(&game);
			auto item2 = std::make_shared<CDoor>(&game);
			auto item3 = std::make_shared<CFloor>(&game);
			auto item4 = std::make_shared<CMoney>(&game);
			auto item5 = std::make_shared<CVillain>(&game);

			game.AddItem(item1);
			game.AddItem(item2);
			game.AddItem(item3);
			game.AddItem(item4);
			game.AddItem(item5);

			CTestVisitor visitor;
			game.Accept(&visitor);
			Assert::AreEqual(1, visitor.mVillains,
				L"Visitor number of villains");
		}
	};
}