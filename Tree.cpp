#include "Tree.hpp"
using namespace std;

Tree::Node::Node(int val)
{
    parent = NULL;
    left = NULL;
    right = NULL;
    value = val;
};

ariel::Tree::Tree()
{
    numOfNodes = 0;
    rootNode = NULL;
}

Node *ariel::Tree::search(int num)
{
    SearchHelper(num, rootNode);
}

Node *ariel::Tree::SearchHelper(int num, Node *curr)
{
    if (curr == NULL || curr->value == num)
    {
        return curr;
    }
    else if (num > curr->value)
    {
        SearchHelper(num, curr->right);
    }
    else
    {
        SearchHelper(num, curr->left);
    }
}
bool ariel::Tree::insert(int num)
{
    Node *toAdd = new Node(num);

    Node *firstPointer = rootNode;

    if (firstPointer == NULL)
    {
        rootNode = toAdd;
        return true;
    }

    Node *secondPointer = NULL;

    while (firstPointer != NULL)
    {
        secondPointer = firstPointer;
        if (num < firstPointer->value)
            firstPointer = firstPointer->left;
        if (firstPointer == NULL)
        {
            secondPointer->left = toAdd;
        }
        else
            firstPointer = firstPointer->right;
        if (firstPointer == NULL)
        {
            secondPointer->right = toAdd;
        }
    }
    return true;
}
bool ariel::Tree::remove(int num)
{
    // Case 0: not found
    Node *temp = search(num) if (temp == NULL)
    {
        std::ostringstream oss;
        oss << "The number " << num << " isn't in the tree";
        throw std::invalid_argument(oss.str());
    }
    // Case 1: leaf
    if ((temp->right == NULL) && (temp->left == NULL))
    {
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
        std::ostringstream oss;
        oss << "The number " << num << " isn't in the tree";
        throw std::invalid_argument(oss.str());
    }
    return temp->parent->value;
}
int ariel::Tree::left(int num)
{
    Node *temp = search(num);
    if (temp == NULL)
    {
        std::ostringstream oss;
        oss << "The number " << num << " isn't in the tree";
        throw std::invalid_argument(oss.str());
    }
    return temp->left->value;
}
int ariel::Tree::right(int num)
{
    Node *temp = search(num);
    if (temp == NULL)
    {
        std::ostringstream oss;
        oss << "The number " << num << " isn't in the tree";
        throw std::invalid_argument(oss.str());
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