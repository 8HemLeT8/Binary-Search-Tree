// Include only once
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
  // Constructor
  Node(int num);
  Node();
};

namespace ariel
{

class Tree
{
private:
  // Tree head
  Node *rootNode;
  // Tree size
  int numOfNodes;
  // Helper functions
  Node *search(int num);
  Node *SearchHelper(int num, Node *curr);
  void inOrder(Node *root) const;
  Node *FindNext(int num);
  Node *FindNext(Node *curr);
  void DestroyTree(Node* curr);

public:
  // Constructors
  Tree();
  // Deconstructors
  ~Tree();
  // Tree operations
  bool insert(int num);
  bool remove(int num);
  int size();
  bool contains(int num);
  int root();
  int parent(int num);
  int left(int num);
  int right(int num);
  void print() const;
};
} // namespace ariel