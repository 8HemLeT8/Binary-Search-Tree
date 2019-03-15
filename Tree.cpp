#include <cstdio>
typedef struct node 
{
    int value;
    node *parent;
    node *left;
    node *right;
};

class Tree{
    private:
    node root;
    int size;
    
    node *search(int num)
    {
        if (root == NULL)
        {
            return NULL;
        }
    }

    public:
   
    bool insert(int i){
        if(root.value == NULL){
            root.value=i;
            return true;
        }
        node *temp=&root;
        node *troot=&root;
        while (true){ 
            if(i<temp->value){
                node* prnt =temp;
                temp = temp->left;
                
                if(temp->value=NULL){
                    temp->value=i;
                    temp->parent=prnt;
                    size++;
                    return true;
            }
            }
            else if(i>temp->value){
                node* prnt =temp;
                temp = temp->right;
                
                if(temp->value=NULL){
                    temp->value=i;
                    temp->parent=prnt;
                    size++;
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
        return size;
    }
    bool contains(int num)
    {

    }
    int root(){
        return root.value;
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