#include "Tree.hpp"

using namespace std;

Node::Node(int val) //counstructor
{
    parent = NULL;
    left = NULL;
    right = NULL;
    value = val;
}

Node::Node() //counstructor
{
    parent = NULL;
    left = NULL;
    right = NULL;
}

Node::~Node() // Deconstructor
{
    if (left)
        delete left;
    if (right)
        delete right;
}

ariel::Tree::Tree() //counstructor
{
    numOfNodes = 0;
    rootNode = NULL;
}

ariel::Tree::~Tree() // Deconstructor
{
    if (rootNode)
        delete rootNode;
}

Node *ariel::Tree::search(int num) //return the node with the *num* value
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
        return SearchHelper(num, curr->right); //research on the right child
    }
    else
    {
        return SearchHelper(num, curr->left); //research on the left child
    }
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
        numOfNodes++;
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
                toAdd->parent = parentPointer;
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
                toAdd->parent = parentPointer;
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
    if (del->parent == NULL)
    {
        delete del;
        numOfNodes--;
        return true;
    }
    if (del->left == NULL && del->right == NULL)
    {                                        //if its a leaf
        if (del->value < del->parent->value) //is del a left child
        {                                    //left child
            del->parent->left = NULL;
            delete del;
            numOfNodes--;
            return true;
        }

        else
        { //right child
            del->parent->right = NULL;
            delete del;
            numOfNodes--;
            return true;
        }
    }
    else if (del->left == NULL || del->right == NULL)
    { //if it has 1 child
        if (del->parent->right == del)
        { //del is right child
            del->parent->right = NULL;
            delete del;
            numOfNodes--;
            return true;
        }
        else
        { //del is left child
            del->parent->left = NULL;
            delete del;
            numOfNodes--;
            return true;
        }
    }
    else
    { //2 children
        Node *temp = del->right;
        while (temp->left != NULL) //find the following value
        {
            del = temp;
            temp = temp->left;
        }

        del->value = temp->value;
        temp->parent->left = NULL;
        delete temp;
        numOfNodes--;
        return true;
    }
}

int ariel::Tree::size() //return size of the tree
{
    return numOfNodes;
}

bool ariel::Tree::contains(int num) //return boolean whether the tree contains node with value num
{
    Node *temp = search(num);
    if (temp == NULL)
    {
        return false;
    }
    return true;
}

int ariel::Tree::root() //return value of the root
{
    return rootNode->value;
}

int ariel::Tree::parent(int num) //return value of the parent of num
{
    Node *temp = search(num);
    if (temp == NULL)
    {
        throw "The number isn't in the tree";
    }
    if (temp->parent == NULL)
    {
        throw "No parent";
    }
    return temp->parent->value;
}

int ariel::Tree::left(int num) //return value of the left child
{
    Node *temp = search(num);
    if (temp == NULL)
    {
        throw "The number isn't in the tree";
    }
    if (temp->left == NULL)
    {
        throw "No left child";
    }
    return temp->left->value;
}

int ariel::Tree::right(int num) //return value of the left child
{
    Node *temp = search(num);
    if (temp == NULL)
    {
        throw "The number isn't in the tree";
    }
    if (temp->right == NULL)
    {
        throw "No right child";
    }
    return temp->right->value;
}

void ariel::Tree::print() //print the tree inorder values
{
    inOrder(rootNode);
}

void ariel::Tree::inOrder(Node *root) //scan the tree from left to right and print it
{
    if (root != NULL)
    {
        if (root->left)
        {
            inOrder(root->left); //scan left
            cout << ", ";
        }

        cout << root->value; //print

        if (root->right) //print right
        {
            cout << ", ";
            inOrder(root->right);
        }
    }
}