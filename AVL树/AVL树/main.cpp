#include"AVLTree.h"
#include<vector>
 void test()
 {
	     vector<int> arr = { 5,2,8,4,3,6,9,7 };
	     AVLTree<int> bt;
	     for (const auto& e : arr)
		     {
		         bt.Insert(e);
		     }
	     bt.Print();
		 system("pause");
		 //  BTnode<int>* node = bt.Find(6);
		 //  cout << node->val_ << endl;
		
		 //  bt.Erase(6);
		 //  bt.Print();
		 }
 int main()
 {
	     test();
	     return 0;
	 }