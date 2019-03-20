#include "Tree.hpp"

using namespace std;

Node::Node(int val)
{
    parent = NULL;
    left = NULL;
    right = NULL;
    value = val;
}

ariel::Tree::Tree()
{
    numOfNodes = 0;
    rootNode = NULL;
}

Node *ariel::Tree::search(int num)
{
    return SearchHelper(num, rootNode);
}
// Binary search
Node *ariel::Tree::SearchHelper(int num, Node *curr)
{
    if (curr == NULL || curr->value == num)
    {
        return curr;
    }
    if (num > curr->value)
    {
        SearchHelper(num, curr->right);
    }
    else
    {
        SearchHelper(num, curr->left);
    }
    // Will never reach this return
    return NULL;
}

bool ariel::Tree::insert(int num)
{
    Node *toAdd = new Node(num);
    // First pointer to keep track of where to insert the number
    Node *positionPointer = rootNode;
    // If the tree is empty add to the head of the tree
    if (positionPointer == NULL)
    {
        rootNode = toAdd;
        return true;
    }
    // second pointer to keep track of the parent
    Node *parentPointer = NULL;

    while (positionPointer != NULL)
    {
        parentPointer = positionPointer;
        if (num < positionPointer->value)
        {
            positionPointer = positionPointer->left;
            // Add to the left if its null
            if (positionPointer == NULL)
            {
                parentPointer->left = toAdd;
                numOfNodes++;
            }
        }
        else if (num > positionPointer->value)
        {
            positionPointer = positionPointer->right;
            // Add to the right if its null
            if (positionPointer == NULL)
            {
                parentPointer->right = toAdd;
                numOfNodes++;
            }
        }
        // If the number is already in the tree throw an exception
        else
        {
            throw "The number is already in the tree";
            return false;
        }
    }
    // Return true if the addition was successful
    return true;
}

bool ariel::Tree::remove(int num)
{
    Node *del = search(num);
    if (del == NULL)
    {
        //ERROR NO NODE FOUND
        throw "No such number to remove";
    }
    if (del->left == NULL && del->right == NULL)
    { //if its a leaf
        if (del->value < del->parent->value)
        { //left child
            del->parent->left = NULL;
            delete del;
        }
        else
        {
            del->parent->right = NULL; //right child
            delete del;
        }
    }
    else if (del->left == NULL || del->right == NULL)
    { //if it has 1 child
        if (del->parent->right == del)
        { //del is right child
            del->parent->right = NULL;
            delete del;
        }
        else
        { //del is left child
            del->parent->left = NULL;
            delete del;
        }
    }
    else
    { //2 children
        Node *temp = del->right;
        while (temp->left != NULL)
        {
            del = temp;
            temp = temp->left;
        }

        del->value = temp->value;
        temp->parent->left = NULL;
        delete temp;
    }
}

int ariel::Tree::size()
{
    return numOfNodes;
}

bool ariel::Tree::contains(int num)
{
    Node *temp = search(num);
    if (temp == NULL)
    {
        return false;
    }
    return true;
}

int ariel::Tree::root()
{
    return rootNode->value;
}

int ariel::Tree::parent(int num)
{
    Node *temp = search(num);
    if (temp == NULL)
    {
        throw "The number isn't in the tree";
    }
    return temp->parent->value;
}

int ariel::Tree::left(int num)
{
    Node *temp = search(num);
    if (temp == NULL)
    {
        throw "The number isn't in the tree";
    }
    return temp->left->value;
}

int ariel::Tree::right(int num)
{
    Node *temp = search(num);
    if (temp == NULL)
    {
        throw "The number isn't in the tree";
    }
    return temp->right->value;
}

void ariel::Tree::print()
{
    inOrder(rootNode);
}

void ariel::Tree::inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->value << ",";
    inOrder(root->right);
}