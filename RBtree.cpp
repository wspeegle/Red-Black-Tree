#include "RBnode.h"
#include "RBtree.h"
#include <cstddef>
#include <queue>
#include <stdio.h>
#include <iostream>
#include <stddef.h>
RBtree::RBtree()
{	
        root = SENTINEL;
}

RBtree::RBtree(RBnode* n)
:root(n)
{
	n->setRightChild(getSentinel());
	n->setLeftChild(getSentinel());

}

RBnode* RBtree::getSentinel()
{
	return SENTINEL;
}

void RBtree::setRoot(RBnode* n)
{
        root = n;
	 n->setParent(SENTINEL);
}

RBnode* RBtree::getRoot()
{
        return root;
}

void RBtree::RBinsert(RBtree* t, RBnode* z)
{
        RBnode* y = SENTINEL;
        RBnode* x = getRoot();
        while(x != t->getSentinel())
        {
                y = x;
                if(z->getKey() < x->getKey())
                {
			x = x->getLeftChild();
                }
                else
                {
                        x = x->getRightChild();
                }
        }
        z->setParent(y);
        if(y == t->getSentinel())
        {
                setRoot(z);
        }
        else if(z->getKey() < y->getKey())
        {
                y->setLeftChild(z);
        }
        else
        {
                y->setRightChild(z);
        }
        z->setLeftChild(t->getSentinel());
        z->setRightChild(t->getSentinel());
        z->setColor(RED);
	 insertFixup(t,z);
}

void RBtree::insertFixup(RBtree* t, RBnode* z)
{

	while((z->getParent()->getColor())== RED)
        {
                if(z->getParent() == (z->getParent()->getParent()->getLeftChild()))
                {
                        RBnode* y = z->getParent()->getParent()->getRightChild();
                        if(y->getColor() == RED)
                        {
                                z->getParent()->setColor(BLACK);
                                y->setColor(BLACK);
                                z->getParent()->getParent()->setColor(RED);
                                z = z->getParent()->getParent();
                        }
                        else if(z == z->getParent()->getRightChild())
                        {
                                z = z->getParent();
                                leftRotate(t, z);
                        }
			   else
			   {
			   z->getParent()->setColor(BLACK);
                        
			   if(z->getParent()->getParent() != NULL  && z->getParent()->getParent() != SENTINEL)
                        {
				z->getParent()->getParent()->setColor(RED);
				rightRotate(t, z->getParent()->getParent());
			   }
			   }
			   
                }
                else 
		  {
		  if(z->getParent() == (z->getParent()->getParent()->getRightChild()))
                {
                        RBnode* y = z->getParent()->getParent()->getLeftChild();
                        if(y->getColor() == RED)
                        {
                                z->getParent()->setColor(BLACK);
                                y->setColor(BLACK);
                                y->getParent()->setColor(RED);
                                z = z->getParent()->getParent();
                        }
                        else if(z == z->getParent()->getLeftChild())
                        {
                                z = z->getParent();
                                rightRotate(t, z);
                        }
			   else{
                        z->getParent()->setColor(BLACK);
			   if(z->getParent()->getParent() !=NULL && z->getParent()->getParent() != SENTINEL)
                        {
				z->getParent()->getParent()->setColor(RED);
				leftRotate(t, z->getParent()->getParent());
			   }
			   }
                }
		  }
	 }


	 t->getRoot()->setColor(BLACK);
}

void RBtree::RBdelete(RBtree* t, RBnode* z)
{
        RBnode* y = z;
        int color = y->getColor();
	 RBnode* x = new RBnode();
        if(z->getLeftChild() == SENTINEL)
        {
                x = z->getRightChild();
                transplant(t, z, z->getRightChild());
        }
        else if(z->getRightChild() == SENTINEL)
        {
                x = z->getLeftChild();
                transplant(t, z, z->getLeftChild());
        }
        else
        {
        
                y = treeMin(z->getRightChild());
                color = y->getColor();
                x = y->getRightChild();
                
                if(y->getParent() == z)
                {
                        x->setParent(y);
                }
                else
                {
                        transplant(t, y, y->getRightChild());
                        y->setRightChild(z->getRightChild());
                        y->getRightChild()->setParent(y);
                }
                transplant(t, z, y);
		  y->setLeftChild(z->getLeftChild());
		  y->getLeftChild()->setParent(y);
		  y->setColor(z->getColor());
        }
        
        if(color == BLACK)
        {
                deleteFixup(t, x);
        }
}

void RBtree::deleteFixup(RBtree* t, RBnode* x)
{
        while( (x != t->getRoot()) && (x->getColor() == BLACK))
        {
                if(x == x->getParent()->getLeftChild())
                {
                        RBnode* w = x->getParent()->getRightChild();
                        if(w->getColor() == RED)
                        {
                                w->setColor(BLACK);
                                x->getParent()->setColor(RED);
                                leftRotate(t, x->getParent());
                                //w = x->getParent()->getRightChild();
                        }
                        if((w->getLeftChild()->getColor() == BLACK) && (w->getRightChild()->getColor() == BLACK))
                        {
                                w->setColor(RED);
                                x = x->getParent();
                        }
                        else if(w->getRightChild()->getColor() == BLACK)
                        {
                                w->getLeftChild()->setColor(BLACK);
                                w->setColor(RED);
                                rightRotate(t, w);
                                //w = x->getParent()->getRightChild();
                        }
                        
                        w->setColor(x->getParent()->getColor());
                        x->getParent()->setColor(BLACK);
                        w->getRightChild()->setColor(BLACK);
                        leftRotate(t, x->getParent());
                        x = getRoot();
                }
                else
                {
                        if(x == x->getParent()->getRightChild())
                        {
                                RBnode* w = x->getParent()->getLeftChild();
                                if(w->getColor() == RED)
                                {
                                        w->setColor(BLACK);
                                        x->getParent()->setColor(RED);
                                        rightRotate(t, x->getParent());
                                        //w = x->getParent()->getLeftChild();
                                }
                                if((w->getRightChild()->getColor() == BLACK) && (w->getLeftChild()->getColor() == BLACK))
                                {
                                        w->setColor(RED);
                                        x = x->getParent();
                                }
                                else if(w->getLeftChild()->getColor() == BLACK)
                                {
                                        w->getRightChild()->setColor(BLACK);
                                        w->setColor(RED);
                                        leftRotate(t, w);
                                       // w = x->getParent()->getLeftChild();
                                }
                                
                                w->setColor(x->getParent()->getColor());
                                x->getParent()->setColor(BLACK);
                                w->getLeftChild()->setColor(BLACK);
                                rightRotate(t, x->getParent());
                                x = getRoot();
                        }
                }
        }
        x->setColor(BLACK);
}

void RBtree::RBinorder(RBtree* t)
{
	std::cout << "Inorder: " << std::endl;
	RBnode* n = t->getRoot();
	inOrderRec(n);
}

void RBtree::inOrderRec(RBnode* n)
{
	if(n != SENTINEL)
	{
		if(n->getLeftChild() != SENTINEL)
			inOrderRec(n->getLeftChild());
		n->print();
		if(n->getRightChild() != SENTINEL)
			inOrderRec(n->getRightChild());
	}
}

void RBtree::RBlevelorder(RBtree* t)
{
	std::cout << "Level Order:" << std::endl;
	RBnode* r = t->getRoot();
	std::queue<RBnode*> q;
	q.push(r);
	while(!q.empty())
	{
		RBnode* temp = q.front();
		q.pop();
		if(temp == SENTINEL)
		{}
		temp->print();
		if(temp->getLeftChild() != SENTINEL)
			q.push(temp->getLeftChild());
		if(temp->getRightChild() != SENTINEL)
			q.push(temp->getRightChild());
	}
}

void RBtree::transplant(RBtree* t, RBnode* u, RBnode* v)
{
	if(u->getParent() == SENTINEL)
	{
		setRoot(v);
	}
	else if(u == u->getParent()->getLeftChild())
	{

		u->getParent()->setLeftChild(v);
	}
	else{
		u->getParent()->setRightChild(v);
	     }
	v->setParent(u->getParent());
}

void RBtree::leftRotate(RBtree* t, RBnode* x)
{
	RBnode* y = x->getRightChild();
	y->setParent(x->getParent());
	x->setRightChild(y->getLeftChild());
	if(y->getLeftChild() != SENTINEL)
		y->getLeftChild()->setParent(x);
	//y->setParent(x->getParent());
	if(x->getParent() == SENTINEL)
		setRoot(y);
	else if(x == x->getParent()->getLeftChild())
		x->getParent()->setLeftChild(y);
	else
		x->getParent()->setRightChild(y);
	
	x->setParent(y);
y->setLeftChild(x);
}

void RBtree::rightRotate(RBtree* t, RBnode* x)
{
	RBnode* y = x->getLeftChild();
	x->setLeftChild(y->getRightChild());
	y->setParent(x->getParent());
	if(y->getRightChild() != SENTINEL)
		y->getRightChild()->setParent(x);
	
	if(x->getParent() == SENTINEL)
		setRoot(y);
	else if(x == x->getParent()->getRightChild())
		x->getParent()->setRightChild(y);
	else
		x->getParent()->setLeftChild(y);
	
	x->setParent(y);
y->setRightChild(x);
}

RBnode* RBtree::treeMin(RBnode* x)
{
	while(x->getLeftChild() != SENTINEL)
	{
		x = x->getLeftChild();
	}
	return x;
}