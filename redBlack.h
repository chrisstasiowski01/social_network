// redBlack.h
// header file for red-black tree and its functions

#ifndef REDBLACK_H
#define REDBLACK_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

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

    void createTree(std::string file); // creates red-black tree from data file given
    void insert(std::string n, int a,  std::string o, std::string profData); // inserts node into red-black tree and adds info to profile data file
    void printAll(); // prints contents of red-black tree
  
  private:

    void fixInsert(Node* k); // fixes tree after inserting value
    void leftRotate(Node* x);
    void rightRotate(Node* x);


};

#endif