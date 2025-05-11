#include "pch.h"
#include "CppUnitTest.h"
#include "..\TreeLib\AVLTree.h"
#include "..\TreeLib\SplayTree.h"
#include "..\TreeLib\BTree.h"
#include <algorithm>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace UnitTest1
{
	//����� ��� ���-������
	TEST_CLASS(UnitTestAVL)
	{
	public:		
		// ����� � ������ ������, �������������� ��������� ��������
		TEST_METHOD(TestAVLSearch1)
		{
			srand(time(0));
			AVLTree root;
			int el = rand() % 11;
			Assert::AreEqual(0, root.search(el));
		}
		//����� � �������� ������, ������� ���� ���� � ������, �������������� ��������� ��������
		TEST_METHOD(TestAVLSearch2)
		{
			srand(time(0));
			vector<int> vec;
			while (vec.size() != 10) {
				int el = rand() % (100 - (-100) + 1) + (-100);
				bool flag = true;
				for (int j = 0; j < vec.size() && flag; j++)
					if (vec[j] == el) flag = false;
				if (flag)
					vec.push_back(el);
			}
			int j = rand() % 10;
			AVLTree root;
			for (int i = 0; i < vec.size(); i++)
				root.insertion(vec[i]);
			Assert::AreEqual(1, root.search(vec[j]));
		}
		//����� � �������� ������, �������� ����� ��� � ������, �������������� ��������� ��������
		TEST_METHOD(TestAVLSearch3)
		{
			srand(time(0));
			vector<int> vec;
			while (vec.size() != 10) {
				int el = rand() % (100 - (-100) + 1) + (-100);
				bool flag = true;
				for (int j = 0; j < vec.size() && flag; j++)
					if (vec[j] == el) flag = false;
				if (flag)
					vec.push_back(el);
			}
			int el = rand() % (300 - 200 + 1) + (200);
			AVLTree root;
			for (int i = 0; i < vec.size(); i++)
				root.insertion(vec[i]);
			Assert::AreEqual(0, root.search(el));
		}
		// ����� � ������ ������
		TEST_METHOD(TestAVLSearch4)
		{
			AVLTree root;
			Assert::AreEqual(0, root.search(5));
		}
		//����� � �������� ������, ������� ���� ���� � ������, ���������� ��������
		TEST_METHOD(TestAVLSearch5)
		{
			AVLTree root;
			root.insertion(7);
			root.insertion(11);
			root.insertion(2);
			root.insertion(5);
			root.insertion(20);
			Assert::AreEqual(1, root.search(2));
			Assert::AreEqual(1, root.search(11));
		}
		//����� � �������� ������, �������� ����� ��� � ������, ���������� ��������
		TEST_METHOD(TestAVLSearch6)
		{
			AVLTree root;
			root.insertion(2);
			root.insertion(15);
			root.insertion(3);
			root.insertion(4);
			root.insertion(12);
			Assert::AreEqual(0, root.search(0));
			Assert::AreEqual(0, root.search(21));
		}
		//������� � ������ ������, �������� � ������� ������, �������������� ��������� ��������
		TEST_METHOD(TestAVLInsert1)
		{
			srand(time(0));
			AVLTree root;
			int el = rand() % (100 - (-100) + 1) + (-100);
			root.insertion(el);
			Assert::AreEqual(1, root.search(el));
		}
		//������� � ������ ������, �������� � ������� ������, �������������� ��������� ��������
		TEST_METHOD(TestAVLInsert2)
		{
			srand(time(0));
			AVLTree root;
			vector<int> vec_tree, vec;
			int el = rand() % (100 - (-100) + 1) + (-100);
			vec.push_back(el);
			root.insertion(el);
			vec_tree = root.tree_walk(vec_tree);
			for (int i = 0; i < vec.size(); i++)
				Assert::AreEqual(vec[i], vec_tree[i]);
		}
		//������� � �������� ������, �������� � ������� ������, �������������� ��������� ��������
		TEST_METHOD(TestAVLInsert3)
		{
			srand(time(0));
			vector<int> vec_tree, vec;
			while (vec.size() != 10) {
				int el = rand() % (100 - (-100) + 1) + (-100);
				bool flag = true;
				for (int j = 0; j < vec.size() && flag; j++) {
					if (vec[j] == el) flag = false;
				}
				if (flag)
					vec.push_back(el);
			}
			int el = rand() % (300 - 200 + 1) + (200);
			AVLTree root;
			for (int i = 0; i < vec.size(); i++)
				root.insertion(vec[i]);
			root.insertion(el);
			vec.push_back(el);
			sort(vec.begin(), vec.end());
			vec_tree = root.tree_walk(vec_tree);
			for (int i = 0; i < vec.size(); i++)
				Assert::AreEqual(vec[i], vec_tree[i]);
		}
		//������� � ������ ������, �������� � ������� ������, ���������� ��������
		TEST_METHOD(TestAVLInsert4)
		{
			AVLTree root;
			vector<int> vec_tree, vec;
			vec.push_back(7);
			root.insertion(7);
			vec_tree = root.tree_walk(vec_tree);
			for (int i = 0; i < vec.size(); i++)
				Assert::AreEqual(vec[i], vec_tree[i]);
		}
		//������� � ������ ������, �������� � ������� ������, ���������� ��������
		TEST_METHOD(TestAVLInsert5)
		{
			AVLTree root;
			root.insertion(3);
			Assert::AreEqual(1, root.search(3));
		}
		//������� � �������� ������, �������� � ������� ������, ���������� ��������
		TEST_METHOD(TestAVLInsert6)
		{
			AVLTree root;
			vector<int> vec = { -8, 3, 6, 11, 17 }, vec_tree;
			root.insertion(17);
			root.insertion(-8);
			root.insertion(11);
			root.insertion(3);
			root.insertion(6);
			vec_tree = root.tree_walk(vec_tree);
			for (int i = 0; i < vec.size(); i++) {
				Assert::AreEqual(vec[i], vec_tree[i]);
			}
		}
		//�������� �� ������ � ����� ���������, �������������� ��������� ��������
		TEST_METHOD(TestAVLDelete1)
		{
			srand(time(0));
			AVLTree root;
			int el = rand() % (100 - (-100) + 1) + (-100);
			root.insertion(el);
			root.deletion(el);
			Assert::AreEqual(0, root.search(el));
		}
		//�������� �� ������� ������, �������������� ��������� ��������
		TEST_METHOD(TestAVLDelete2)
		{
			srand(time(0));
			AVLTree root;
			int el = rand() % (100 - (-100) + 1) + (-100);
			root.deletion(el);
			Assert::AreEqual(0, root.search(el));
		}
		//�������� �� ��������� ������, �������� ����� ��� � ������, �������� � ������� ������, �������������� ��������� ��������
		TEST_METHOD(TestAVLDelete3)
		{
			srand(time(0));
			vector<int> vec_tree, vec;
			while (vec.size() != 10) {
				int el = rand() % (100 - (-100) + 1) + (-100);
				bool flag = true;
				for (int j = 0; j < vec.size() && flag; j++) {
					if (vec[j] == el) flag = false;
				}
				if (flag)
					vec.push_back(el);
			}
			int el = rand() % (300 - 200 + 1) + (200);
			AVLTree root;
			for (int i = 0; i < vec.size(); i++)
				root.insertion(vec[i]);
			root.deletion(el);
			sort(vec.begin(), vec.end());
			vec_tree = root.tree_walk(vec_tree);
			for (int i = 0; i < vec.size(); i++)
				Assert::AreEqual(vec[i], vec_tree[i]);
		}
		//�������� �� ��������� ������, �������� ����� ��� � ������, �������� � ������� ������, �������������� ��������� ��������
		TEST_METHOD(TestAVLDelete4)
		{
			srand(time(0));
			vector<int> vec;
			while (vec.size() != 10) {
				int el = rand() % (100 - (-100) + 1) + (-100);
				bool flag = true;
				for (int j = 0; j < vec.size() && flag; j++) {
					if (vec[j] == el) flag = false;
				}
				if (flag)
					vec.push_back(el);
			}
			int el = rand() % (300 - 200 + 1) + (200);
			AVLTree root;
			for (int i = 0; i < vec.size(); i++)
				root.insertion(vec[i]);
			root.deletion(el);
			Assert::AreEqual(0, root.search(el));
		}
		//�������� �� ��������� ������, ������� ���� ���� � ������, �������� � ������� ������, �������������� ��������� ��������
		TEST_METHOD(TestAVLDelete5)
		{
			srand(time(0));
			vector<int> vec;
			while (vec.size() != 10) {
				int el = rand() % (100 - (-100) + 1) + (-100);
				bool flag = true;
				for (int j = 0; j < vec.size() && flag; j++) {
					if (vec[j] == el) flag = false;
				}
				if (flag)
					vec.push_back(el);
			}
			int j = rand() % 10;
			AVLTree root;
			for (int i = 0; i < vec.size(); i++)
				root.insertion(vec[i]);
			root.deletion(vec[j]);
			Assert::AreEqual(0, root.search(vec[j]));
		}
		//�������� �� ��������� ������, ������� ���� ���� � ������, �������� � ������� ������, �������������� ��������� ��������
		TEST_METHOD(TestAVLDelete6)
		{
			srand(time(0));
			vector<int> vec_tree, vec;
			while (vec.size() != 10) {
				int el = rand() % (100 - (-100) + 1) + (-100);
				bool flag = true;
				for (int j = 0; j < vec.size() && flag; j++) {
					if (vec[j] == el) flag = false;
				}
				if (flag)
					vec.push_back(el);
			}
			int j = rand() % 10;
			AVLTree root;
			for (int i = 0; i < vec.size(); i++)
				root.insertion(vec[i]);
			root.deletion(vec[j]);
			vec.erase(vec.begin() + j);
			sort(vec.begin(), vec.end());
			vec_tree = root.tree_walk(vec_tree);
			for (int i = 0; i < vec.size(); i++)
				Assert::AreEqual(vec[i], vec_tree[i]);
		}
		//�������� �� ������ � ����� ���������, ���������� ��������
		TEST_METHOD(TestAVLDelete7)
		{
			AVLTree root;
			root.insertion(4);
			root.deletion(4);
			Assert::AreEqual(0, root.search(4));
		}
		//�������� �� ������� ������, ���������� ��������
		TEST_METHOD(TestAVLDelete8)
		{
			AVLTree root;
			root.deletion(1);
			Assert::AreEqual(0, root.search(1));
		}
		//�������� �� ��������� ������, �������� ����� ��� � ������, �������� � ������� ������, ���������� ��������
		TEST_METHOD(TestAVLDelete9)
		{
			vector<int> vec = { -17, -4, 3, 8, 17 }, vec_tree;
			AVLTree root;
			root.insertion(8);
			root.insertion(-4);
			root.insertion(-17);
			root.insertion(3);
			root.insertion(17);
			root.deletion(100);
			vec_tree = root.tree_walk(vec_tree);
			for(int i=0; i<vec.size(); i++)
				Assert::AreEqual(vec[i], vec_tree[i]);
		}
		//�������� �� ��������� ������, �������� ����� ��� � ������, �������� � ������� ������, ���������� ��������
		TEST_METHOD(TestAVLDelete10)
		{
			AVLTree root;			
			root.insertion(17);
			root.insertion(28);
			root.insertion(4);
			root.insertion(1);
			root.insertion(-20);
			root.deletion(3);
			Assert::AreEqual(0, root.search(3));
		}
		//�������� �� ��������� ������, ������� ���� ���� � ������, �������� � ������� ������, ���������� ��������
		TEST_METHOD(TestAVLDelete11)
		{
			vector<int> vec = { -40, -4, 5, 19 }, vec_tree;
			AVLTree root;
			root.insertion(5);
			root.insertion(-4);
			root.insertion(0);
			root.insertion(-40);
			root.insertion(19);
			root.deletion(0);
			vec_tree = root.tree_walk(vec_tree);
			for (int i = 0; i < vec.size(); i++)
				Assert::AreEqual(vec[i], vec_tree[i]);
		}
		//�������� �� ��������� ������, ������� ���� ���� � ������, �������� � ������� ������, ���������� ��������
		TEST_METHOD(TestAVLDelete12)
		{
			AVLTree root;
			root.insertion(1);
			root.insertion(84);
			root.insertion(-100);
			root.insertion(99);
			root.insertion(5);
			root.deletion(1);
			Assert::AreEqual(0, root.search(1));
		}
		//�������� ������, �������������� ��������� ��������
		TEST_METHOD(TestAVLWalk1)
		{
			srand(time(0));
			vector<int> vec_tree, vec;
			while (vec.size() != 10) {
				int el = rand() % (100 - (-100) + 1) + (-100);
				bool flag = true;
				for (int j = 0; j < vec.size() && flag; j++) {
					if (vec[j] == el) flag = false;
				}
				if (flag)
					vec.push_back(el);
			}
			AVLTree root;
			for (int i = 0; i < vec.size(); i++)
				root.insertion(vec[i]);
			sort(vec.begin(), vec.end());
			vec_tree = root.tree_walk(vec_tree);
			for (int i = 0; i < vec.size(); i++)
				Assert::AreEqual(vec[i], vec_tree[i]);
		}
		//�������� ������, ���������� ��������
		TEST_METHOD(TestAVLWalk2)
		{
			vector<int> vec = { -30, -6, 5, 8, 44 }, vec_tree;
			AVLTree root;
			root.insertion(44);
			root.insertion(8);
			root.insertion(-6);
			root.insertion(-30);
			root.insertion(5);
			vec_tree = root.tree_walk(vec_tree);
			for (int i = 0; i < vec.size(); i++)
				Assert::AreEqual(vec[i], vec_tree[i]);
		}
	};
	//����� ��� Splay-������
	TEST_CLASS(UnitTestSplay)
	{
	public:
		// ����� � ������ ������, �������������� ��������� ��������
		TEST_METHOD(TestSplaySearch1)
		{
			srand(time(0));
			SplayTree root;
			int el = rand() % 11;
			Assert::AreEqual(0, root.search(el));
		}
		//����� � �������� ������, ������� ���� ���� � ������, �������������� ��������� ��������
		TEST_METHOD(TestSplaySearch2)
		{
			srand(time(0));
			vector<int> vec;
			while (vec.size() != 10) {
				int el = rand() % (100 - (-100) + 1) + (-100);
				bool flag = true;
				for (int j = 0; j < vec.size() && flag; j++)
					if (vec[j] == el) flag = false;
				if (flag)
					vec.push_back(el);
			}
			int j = rand() % 10;
			SplayTree root;
			for (int i = 0; i < vec.size(); i++)
				root.insertion(vec[i]);
			Assert::AreEqual(1, root.search(vec[j]));
		}
		//����� � �������� ������, �������� ����� ��� � ������, �������������� ��������� ��������
		TEST_METHOD(TestSplaySearch3)
		{
			srand(time(0));
			vector<int> vec;
			while (vec.size() != 10) {
				int el = rand() % (100 - (-100) + 1) + (-100);
				bool flag = true;
				for (int j = 0; j < vec.size() && flag; j++)
					if (vec[j] == el) flag = false;
				if (flag)
					vec.push_back(el);
			}
			int el = rand() % (300 - 200 + 1) + (200);
			SplayTree root;
			for (int i = 0; i < vec.size(); i++)
				root.insertion(vec[i]);
			Assert::AreEqual(0, root.search(el));
		}
		// ����� � ������ ������
		TEST_METHOD(TestSplaySearch4)
		{
			SplayTree root;
			Assert::AreEqual(0, root.search(5));
		}
		//����� � �������� ������, ������� ���� ���� � ������, ���������� ��������
		TEST_METHOD(TestSplaySearch5)
		{
			SplayTree root;
			root.insertion(7);
			root.insertion(11);
			root.insertion(2);
			root.insertion(5);
			root.insertion(20);
			Assert::AreEqual(1, root.search(2));
			Assert::AreEqual(1, root.search(11));
		}
		//����� � �������� ������, �������� ����� ��� � ������, ���������� ��������
		TEST_METHOD(TestSplaySearch6)
		{
			SplayTree root;
			root.insertion(2);
			root.insertion(15);
			root.insertion(3);
			root.insertion(4);
			root.insertion(12);
			Assert::AreEqual(0, root.search(0));
			Assert::AreEqual(0, root.search(21));
		}
		//������� � ������ ������, �������� � ������� ������, �������������� ��������� ��������
		TEST_METHOD(TestSplayInsert1)
		{
			srand(time(0));
			SplayTree root;
			int el = rand() % (100 - (-100) + 1) + (-100);
			root.insertion(el);
			Assert::AreEqual(1, root.search(el));
		}
		//������� � ������ ������, �������� � ������� ������, �������������� ��������� ��������
		TEST_METHOD(TestSplayInsert2)
		{
			srand(time(0));
			SplayTree root;
			vector<int> vec_tree, vec;
			int el = rand() % (100 - (-100) + 1) + (-100);
			vec.push_back(el);
			root.insertion(el);
			vec_tree = root.tree_walk(vec_tree);
			for (int i = 0; i < vec.size(); i++)
				Assert::AreEqual(vec[i], vec_tree[i]);
		}
		//������� � �������� ������, �������� � ������� ������, �������������� ��������� ��������
		TEST_METHOD(TestSplayInsert3)
		{
			srand(time(0));
			vector<int> vec_tree, vec;
			while (vec.size() != 10) {
				int el = rand() % (100 - (-100) + 1) + (-100);
				bool flag = true;
				for (int j = 0; j < vec.size() && flag; j++) {
					if (vec[j] == el) flag = false;
				}
				if (flag)
					vec.push_back(el);
			}
			int el = rand() % (300 - 200 + 1) + (200);
			SplayTree root;
			for (int i = 0; i < vec.size(); i++)
				root.insertion(vec[i]);
			root.insertion(el);
			vec.push_back(el);
			sort(vec.begin(), vec.end());
			vec_tree = root.tree_walk(vec_tree);
			for (int i = 0; i < vec.size(); i++)
				Assert::AreEqual(vec[i], vec_tree[i]);
		}
		//������� � ������ ������, �������� � ������� ������, ���������� ��������
		TEST_METHOD(TestSplayInsert4)
		{
			SplayTree root;
			vector<int> vec_tree, vec;
			vec.push_back(7);
			root.insertion(7);
			vec_tree = root.tree_walk(vec_tree);
			for (int i = 0; i < vec.size(); i++)
				Assert::AreEqual(vec[i], vec_tree[i]);
		}
		//������� � ������ ������, �������� � ������� ������, ���������� ��������
		TEST_METHOD(TestSplayInsert5)
		{
			SplayTree root;
			root.insertion(3);
			Assert::AreEqual(1, root.search(3));
		}
		//������� � �������� ������, �������� � ������� ������, ���������� ��������
		TEST_METHOD(TestSplayInsert6)
		{
			SplayTree root;
			vector<int> vec = { -8, 3, 6, 11, 17 }, vec_tree;
			root.insertion(17);
			root.insertion(-8);
			root.insertion(11);
			root.insertion(3);
			root.insertion(6);
			vec_tree = root.tree_walk(vec_tree);
			for (int i = 0; i < vec.size(); i++) {
				Assert::AreEqual(vec[i], vec_tree[i]);
			}
		}
		//�������� �� ������ � ����� ���������, �������������� ��������� ��������
		TEST_METHOD(TestSplayDelete1)
		{
			srand(time(0));
			SplayTree root;
			int el = rand() % (100 - (-100) + 1) + (-100);
			root.insertion(el);
			root.deletion(el);
			Assert::AreEqual(0, root.search(el));
		}
		//�������� �� ������� ������, �������������� ��������� ��������
		TEST_METHOD(TestSplayDelete2)
		{
			srand(time(0));
			SplayTree root;
			int el = rand() % (100 - (-100) + 1) + (-100);
			root.deletion(el);
			Assert::AreEqual(0, root.search(el));
		}
		//�������� �� ��������� ������, �������� ����� ��� � ������, �������� � ������� ������, �������������� ��������� ��������
		TEST_METHOD(TestSplayDelete3)
		{
			srand(time(0));
			vector<int> vec_tree, vec;
			while (vec.size() != 10) {
				int el = rand() % (100 - (-100) + 1) + (-100);
				bool flag = true;
				for (int j = 0; j < vec.size() && flag; j++) {
					if (vec[j] == el) flag = false;
				}
				if (flag)
					vec.push_back(el);
			}
			int el = rand() % (300 - 200 + 1) + (200);
			SplayTree root;
			for (int i = 0; i < vec.size(); i++)
				root.insertion(vec[i]);
			root.deletion(el);
			sort(vec.begin(), vec.end());
			vec_tree = root.tree_walk(vec_tree);
			for (int i = 0; i < vec.size(); i++)
				Assert::AreEqual(vec[i], vec_tree[i]);
		}
		//�������� �� ��������� ������, �������� ����� ��� � ������, �������� � ������� ������, �������������� ��������� ��������
		TEST_METHOD(TestSplayDelete4)
		{
			srand(time(0));
			vector<int> vec;
			while (vec.size() != 10) {
				int el = rand() % (100 - (-100) + 1) + (-100);
				bool flag = true;
				for (int j = 0; j < vec.size() && flag; j++) {
					if (vec[j] == el) flag = false;
				}
				if (flag)
					vec.push_back(el);
			}
			int el = rand() % (300 - 200 + 1) + (200);
			SplayTree root;
			for (int i = 0; i < vec.size(); i++)
				root.insertion(vec[i]);
			root.deletion(el);
			Assert::AreEqual(0, root.search(el));
		}
		//�������� �� ��������� ������, ������� ���� ���� � ������, �������� � ������� ������, �������������� ��������� ��������
		TEST_METHOD(TestSplayDelete5)
		{
			srand(time(0));
			vector<int> vec;
			while (vec.size() != 10) {
				int el = rand() % (100 - (-100) + 1) + (-100);
				bool flag = true;
				for (int j = 0; j < vec.size() && flag; j++) {
					if (vec[j] == el) flag = false;
				}
				if (flag)
					vec.push_back(el);
			}
			int j = rand() % 10;
			SplayTree root;
			for (int i = 0; i < vec.size(); i++)
				root.insertion(vec[i]);
			root.deletion(vec[j]);
			Assert::AreEqual(0, root.search(vec[j]));
		}
		//�������� �� ��������� ������, ������� ���� ���� � ������, �������� � ������� ������, �������������� ��������� ��������
		TEST_METHOD(TestSplayDelete6)
		{
			srand(time(0));
			vector<int> vec_tree, vec;
			while (vec.size() != 10) {
				int el = rand() % (100 - (-100) + 1) + (-100);
				bool flag = true;
				for (int j = 0; j < vec.size() && flag; j++) {
					if (vec[j] == el) flag = false;
				}
				if (flag)
					vec.push_back(el);
			}
			int j = rand() % 10;
			SplayTree root;
			for (int i = 0; i < vec.size(); i++)
				root.insertion(vec[i]);
			root.deletion(vec[j]);
			vec.erase(vec.begin() + j);
			sort(vec.begin(), vec.end());
			vec_tree = root.tree_walk(vec_tree);
			for (int i = 0; i < vec.size(); i++)
				Assert::AreEqual(vec[i], vec_tree[i]);
		}
		//�������� �� ������ � ����� ���������, ���������� ��������
		TEST_METHOD(TestSplayDelete7)
		{
			SplayTree root;
			root.insertion(4);
			root.deletion(4);
			Assert::AreEqual(0, root.search(4));
		}
		//�������� �� ������� ������, ���������� ��������
		TEST_METHOD(TestSplayDelete8)
		{
			SplayTree root;
			root.deletion(1);
			Assert::AreEqual(0, root.search(1));
		}
		//�������� �� ��������� ������, �������� ����� ��� � ������, �������� � ������� ������, ���������� ��������
		TEST_METHOD(TestSplayDelete9)
		{
			vector<int> vec = { -17, -4, 3, 8, 17 }, vec_tree;
			SplayTree root;
			root.insertion(8);
			root.insertion(-4);
			root.insertion(-17);
			root.insertion(3);
			root.insertion(17);
			root.deletion(100);
			vec_tree = root.tree_walk(vec_tree);
			for (int i = 0; i < vec.size(); i++)
				Assert::AreEqual(vec[i], vec_tree[i]);
		}
		//�������� �� ��������� ������, �������� ����� ��� � ������, �������� � ������� ������, ���������� ��������
		TEST_METHOD(TestSplayDelete10)
		{
			SplayTree root;
			root.insertion(17);
			root.insertion(28);
			root.insertion(4);
			root.insertion(1);
			root.insertion(-20);
			root.deletion(3);
			Assert::AreEqual(0, root.search(3));
		}
		//�������� �� ��������� ������, ������� ���� ���� � ������, �������� � ������� ������, ���������� ��������
		TEST_METHOD(TestSplayDelete11)
		{
			vector<int> vec = { -40, -4, 5, 19 }, vec_tree;
			SplayTree root;
			root.insertion(5);
			root.insertion(-4);
			root.insertion(0);
			root.insertion(-40);
			root.insertion(19);
			root.deletion(0);
			vec_tree = root.tree_walk(vec_tree);
			for (int i = 0; i < vec.size(); i++)
				Assert::AreEqual(vec[i], vec_tree[i]);
		}
		//�������� �� ��������� ������, ������� ���� ���� � ������, �������� � ������� ������, ���������� ��������
		TEST_METHOD(TestSplayDelete12)
		{
			SplayTree root;
			root.insertion(1);
			root.insertion(84);
			root.insertion(-100);
			root.insertion(99);
			root.insertion(5);
			root.deletion(1);
			Assert::AreEqual(0, root.search(1));
		}
		//�������� ������, �������������� ��������� ��������
		TEST_METHOD(TestSplayWalk1)
		{
			srand(time(0));
			vector<int> vec_tree, vec;
			while (vec.size() != 10) {
				int el = rand() % (100 - (-100) + 1) + (-100);
				bool flag = true;
				for (int j = 0; j < vec.size() && flag; j++) {
					if (vec[j] == el) flag = false;
				}
				if (flag)
					vec.push_back(el);
			}
			SplayTree root;
			for (int i = 0; i < vec.size(); i++)
				root.insertion(vec[i]);
			sort(vec.begin(), vec.end());
			vec_tree = root.tree_walk(vec_tree);
			for (int i = 0; i < vec.size(); i++)
				Assert::AreEqual(vec[i], vec_tree[i]);
		}
		//�������� ������, ���������� ��������
		TEST_METHOD(TestSplayWalk2)
		{
			vector<int> vec = { -30, -6, 5, 8, 44 }, vec_tree;
			SplayTree root;
			root.insertion(44);
			root.insertion(8);
			root.insertion(-6);
			root.insertion(-30);
			root.insertion(5);
			vec_tree = root.tree_walk(vec_tree);
			for (int i = 0; i < vec.size(); i++)
				Assert::AreEqual(vec[i], vec_tree[i]);
		}
	};
	//����� ��� B-������
	TEST_CLASS(UnitTestB)
	{
	public:
		// ����� � ������ ������, �������������� ��������� ��������
		TEST_METHOD(TestBSearch1)
		{
			srand(time(0));
			BTree root(2);
			int el = rand() % 11;
			Assert::AreEqual(0, root.search(el));
		}
		//����� � �������� ������, ������� ���� ���� � ������, �������������� ��������� ��������
		TEST_METHOD(TestBSearch2)
		{
			srand(time(0));
			vector<int> vec;
			while (vec.size() != 10) {
				int el = rand() % (100 - (-100) + 1) + (-100);
				bool flag = true;
				for (int j = 0; j < vec.size() && flag; j++)
					if (vec[j] == el) flag = false;
				if (flag)
					vec.push_back(el);
			}
			int j = rand() % 10;
			BTree root(2);
			for (int i = 0; i < vec.size(); i++)
				root.insertion(vec[i]);
			Assert::AreEqual(1, root.search(vec[j]));
		}
		//����� � �������� ������, �������� ����� ��� � ������, �������������� ��������� ��������
		TEST_METHOD(TestBSearch3)
		{
			srand(time(0));
			vector<int> vec;
			while (vec.size() != 10) {
				int el = rand() % (100 - (-100) + 1) + (-100);
				bool flag = true;
				for (int j = 0; j < vec.size() && flag; j++)
					if (vec[j] == el) flag = false;
				if (flag)
					vec.push_back(el);
			}
			int el = rand() % (300 - 200 + 1) + (200);
			BTree root(2);
			for (int i = 0; i < vec.size(); i++)
				root.insertion(vec[i]);
			Assert::AreEqual(0, root.search(el));
		}
		// ����� � ������ ������
		TEST_METHOD(TestBSearch4)
		{
			BTree root(2);
			Assert::AreEqual(0, root.search(5));
		}
		//����� � �������� ������, ������� ���� ���� � ������, ���������� ��������
		TEST_METHOD(TestBSearch5)
		{
			BTree root(2);
			root.insertion(7);
			root.insertion(11);
			root.insertion(2);
			root.insertion(5);
			root.insertion(20);
			Assert::AreEqual(1, root.search(2));
			Assert::AreEqual(1, root.search(11));
		}
		//����� � �������� ������, �������� ����� ��� � ������, ���������� ��������
		TEST_METHOD(TestBSearch6)
		{
			BTree root(2);
			root.insertion(2);
			root.insertion(15);
			root.insertion(3);
			root.insertion(4);
			root.insertion(12);
			Assert::AreEqual(0, root.search(0));
			Assert::AreEqual(0, root.search(21));
		}
		//������� � ������ ������, �������� � ������� ������, �������������� ��������� ��������
		TEST_METHOD(TestBInsert1)
		{
			srand(time(0));
			BTree root(2);
			int el = rand() % (100 - (-100) + 1) + (-100);
			root.insertion(el);
			Assert::AreEqual(1, root.search(el));
		}
		//������� � ������ ������, �������� � ������� ������, �������������� ��������� ��������
		TEST_METHOD(TestBInsert2)
		{
			srand(time(0));
			BTree root(2);
			vector<int> vec_tree, vec;
			int el = rand() % (100 - (-100) + 1) + (-100);
			vec.push_back(el);
			root.insertion(el);
			vec_tree = root.tree_walk(vec_tree);
			for (int i = 0; i < vec.size(); i++)
				Assert::AreEqual(vec[i], vec_tree[i]);
		}
		//������� � �������� ������, �������� � ������� ������, �������������� ��������� ��������
		TEST_METHOD(TestBInsert3)
		{
			srand(time(0));
			vector<int> vec_tree, vec;
			while (vec.size() != 10) {
				int el = rand() % (100 - (-100) + 1) + (-100);
				bool flag = true;
				for (int j = 0; j < vec.size() && flag; j++) {
					if (vec[j] == el) flag = false;
				}
				if (flag)
					vec.push_back(el);
			}
			int el = rand() % (300 - 200 + 1) + (200);
			BTree root(2);
			for (int i = 0; i < vec.size(); i++)
				root.insertion(vec[i]);
			root.insertion(el);
			vec.push_back(el);
			sort(vec.begin(), vec.end());
			vec_tree = root.tree_walk(vec_tree);
			for (int i = 0; i < vec.size(); i++)
				Assert::AreEqual(vec[i], vec_tree[i]);
		}
		//������� � ������ ������, �������� � ������� ������, ���������� ��������
		TEST_METHOD(TestBInsert4)
		{
			BTree root(2);
			vector<int> vec_tree, vec;
			vec.push_back(7);
			root.insertion(7);
			vec_tree = root.tree_walk(vec_tree);
			for (int i = 0; i < vec.size(); i++)
				Assert::AreEqual(vec[i], vec_tree[i]);
		}
		//������� � ������ ������, �������� � ������� ������, ���������� ��������
		TEST_METHOD(TestBInsert5)
		{
			BTree root(2);
			root.insertion(3);
			Assert::AreEqual(1, root.search(3));
		}
		//������� � �������� ������, �������� � ������� ������, ���������� ��������
		TEST_METHOD(TestBInsert6)
		{
			BTree root(2);
			vector<int> vec = { -8, 3, 6, 11, 17 }, vec_tree;
			root.insertion(17);
			root.insertion(-8);
			root.insertion(11);
			root.insertion(3);
			root.insertion(6);
			vec_tree = root.tree_walk(vec_tree);
			for (int i = 0; i < vec.size(); i++) {
				Assert::AreEqual(vec[i], vec_tree[i]);
			}
		}
		//�������� �� ������ � ����� ���������, �������������� ��������� ��������
		TEST_METHOD(TestBDelete1)
		{
			srand(time(0));
			BTree root(2);
			int el = rand() % (100 - (-100) + 1) + (-100);
			root.insertion(el);
			root.deletion(el);
			Assert::AreEqual(0, root.search(el));
		}
		//�������� �� ������� ������, �������������� ��������� ��������
		TEST_METHOD(TestBDelete2)
		{
			srand(time(0));
			BTree root(2);
			int el = rand() % (100 - (-100) + 1) + (-100);
			root.deletion(el);
			Assert::AreEqual(0, root.search(el));
		}
		//�������� �� ��������� ������, �������� ����� ��� � ������, �������� � ������� ������, �������������� ��������� ��������
		TEST_METHOD(TestBDelete3)
		{
			srand(time(0));
			vector<int> vec_tree, vec;
			while (vec.size() != 10) {
				int el = rand() % (100 - (-100) + 1) + (-100);
				bool flag = true;
				for (int j = 0; j < vec.size() && flag; j++) {
					if (vec[j] == el) flag = false;
				}
				if (flag)
					vec.push_back(el);
			}
			int el = rand() % (300 - 200 + 1) + (200);
			BTree root(2);
			for (int i = 0; i < vec.size(); i++)
				root.insertion(vec[i]);
			root.deletion(el);
			sort(vec.begin(), vec.end());
			vec_tree = root.tree_walk(vec_tree);
			for (int i = 0; i < vec.size(); i++)
				Assert::AreEqual(vec[i], vec_tree[i]);
		}
		//�������� �� ��������� ������, �������� ����� ��� � ������, �������� � ������� ������, �������������� ��������� ��������
		TEST_METHOD(TestBDelete4)
		{
			srand(time(0));
			vector<int> vec;
			while (vec.size() != 10) {
				int el = rand() % (100 - (-100) + 1) + (-100);
				bool flag = true;
				for (int j = 0; j < vec.size() && flag; j++) {
					if (vec[j] == el) flag = false;
				}
				if (flag)
					vec.push_back(el);
			}
			int el = rand() % (300 - 200 + 1) + (200);
			BTree root(2);
			for (int i = 0; i < vec.size(); i++)
				root.insertion(vec[i]);
			root.deletion(el);
			Assert::AreEqual(0, root.search(el));
		}
		//�������� �� ��������� ������, ������� ���� ���� � ������, �������� � ������� ������, �������������� ��������� ��������
		TEST_METHOD(TestBDelete5)
		{
			srand(time(0));
			vector<int> vec;
			while (vec.size() != 10) {
				int el = rand() % (100 - (-100) + 1) + (-100);
				bool flag = true;
				for (int j = 0; j < vec.size() && flag; j++) {
					if (vec[j] == el) flag = false;
				}
				if (flag)
					vec.push_back(el);
			}
			int j = rand() % 10;
			BTree root(2);
			for (int i = 0; i < vec.size(); i++)
				root.insertion(vec[i]);
			root.deletion(vec[j]);
			Assert::AreEqual(0, root.search(vec[j]));
		}
		//�������� �� ��������� ������, ������� ���� ���� � ������, �������� � ������� ������, �������������� ��������� ��������
		TEST_METHOD(TestBDelete6)
		{
			srand(time(0));
			vector<int> vec_tree, vec;
			while (vec.size() != 10) {
				int el = rand() % (100 - (-100) + 1) + (-100);
				bool flag = true;
				for (int j = 0; j < vec.size() && flag; j++) {
					if (vec[j] == el) flag = false;
				}
				if (flag)
					vec.push_back(el);
			}
			int j = rand() % 10;
			BTree root(2);
			for (int i = 0; i < vec.size(); i++)
				root.insertion(vec[i]);
			root.deletion(vec[j]);
			vec.erase(vec.begin() + j);
			sort(vec.begin(), vec.end());
			vec_tree = root.tree_walk(vec_tree);
			for (int i = 0; i < vec.size(); i++)
				Assert::AreEqual(vec[i], vec_tree[i]);
		}
		//�������� �� ������ � ����� ���������, ���������� ��������
		TEST_METHOD(TestBDelete7)
		{
			BTree root(2);
			root.insertion(4);
			root.deletion(4);
			Assert::AreEqual(0, root.search(4));
		}
		//�������� �� ������� ������, ���������� ��������
		TEST_METHOD(TestBDelete8)
		{
			BTree root(2);
			root.deletion(1);
			Assert::AreEqual(0, root.search(1));
		}
		//�������� �� ��������� ������, �������� ����� ��� � ������, �������� � ������� ������, ���������� ��������
		TEST_METHOD(TestBDelete9)
		{
			vector<int> vec = { -17, -4, 3, 8, 17 }, vec_tree;
			BTree root(2);
			root.insertion(8);
			root.insertion(-4);
			root.insertion(-17);
			root.insertion(3);
			root.insertion(17);
			root.deletion(100);
			vec_tree = root.tree_walk(vec_tree);
			for (int i = 0; i < vec.size(); i++)
				Assert::AreEqual(vec[i], vec_tree[i]);
		}
		//�������� �� ��������� ������, �������� ����� ��� � ������, �������� � ������� ������, ���������� ��������
		TEST_METHOD(TestBDelete10)
		{
			BTree root(2);
			root.insertion(17);
			root.insertion(28);
			root.insertion(4);
			root.insertion(1);
			root.insertion(-20);
			root.deletion(3);
			Assert::AreEqual(0, root.search(3));
		}
		//�������� �� ��������� ������, ������� ���� ���� � ������, �������� � ������� ������, ���������� ��������
		TEST_METHOD(TestBDelete11)
		{
			vector<int> vec = { -40, -4, 5, 19 }, vec_tree;
			BTree root(2);
			root.insertion(5);
			root.insertion(-4);
			root.insertion(0);
			root.insertion(-40);
			root.insertion(19);
			root.deletion(0);
			vec_tree = root.tree_walk(vec_tree);
			for (int i = 0; i < vec.size(); i++)
				Assert::AreEqual(vec[i], vec_tree[i]);
		}
		//�������� �� ��������� ������, ������� ���� ���� � ������, �������� � ������� ������, ���������� ��������
		TEST_METHOD(TestBDelete12)
		{
			BTree root(2);
			root.insertion(45);
			root.insertion(13);
			root.insertion(-8);
			root.insertion(1);
			root.insertion(10);
			root.deletion(13);
			Assert::AreEqual(0, root.search(13));
		}
		//�������� ������, �������������� ��������� ��������
		TEST_METHOD(TestBWalk1)
		{
			srand(time(0));
			vector<int> vec_tree, vec;
			while (vec.size() != 10) {
				int el = rand() % (100 - (-100) + 1) + (-100);
				bool flag = true;
				for (int j = 0; j < vec.size() && flag; j++) {
					if (vec[j] == el) flag = false;
				}
				if (flag)
					vec.push_back(el);
			}
			BTree root(2);
			for (int i = 0; i < vec.size(); i++)
				root.insertion(vec[i]);
			sort(vec.begin(), vec.end());
			vec_tree = root.tree_walk(vec_tree);
			for (int i = 0; i < vec.size(); i++)
				Assert::AreEqual(vec[i], vec_tree[i]);
		}
		//�������� ������, ���������� ��������
		TEST_METHOD(TestBWalk2)
		{
			vector<int> vec = { -30, -6, 5, 8, 44 }, vec_tree;
			BTree root(2);
			root.insertion(44);
			root.insertion(8);
			root.insertion(-6);
			root.insertion(-30);
			root.insertion(5);
			vec_tree = root.tree_walk(vec_tree);
			for (int i = 0; i < vec.size(); i++)
				Assert::AreEqual(vec[i], vec_tree[i]);
		}
	};
}
