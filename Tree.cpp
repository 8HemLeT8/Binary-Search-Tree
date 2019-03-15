#include <cstdio>
<<<<<<< HEAD
#include <stdexcept>
#include <sstream>

struct node
=======
#include<stdlib.h> 

struct node 
>>>>>>> 01992ebdd12829653a8ed2aead83e2e857265cbe
{
    int value;
    node *parent;
    node *left;
    node *right;
};

class Tree
{
  private:
    node *rootNode;
    int numOfNodes;

    node *search(int num)
    {
        SearchHelper(num, rootNode);
    }

    node *SearchHelper(int num, node *curr)
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

<<<<<<< HEAD
  public:
    bool insert(int i)
    {
        if (rootNode.value == NULL)
        {
            rootNode.value = i;
            return true;
        }
        node *temp = &rootNode;
        node *troot = &rootNode;
        while (true)
        {
            if (i < temp->value)
            {
                node *prnt = temp;
                temp = temp->left;

                if (temp->value = NULL)
                {
                    temp->value = i;
                    temp->parent = prnt;
=======
    public:
   
    bool insert(int i){
        if(rootNode->value == NULL){
            rootNode=(node*)(malloc(sizeof(node)));
            rootNode->value=i;
            rootNode->parent=rootNode->left=rootNode->right=NULL;
            return true;
        }
        node *temp=rootNode;
        while (true){ 
            if(i<temp->value){
                node* prnt =temp;
                temp = temp->left;
                
                if(temp->value=NULL){
                    temp=(node*)(malloc(sizeof(node)));
                    temp->parent=prnt;
                    temp->left=temp->right=NULL;
>>>>>>> 01992ebdd12829653a8ed2aead83e2e857265cbe
                    numOfNodes++;
                    return true;
                }
            }
            else if (i > temp->value)
            {
                node *prnt = temp;
                temp = temp->right;
<<<<<<< HEAD

                if (temp->value = NULL)
                {
                    temp->value = i;
                    temp->parent = prnt;
=======
                
                if(temp->value=NULL){
                    temp=(node*)(malloc(sizeof(node)));
                    temp->parent=prnt;
                    temp->left=temp->right=NULL;
>>>>>>> 01992ebdd12829653a8ed2aead83e2e857265cbe
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
    bool remove(int num)
    {
    }
    int size()
    {
        return numOfNodes;
    }
    bool contains(int num)
    {
        node *temp = search(num);
        if (temp == NULL)
        {
            return false;
        }
        return true;
    }
    int root()
    {
        return rootNode->value;
    }
    int parent(int num)
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
    int left(int num)
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
    int right(int num)
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
    void print()
    {
    }
};