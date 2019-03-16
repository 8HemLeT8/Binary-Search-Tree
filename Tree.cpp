#include "Tree.hpp"
using namespace std;

    Tree::Node::Node(int val)
    {
        parent = NULL;
        left = NULL;
        right = NULL;
        value = val;
    };

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
bool ariel::Tree::insert(int i)
{
    if (rootNode->value == NULL)
    {
        rootNode = (Node *)(malloc(sizeof(Node)));
        rootNode->value = i;
        rootNode->parent = rootNode->left = rootNode->right = NULL;
        return true;
    }
    Node *temp = rootNode;
    while (true)
    {
        if (i < temp->value)
        {
            Node *prnt = temp;
            temp = temp->left;  

            if (temp->value = NULL)
            {
                temp = (Node *)(malloc(sizeof(Node)));
                temp->parent = prnt;
                temp->left = temp->right = NULL;
                numOfNodes++;
                return true;
            }
        }
        else if (i > temp->value)
        {
            Node *prnt = temp;
            temp = temp->right;

            if (temp->value == NULL)
            {
                temp = (Node *)(malloc(sizeof(Node)));
                temp->parent = prnt;
                temp->left = temp->right = NULL;
                numOfNodes++;
                return true;
            }
        }
        else
        {
            return false;
        }
    }
}
bool ariel::Tree::remove(int num)
{   
    // Case 0: not found
    Node *temp = search(num)
    if(temp == NULL)
    {
        std::ostringstream oss;
        oss << "The number " << num << " isn't in the tree";
        throw std::invalid_argument(oss.str());
    }
    // Case 1: leaf
    if((temp->right == NULL) && (temp->left == NULL))
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