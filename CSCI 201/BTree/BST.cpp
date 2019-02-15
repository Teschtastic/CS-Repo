/*
 Sean Tesch   CSCI 201    Assignment #7
 Due: Monday, November 16, 2015 @ Midnight
 
 To compile, write in the command line:
 g++ -o BTree dictionary.cpp BST.cpp ItemType.cpp
 
 To run, write in the command line:
 ./BTree
 */

#include <iostream>
#include "ItemType.h"
#include "BST.h"

BTree::BTree()
{
    // Done
    root = NULL;
}

BTree::~BTree()
{
    // Done
    if (!isEmpty())
	destructHelper(root);
    root = NULL;
}

void BTree::insert(ItemType data)
{
    // Done
    
    // If the tree is empty?
    if (isEmpty())
    {
    //     Allocate a new node into root
        root = new(BTreeNode);
    //     Copy insertion data into the new node
        root -> appData = data;
    //     Make sure the pointers (left and right) are NULL
        root -> left = NULL;
        root -> right = NULL;
    }
    // Else
    else
    {
    //     Call the insert helper with the root of the tree
    //         and the insertion data
        insertHelper(root, data);
    }
}

void BTree::remove(ItemType data)
{
    // Done
    removeHelper(&root, data);
}

ItemType BTree::find(ItemType data)
{
    // Done
    return (findHelper(root, data));
}

void BTree::printInOrder()
{
    // Done
    cout << "The Binary Search Tree contains (inorder):\n";
    printInOrderHelper(root);
    cout << endl;
}

void BTree::printPreOrder()
{
    // Done
    cout << "The Binary Search Tree contains (preorder):\n";
    printPreOrderHelper(root);
    cout << endl;
}

void BTree::printPostOrder()
{
    // Done
    cout << "The Binary Search Tree contains (postorder):\n";
    printPostOrderHelper(root);
    cout << endl;
}


bool BTree::isEmpty()
{
    // Done
    return(root == NULL);
}

ItemType BTree::maxBTree()
{
    // Done
    ItemType max;
    
    if (!isEmpty())
    {
        return maxBTreeHelper(root);
    }
    else
    {
        cout << "ERROR: In maxBTree there is no tree (nor spoon)\n";
        return max;
    }
}

ItemType BTree::minBTree()
{
    // Done
    ItemType min;

    if (!isEmpty())
    {
	return minBTreeHelper(root);
    }
    else
    {
	cout << "ERROR: In minBTree there is no tree (nor spoon)\n";
	return min;
    }
}

void BTree::destructHelper(BTreeNode *current)
{
    // Done
    ItemType dummy;

    if (current->left != NULL)
    {
	destructHelper(current->left);
	current->left = NULL;
    }
    if (current->right != NULL)
    {
	destructHelper(current->right);
	current->right = NULL;
    }
    current->appData = dummy;		// Clear out sensitive data

    delete(current);

    return;
}

void BTree::insertHelper(BTreeNode *current, ItemType data)
{
    // Done
    
    // If the insert data equals the data in current, bail
    //    out with an error
    if (data == current -> appData)
    {
        cout << "ERROR: Data has been inserted already." << endl;
    }
    
    // Is our insert data less than the data in current?
    if (data < current -> appData)
    {
        //    Is the left of current NULL?
        if (current -> left == NULL)
        {
            // Allocate a new node into current's left
            current -> left = new (BTreeNode);
            // Copy data into new node
            current -> left -> appData = data;
            // NULL the left and right pointers of the new node
        }
        
        else
        {
            //    Else recurse to the left
            insertHelper(current -> left, data);
        }
    }
    
    if (data > current -> appData)
    {
        // We must go right...
        //    Can we go right (i.e. right is NULL)?
        if (current -> right == NULL)
        {
            //        Allocate a new node into current's right
            current -> right = new (BTreeNode);
            //        Copy data into new node
            current -> right -> appData = data;
            //        NULL the left and right pointers of the new node
        }
        
        else
        {
            // Else recurse right
            insertHelper(current -> right, data);
        }
        
    }
 
    return;
}

void BTree::removeHelper(BTreeNode **current, ItemType data)
{
    // Done
    
    /* - Temp variable - */
    BTreeNode *tempNode;
    
    /* - Empty tree - */
    if (*current == NULL)
    {
        /* - Error output - */
        cout << "ERROR: There is no data to remove. \n";
    }
    else if ((*current) -> appData == data)
    {
        /* - Empty node - */
        if ((*current) -> left == NULL && (*current) -> right == NULL)
        {
            // cout << "Deleting leaf node\n";
            // ^^^ Used for testing
            tempNode = *current;
            *current = NULL;
            delete(tempNode);
        }
        /* - One child - */
        else if(((*current) -> left != NULL && (*current) -> right == NULL) || ((*current) -> left == NULL && (*current) -> right != NULL))
        {
            /* - left tree, no right - */
            if ((*current) -> right == NULL)
            {
                // cout << "deleting one child on left\n";
                // ^^^ Used for testing
                tempNode = (*current);
                *current = (*current) -> left;
                delete tempNode;
            }
            /* - right tree, no left - */
            else
            {
                // cout << "deleting one child on right\n";
                // ^^^ Used for testing
                tempNode = (*current);
                *current = (*current) -> right;
                delete tempNode;
            }
        }
        /* - Two children - */
        else
        {
            // cout << "deleting two child\n";
            // ^^^ Used for testing
            tempNode = (*current) -> left;
            while (tempNode -> right != NULL)
                tempNode = tempNode -> right;
            tempNode -> right = (*current) -> right;
            tempNode = (*current);
            (*current) = (*current) -> left;
            delete(tempNode);
        }
    }
    else if (data < (*current) -> appData)
        removeHelper(&(*current) -> left, data);
    else
        removeHelper(&(*current) -> right, data);
}

ItemType BTree::findHelper(BTreeNode *current, ItemType data)
{
    // Done
    if (current == NULL)
    {
        return data;
    }
    else if (current -> appData == data)
    {
        return (current -> appData);
    }
    else if (data < current -> appData)
    {
        return (findHelper(current -> left, data));
    }
    else
        return (findHelper(current -> right, data));
}

void BTree::printInOrderHelper(BTreeNode *current)
{
    // Done
    if (current != NULL)
    {
	printInOrderHelper(current->left);
	cout << "\t" << current->appData << endl;
	printInOrderHelper(current->right);
    }

    return;
}

void BTree::printPreOrderHelper(BTreeNode *current)
{
    // Done
    if (current != NULL)
    {
        cout << "\t" << current -> appData << endl;
        printPreOrderHelper(current -> left);
        printPreOrderHelper(current -> right);
    }
    
    return;
}

void BTree::printPostOrderHelper(BTreeNode *current)
{
    // Done
    if (current != NULL)
    {
        printPostOrderHelper(current -> left);
        printPostOrderHelper(current -> right);
        cout << "\t" << current -> appData << endl;
    }
    
    return;
}

ItemType BTree::maxBTreeHelper(BTreeNode *current)
{
    // Done
    if (current -> right == NULL)
    {
        return current -> appData;
    }
    else
        return(maxBTreeHelper(current -> right));
    
}

ItemType BTree::minBTreeHelper(BTreeNode *current)
{
    // Done
    if (current -> left == NULL)
    {
        return current -> appData;
    }
    else
        return(minBTreeHelper(current -> left));
}
