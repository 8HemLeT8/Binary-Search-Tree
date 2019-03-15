#include <cstdio>
#include<stdlib.h> 

struct node 
{
    int value;
    node *parent;
    node *left;
    node *right;
};

class Tree{
    private:
    node *rootNode;
    int numOfNodes;
    
    node *search (int num)
    {
        SearchHelper(num, rootNode);
    }

    node *SearchHelper(int num, node *curr)
    {
        if (curr == NULL || curr->value == num)
        {
            return curr;
        }
        else if (num > curr->value){
            SearchHelper(num,curr->right);
        }
        else
        {
            SearchHelper(num,curr->left);
        }
    }

    public:
   
    bool insert(int i){
        if(rootNode->value == NULL){
            rootNode->value=i;
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
                    numOfNodes++;
                    return true;
            }
            }
            else if(i>temp->value){
                node* prnt =temp;
                temp = temp->right;
                
                if(temp->value=NULL){
                    temp=(node*)(malloc(sizeof(node)));
                    temp->parent=prnt;
                    temp->left=temp->right=NULL;
                    numOfNodes++;
                    return true;
            }
            }
            else{
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
    int root(){
        return rootNode->value;
    }
    int parent(int num){

    }
    int left(int num){

    }
    int right(int num){

    }
    void print()
    {

    }
};