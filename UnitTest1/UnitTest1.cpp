#include "pch.h"
#include "CppUnitTest.h"
#include "..\\Lab11\Hash.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Hash test(3);
			Node* node1 = test.addItem();
			Node* node2 = test.addItem();
			Node* node3 = test.addItem();
			Node* node4 = test.addItem();

			Assert::IsNotNull(node1);
			Assert::IsNotNull(node2);
			Assert::IsNotNull(node3);
			Assert::IsNull(node4);
		}

		TEST_METHOD(TestMethod2)
		{
			Hash test;
			Node* node1 = test.addItem();
			Node* node2 = test.addItem();
			Node* node3 = test.addItem();
			Node* node4 = test.addItem();

			Assert::IsNotNull(node1);
			Assert::IsNotNull(node2);
			Assert::IsNotNull(node3);
			Assert::IsNotNull(node4);
		}

		TEST_METHOD(TestMethod3)
		{
			Hash test(4);
			Node* node1 = test.addItem();
			Node* node2 = test.addItem();
			Node* node3 = test.addItem();
			Node* node4 = test.addItem();

			Assert::IsNotNull(test.removeItem(0));
			Assert::IsNotNull(test.removeItem(1));
			Assert::IsNotNull(test.removeItem(2));
			Assert::IsNotNull(test.removeItem(3));
		}

		TEST_METHOD(TestMethod4)
		{
			Hash test;
			Node* node1 = test.addItem();
			Node* node2 = test.addItem();
			Node* node3 = test.addItem();
			Node* node4 = test.addItem();

			int index1 = node1->key % 100;
			int index2 = node2->key % 100;
			int index3 = node3->key % 100;
			int index4 = node4->key % 100;

			Assert::IsNotNull(test.removeItem(index1));
			Assert::IsNotNull(test.removeItem(index2));
			Assert::IsNotNull(test.removeItem(index3));
			Assert::IsNotNull(test.removeItem(index4));
		}

		TEST_METHOD(TestMethod5)
		{
			Hash test(4);
			Node* node1 = test.addItem();
			Node* node2 = test.addItem();
			Node* node3 = test.addItem();
			Node* node4 = test.addItem();

			Assert::IsNotNull(test.getItem(0));
			Assert::IsNotNull(test.getItem(1));
			Assert::IsNotNull(test.getItem(2));
			Assert::IsNotNull(test.getItem(3));
		}

		TEST_METHOD(TestMethod6)
		{
			Hash test;
			Node* node1 = test.addItem();
			Node* node2 = test.addItem();
			Node* node3 = test.addItem();
			Node* node4 = test.addItem();

			int index1 = node1->key % 100;
			int index2 = node2->key % 100;
			int index3 = node3->key % 100;
			int index4 = node4->key % 100;

			Assert::IsNotNull(test.getItem(index1));
			Assert::IsNotNull(test.getItem(index2));
			Assert::IsNotNull(test.getItem(index3));
			Assert::IsNotNull(test.getItem(index4));
		}

		TEST_METHOD(TestMethod7)
		{
			Hash test(4);
			Node* node1 = test.addItem();
			Node* node2 = test.addItem();
			Node* node3 = test.addItem();
			Node* node4 = test.addItem();
			Assert::AreEqual(test.getLength(), 4);

			test.removeItem(1);
			test.removeItem(3);
			Assert::AreEqual(test.getLength(), 2);

		}

		TEST_METHOD(TestMethod8)
		{
			Hash test;
			Assert::AreEqual(test.getLength(), 0);

			Node* node1 = test.addItem();
			Node* node2 = test.addItem();
			Node* node3 = test.addItem();
			Assert::AreEqual(test.getLength(), 3);

			int index = node1->key % 100;
			test.removeItem(index);
			Assert::AreEqual(test.getLength(), 2);
		}
	};
}
