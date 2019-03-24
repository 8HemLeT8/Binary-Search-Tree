#include "Tree.hpp"

using namespace std;

Node::Node(int val) // Counstructor with value
{
    parent = NULL;
    left = NULL;
    right = NULL;
    value = val;
}

Node::Node() // Empty counstructor
{
    parent = NULL;
    left = NULL;
    right = NULL;
}

ariel::Tree::Tree() // Tree counstructor
{
    numOfNodes = 0;
    rootNode = NULL;
}

void ariel::Tree::DestroyTree(Node *curr) // Destroy all subtrees of current node
{
    if (curr)
    {
        DestroyTree(curr->left);
        DestroyTree(curr->right);
        delete curr;
    }
}

ariel::Tree::~Tree() // Deconstructor for tree
{
    DestroyTree(rootNode);
}

Node *ariel::Tree::search(int num) // Return the node with the num value
{
    return SearchHelper(num, rootNode);
}

Node *ariel::Tree::SearchHelper(int num, Node *curr) // Binary tree
{
    if (curr == NULL || curr->value == num)
    {
        return curr;
    }
    if (num > curr->value)
    {
        return SearchHelper(num, curr->right); //research on the right sub-tree
    }
    else
    {
        return SearchHelper(num, curr->left); //research on the left sub-trr
    }
}

Node *ariel::Tree::FindNext(int num) // Find the next number after num using number
{
    Node *curr = search(num);
    return FindNext(curr);
}

Node *ariel::Tree::FindNext(Node *curr) // Find the next number after num using current node
{
    Node *next = curr->right;
    while (next->left != NULL)
    {
        next = next->left;
    }
    return next;
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

void ariel::Tree::print() const //print the tree inorder values
{
    cout << endl;
    inOrder(rootNode);
    cout << endl;
}

void ariel::Tree::inOrder(Node *root) const // Print each subtree seperated by a comma
{
    if (root != NULL)
    {
        if (root->left)
        {
            inOrder(root->left); // Left subtree
            cout << ", ";
        }

        cout << root->value; // Print the value

        if (root->right)
        {
            cout << ", ";
            inOrder(root->right); // Right subtree
        }
    }
}