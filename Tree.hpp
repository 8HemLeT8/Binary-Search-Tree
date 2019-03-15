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