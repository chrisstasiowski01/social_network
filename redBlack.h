// redBlack.h
// header file for red-black tree and its functions

#ifndef REDBLACK_H
#define REDBLACK_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include "profData.h"

struct Node{
  std::string name;
  int index;
  
  Node* parent;
  Node* left;
  Node* right;
  int color; // 0 = black, 1 = red
};

class redBlack{
  
  public:
    redBlack();
    void createTree(); // creates red-black tree from data file given
    void insert(std::string n, int i); // inserts node into red-black tree
    void printAll(); // prints contents of red-black tree
    void findPerson(std::string n); // searches for n and prints info from profile data

  private:

    void printHelper(Node* p);
    void fixInsert(Node* k); // fixes tree after inserting value
    void leftRotate(Node* x);
    void rightRotate(Node* x);
    int findPersonHelper(Node* r, std::string n); // searches for and returns index of n

    Node* root;
    Node* TNULL;


};

#endif