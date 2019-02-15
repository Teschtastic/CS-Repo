#include <iostream>

#ifndef BTREE
#define BTREE

class BTree
{
    public:
	BTree();
	~BTree();
	void insert(ItemType data);
	void remove(ItemType data);
	ItemType find(ItemType data);
	void printInOrder();
    void printPreOrder();
    void printPostOrder();
	bool isEmpty();
	ItemType maxBTree();
	ItemType minBTree();

    private:
	struct BTreeNode
	{
	    ItemType appData;
	    BTreeNode *left, *right;
	};

	BTreeNode *root;
    
    void BTree::destructHelper(BTreeNode *current);
	void insertHelper(BTreeNode *current, ItemType data);
	void removeHelper(BTreeNode **current, ItemType data);
	ItemType findHelper(BTreeNode *current, ItemType data);
	void printInOrderHelper(BTreeNode *current);
    void printPreOrderHelper(BTreeNode *current);
    void printPostOrderHelper(BTreeNode *current);
	ItemType maxBTreeHelper(BTreeNode *current);
	ItemType minBTreeHelper(BTreeNode *current);
};

#endif
