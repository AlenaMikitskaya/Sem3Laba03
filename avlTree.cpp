#include "avlTree.h"
#include <iostream>

using namespace std;

AvlTree::AvlTree():
    root(nullptr) {}

AvlTree::~AvlTree()
{
    if(root)
        deleteTree(root);
    else
        delete []root;
}

void AvlTree::deleteTree(Node* node)
{
    if(node->left)
        deleteTree(node->left);
    if(node->right)
        deleteTree(node->right);
    delete node;
}

AvlTree::AvlTree(const AvlTree &original):
    root(nullptr)
{
    root=new Node(original.root->key);
    copyOfTree(root, original.root);
}

AvlTree& AvlTree::operator=(const AvlTree &rhs)
{
	if(this!=&rhs)
	{
		deleteTree(root);
		root=new Node(rhs.root->key);
		copyOfTree(root, rhs.root);
	}
	return *this;
}

void AvlTree::copyOfTree(Node* &newTree, Node* org)
{
    if(org->left)
    {
        addKey((org->left)->key);
        copyOfTree(newTree, org->left);
    }
    if(org->right)
    {
        addKey((org->right)->key);
        copyOfTree(newTree, org->right);
    }
}

void AvlTree::outputTree(Node *node, int level)
{
    if(node)
    {
        outputTree(node->right, level+1);
        for (int i=0; i<level; i++) cout<<"   ";
        cout<<node->key<<endl;
        outputTree(node->left, level+1);
    }
}

void AvlTree::outputTree()
{
	outputTree(root, 0);
}

int AvlTree::height(Node* node)
{
    if(node)
        return node->height;
    return 0;
}

int AvlTree::balanceFactor(Node* node)
{
   return height(node->right)-height(node->left);
}

void AvlTree::fixHeight(Node* node)
{
    int hl=height(node->left);
    int hr=height(node->right);
    if(hl>hr)
        node->height=hl+1;
    node->height=hr+1;
}

AvlTree::Node* AvlTree::rotateRight(Node *node) //right turn around node
{
    Node *p;
    p=node->left;
    node->left=p->right;
    p->right=node;
    fixHeight(node);
    fixHeight(p);
    return p;
}

AvlTree::Node* AvlTree::rotateLeft(Node *node) //left turn around node
{
    Node *p;
    p=node->right;
    node->right=p->left;
    p->left=node;
    fixHeight(node);
    fixHeight(p);
    return p;
}

AvlTree::Node* AvlTree::balancing(Node *node)
{
    fixHeight(node);
    if(balanceFactor(node)==2)
    {
        if(balanceFactor(node->right)<0)
            node->right=rotateRight(node->right);
        return rotateLeft(node);
    }
    if(balanceFactor(node)==-2)
    {
        if(balanceFactor(node->left)>0)
            node->left=rotateLeft(node->left);
        return rotateRight(node);
    }
    return node;
}

AvlTree::Node* AvlTree::addKey(Node *node, int datum)
{
    if(node==nullptr)
        node=new Node(datum);
    else
    {
        if(datum<node->key)
            node->left=addKey(node->left, datum);
        else
            node->right=addKey(node->right, datum);
    }
  	return balancing(node);
}

void AvlTree::addKey(int datum)
{
    root=addKey(root, datum);
}

AvlTree::Node* AvlTree::findMin(Node* node) //search node with minimum key in the subtree
{
    if(node->left)
       return findMin(node->left);
    else
        return node;
}

AvlTree::Node* AvlTree::deleteMin(Node* node)
{
    if(node->left==0)
        return node->right;
    node->left=deleteMin(node->left);
    return balancing(node);
}

AvlTree::Node* AvlTree::deleteKey(Node* node, int datum)
{
    if(node==nullptr)
        return 0;
    if(datum<node->key)
        node->left=deleteKey(node->left, datum);
    else
        if(datum>node->key)
            node->left=deleteKey(node->left, datum);
        else
            if(datum==node->key)
            {
                Node* l=node->left;
                Node* r=node->right;
                delete node;
                if(r==nullptr)
                    return l;
                Node* minNode=findMin(r);
                minNode->right=deleteMin(r);
                minNode->left=l;
                return balancing(minNode);
            }
    return balancing(node);
}

void AvlTree::deleteKey(int datum)
{
    root=deleteKey(root, datum);
}

AvlTree::Node* AvlTree::findKey(Node* node, int datum)
{
    if(node==nullptr)
        return node;
    if(datum<node->key)
        node->left=findKey(node->left, datum);
    else
        if(datum>node->key)
            node->left=findKey(node->left, datum);
        else
            if(datum==node->key)
                return node;
}

bool AvlTree::findKey(int datum)
{
    if(findKey(root, datum))
        return true;
    else
        return false;
}

