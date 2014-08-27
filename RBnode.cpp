#include "RBnode.h"
#include <cstddef>
#include <stdio.h>
#include <iostream>

RBnode::RBnode()
	:parent(NULL),
	leftChild(NULL),
	rightChild(NULL),
	key(-1),
	Color(1)
{}

RBnode::RBnode(int k)
	://parent(NULL),
	//leftChild(NULL),
	//rightChild(NULL),
	key(k),
	Color(0)
{}

RBnode::RBnode(RBnode* p, RBnode* l, RBnode* r, int k, int c)
	:parent(p),
	leftChild(l),
	rightChild(r),
	key(k),
	Color(c)
{}

void RBnode::setParent(RBnode* p)
{
	parent = p;
}

void RBnode::setLeftChild(RBnode* l)
{
	leftChild = l;
}

void RBnode::setRightChild(RBnode* r)
{
	rightChild = r;
}

void RBnode::setColor(int c)
{
	Color = c;
}

RBnode* RBnode::getParent()
{
	return parent;
}

RBnode* RBnode::getLeftChild()
{
	return leftChild;
}

RBnode* RBnode::getRightChild()
{
	return rightChild;
}

int RBnode::getKey()
{
	return key;
}

int RBnode::getColor()
{
	return Color;
}

void RBnode::print()
{
	std::string c;
	if(getKey() == -1)
		return;
	else if(getColor() == RED)
		c = "R";
	else if((getColor() == BLACK))
		c = "B";
	std::cout << getKey() << "(" << c << ")" << std::endl;
}
