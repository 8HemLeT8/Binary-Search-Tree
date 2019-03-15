#include "Tree.hpp"
using namespace std;

    node *Tree::search(int num)
    {
        SearchHelper(num, rootNode);
    }

    node *Tree::SearchHelper(int num, node *curr)
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
    bool Tree::insert(int i)
    {
        if (rootNode->value == NULL)
        {
            rootNode = (node *)(malloc(sizeof(node)));
            rootNode->value = i;
            rootNode->parent = rootNode->left = rootNode->right = NULL;
            return true;
        }
        node *temp = rootNode;
        while (true)
        {
            if (i < temp->value)
            {
                node *prnt = temp;
                temp = temp->left;

                if (temp->value = NULL)
                {
                    temp = (node *)(malloc(sizeof(node)));
                    temp->parent = prnt;
                    temp->left = temp->right = NULL;
                    numOfNodes++;
                    return true;
                }
            }
            else if (i > temp->value)
            {
                node *prnt = temp;
                temp = temp->right;

                if (temp->value == NULL)
                {
                    temp = (node *)(malloc(sizeof(node)));
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
    bool Tree::remove(int num)
    {
        // Case 1
    }
    int Tree::size()
    {
        return numOfNodes;
    }
    bool Tree::contains(int num)
    {
        node *temp = search(num);
        if (temp == NULL)
        {
            return false;
        }
        return true;
    }
    int Tree::root()
    {
        return rootNode->value;
    }
    int Tree::parent(int num)
    {
        node *temp = search(num);
        if (temp == NULL)
        {
            std::ostringstream oss;
            oss << "The number " << num << " isn't in the tree";
            throw std::invalid_argument(oss.str());
        }
        return temp->parent->value;
    }
    int Tree::left(int num)
    {
        node *temp = search(num);
        if (temp == NULL)
        {
            std::ostringstream oss;
            oss << "The number " << num << " isn't in the tree";
            throw std::invalid_argument(oss.str());
        }
        return temp->left->value;
    }
    int Tree::right(int num)
    {
        node *temp = search(num);
        if (temp == NULL)
        {
            std::ostringstream oss;
            oss << "The number " << num << " isn't in the tree";
            throw std::invalid_argument(oss.str());
        }
        return temp->right->value;
    }
    void Tree::print()
    {
        inOrder(rootNode);
    }
    void Tree::inOrder(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        inOrder(root->left);
        cout << root->value << ",";
        inOrder(root->right);
    }