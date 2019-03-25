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

Node *ariel::Tree::FindNextNum(int num) // Find the next number after num using number
{
    Node *curr = search(num);
    return FindNextNode(curr);
}

Node *ariel::Tree::FindNextNode(Node *curr) // Find the next number after num using current node
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
    // First pointer to keep track of where to insert the number
    Node *positionPointer = rootNode;
    // If the tree is empty add to the head of the tree
    if (positionPointer == NULL)
    {
        rootNode = new Node(num);
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
                parentPointer->left = new Node(num);
                parentPointer->left->parent = parentPointer;
                numOfNodes++;
            }
        }
        else if (num > positionPointer->value)
        {
            positionPointer = positionPointer->right;
            // Add to the right if its null
            if (positionPointer == NULL)
            {
                parentPointer->right = new Node(num);
                parentPointer->right->parent = parentPointer;
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
    // If the number doesnt exist
    if (del == NULL)
        throw "No such number to remove";
    // Node is a leaf
    if (del->left == NULL && del->right == NULL)
    {
        if (del->parent != NULL)
        {
            if (del->parent->right == del)
                del->parent->right = NULL;
            else
                del->parent->left = NULL;
        }
        // Node is root
        else
        {
            cout << "debug" << endl;
            rootNode = NULL;
        }
        delete del;
        numOfNodes--;
        return true;
    }
    // Node has one child
    else if (del->left == NULL || del->right == NULL)
    {
        Node *temp = NULL;
        if (del->left == NULL)
            temp = del->right;
        if (del->right == NULL)
            temp = del->left;

        if (del->parent != NULL)
        {
            temp->parent = del->parent;
            if (del->parent->right == del)
                del->parent->right = temp;
            else
                del->parent->left = temp;
        }
        // Node is root
        else
        {
            rootNode = temp;
            temp->parent = NULL;
        }

        delete del;
        numOfNodes--;
        return true;
    }
    else if (del->left != NULL && del->right != NULL)
    {
        // look for inorder successor
        Node *next = FindNextNode(del);
        int temp = next->value;
        // Use recursive call to delete the next node
        remove(temp);
        // Change value
        del->value = temp;
        return true;
    }
    return false;
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
    if (rootNode == NULL)
        cout << "Tree is empty";
    else
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