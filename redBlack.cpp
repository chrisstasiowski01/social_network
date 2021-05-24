#include "redBlack.h"

using namespace std;

redBlack::redBlack(){
  TNULL = new Node;
  TNULL->color = 0;
  TNULL->left = NULL;
  TNULL->right = NULL;
  root = NULL;
}

void redBlack::createTree(){
  ifstream input;
  input.open("ProfileData.txt");
  string word;

  int index = 0;
  while(getline(input, word)){
    char name[20];
    for(int i = 0; i < 20; i++){
      name[i] = word[i];
    }
    insert(name, index);
  }
}

void redBlack::insert(string n, int i){
  Node* node = new Node;
  node->parent = NULL;
  node->name = n;
  node->left = TNULL;
  node->right = TNULL;
  node->color = 1; // inserted as RED

  Node* x = root;
  Node* y = NULL;

  while(x != TNULL){
    y = x;
    if(node->name < x->name){
      x = x->left;
    }else{
      x = x->right;
    }
  }

  node->parent = y;
  if(y == NULL){
    root = node;
  }else if(node->name < y->name){
    y->left = node;
  }else{
    y->right = node;
  }

  // if root, set to black and return
  if(node->parent == NULL){
    node->color = 0;
    return;
  }

  if(node->parent->parent == NULL){
    return;
  }
  // else, call helper function to rotate
  fixInsert(node);
}


void redBlack::fixInsert(Node* k){
  Node* n;
  while(k->parent->color == 1){
    if(k->parent = k->parent->parent->right){
      n = k->parent->parent->left;
      if(n->color == 1){
        n->color = 0;
        k->parent->color = 0;
        k->parent->parent->color = 1;
        k = k->parent->parent;
      }else{
        if(k == k->parent->left){
          k = k->parent;
          rightRotate(k);
        }
        k->parent->color = 0;
        k->parent->parent->color = 1;
        leftRotate(k->parent->parent);
      }
    }else{
      n = k->parent->parent->right;
      if(n->color == 1){
        n->color = 0;
        k->parent->color = 0;
        k->parent->parent->color = 1;
        k = k->parent->parent;
      }else{
        if(k == k->parent->right){
          k = k->parent;
          leftRotate(k);
        }
        k->parent->color = 0;
        k->parent->parent->color = 1;
        rightRotate(k->parent->parent);
      }
    }
    if(k == root){
      break;
    }
  }
  root->color = 0;
}