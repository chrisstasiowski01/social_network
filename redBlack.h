// redBlack.h
// header file for red-black tree and its functions

#ifndef REDBLACK_H
#define REDBLACK_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <queue>

#include "profData.h"

// friendEdge stores each 'friendship' relationship (edge) between two Nodes in a linked list
struct friendEdge;
// node stores the graph's nodes
struct Node;

struct friendEdge{
  Node* connectionNode;
  friendEdge* next;
};
struct Node{
  std::string name;
  Node* parent;
  Node* left;
  Node* right;
  int index;
  int color; // 0 = black, 1 = red
  
  bool visited;
  friendEdge* friendRoot; // first friend to be appended
  friendEdge* friendHead; // last friend to be appended
};

class redBlack{
  public:
    redBlack();
    void createTree(); // creates red-black tree from data file given
    void insert(std::string n); // inserts node into red-black tree
    void printAll(); // prints contents of red-black tree
    void findPerson(std::string n); // searches for n and prints info from profile data
    Node* findPersonNode(std::string n); // searches for n and returns that node, or TNULL if not found
    int getSize(); // returns number of nodes in tree
    void addFriend(std::string nameA, std::string nameB); // creates edge ('frienship') between person A and person B
    void dfs(Node* a, std::queue<Node*>& nodes); // dfs of a
    std::string friendsToString(const Node* a); // gets all friends of node a and appends to string
    int findHeight(); // returns height of tree
    void listFriendsInfo(std::string name); // print info of friends of omid
  private:
    int findHeightHelper(Node* root, int level); // returns height of tree
    bool isFriended(Node*a, Node*b); // returns whether or not a and b are already friends
    void printAllHelper(Node* root, std::string indent, int level);
    void printHelper(Node* root, std::string indent, bool last);
    void fixInsert(Node* k); // fixes tree after inserting value
    void leftRotate(Node* x);
    void rightRotate(Node* x);
    int findPersonHelper(Node* r, std::string n); // searches for and returns index of n
    Node* findPersonHelperNode(Node* r, std::string n); // searches for node r and returns that node, or TNULL if not found

    Node* root;
    Node* TNULL;
    int size;


};

#endif