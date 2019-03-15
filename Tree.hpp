#pragma once
 
#include <cstdio>
#include <stdexcept>
#include <sstream>
#include <cstdlib>
#include <iostream>

struct node
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

    node *search(int num);
    node *SearchHelper(int num, node *curr);

  public:
    bool insert(int i);
    bool remove(int num);
    int size();
    bool contains(int num);
    int root();
    int parent(int num);
    int left(int num);
    int right(int num);
    void print();
    void inOrder(node *root);
};