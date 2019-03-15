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
    bool insert(int num)
    {

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