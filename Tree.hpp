#pragma once

#include <cstdio>
#include <stdexcept>
#include <sstream>
#include <cstdlib>
#include <iostream>
struct Node
{
    int value;
    Node *parent;
    Node *left;
    Node *right;

    Node(int key);
};

namespace ariel
{

class Tree
{
private:
  Node *rootNode;
  int numOfNodes;

  Node *search(int num);
  Node *SearchHelper(int num, Node *curr);

public:
  Tree();
  bool insert(int i);
  bool remove(int num);
  int size();
  bool contains(int num);
  int root();
  int parent(int num);
  int left(int num);
  int right(int num);
  void print();
  void inOrder(Node *root);
};
} // namespace ariel