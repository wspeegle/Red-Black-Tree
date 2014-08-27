#pragma once

#include <cstddef>
#include "RBnode.h"


class RBtree
{
	private: 
		RBnode* root;
	 	RBnode* SENTINEL = new RBnode(NULL, NULL, NULL, -1, BLACK);

	public:
		RBtree();
		RBtree(RBnode*);
		RBnode* getSentinel();
		void setRoot(RBnode*);
		RBnode* getRoot();
		void RBinsert(RBtree*, RBnode*);
		void insertFixup(RBtree*, RBnode*);
		void RBdelete(RBtree*, RBnode*);
		void deleteFixup(RBtree*, RBnode*);
		void RBinorder(RBtree*);
		void inOrderRec(RBnode*);
		void RBlevelorder(RBtree*);
		void transplant(RBtree*, RBnode*, RBnode*);
		void leftRotate(RBtree*, RBnode*);
		void rightRotate(RBtree*, RBnode*);
		RBnode* treeMin(RBnode*);
};