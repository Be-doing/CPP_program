#include"RBTree.h"


void test1()
{
	BRTree<int, int> rbtree;
	rbtree.Insert(make_pair(1, 2));
	rbtree.Insert(make_pair(3, 3));
	rbtree.Insert(make_pair(2, 8));
	rbtree.Insert(make_pair(7, 6));
	rbtree.Insert(make_pair(9, 1));
	rbtree.Insert(make_pair(8, 0));

	rbtree.Inorder();
}

int main()
{
	test1();
	system("pause");
	return 0;
}