#pragma once
#ifndef COLORS
#define COLORS 1
const int RED = 0;
const int BLACK = 1;
const int EMPTY = -1;
#endif

class RBnode{
	private:
		RBnode* parent;
		RBnode* leftChild;
		RBnode* rightChild;
		int key;
		int Color;
	public:
		RBnode();
		RBnode(int);
		RBnode(RBnode*, RBnode*, RBnode*, int, int);
		void setParent(RBnode*);
		void setLeftChild(RBnode*);
		void setRightChild(RBnode*);
		void setColor(int);
		RBnode* getParent();
		RBnode* getLeftChild();
		RBnode* getRightChild();
		int getKey();
		int getColor();
		void print();
};