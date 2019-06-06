#include"BSTree.h"

void test1()
{
	BTree<int> tree;
	tree.Insert(1);
	tree.Insert(5);
	tree.Insert(3);
	tree.Insert(7);
	tree.Insert(2);

	tree.Inorder();
}

void test2()
{
	BTree<int> tree;
	tree.Insert(1);
	tree.Insert(5);
	tree.Insert(3);
	tree.Insert(7);
	tree.Insert(2);
	tree.Insert(23);
	tree.Insert(11);
	tree.Insert(12);
	tree.Insert(10);
	tree.Insert(9);

	tree.Inorder();

	tree.Erase(1);
	tree.Erase(9);
	tree.Erase(23);
	tree.Erase(10);
	tree.Inorder();
}

void test3()
{
	BTree<int> tree;
	tree.Insert(1);
	tree.Insert(5);
	tree.Insert(3);
	tree.Insert(7);
	tree.Insert(2);

	tree.Inorder();


	BTree<int> tree2(tree);
	tree2.Inorder();

	tree.Insert(23);
	tree.Insert(11);
	tree.Insert(12);
	tree.Insert(10);
	tree.Insert(9);
	tree.Inorder();

	tree2 = tree;
	tree2.Inorder();
}
int main()
{
	test3();
	system("pause");
	return 0;
}