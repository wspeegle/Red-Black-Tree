#include "RBnode.h"
#include "RBtree.h"
#include <stdio.h>
#include <iostream>

int main()
{
	RBtree* TREE = new RBtree();
	int keys[] {50, 25, 14, 9, 5, 2, 11, 19, 17, 31, 28, 35, 30, 80, 55, 52, 68, 65, 79, 90};
	for(int i = 0; i < 20; i++)
	{
		RBnode* temp = new RBnode(keys[i]);
		TREE->RBinsert(TREE, temp);
		temp->print();
	}
	TREE->RBlevelorder(TREE);
	TREE->RBinorder(TREE);
	RBnode* test = TREE->getRoot()->getRightChild()->getRightChild();
	std::cout << "deleting ";
	test->print();
	TREE->RBdelete(TREE, test);
	TREE->RBlevelorder(TREE);
}