#include "redBlack.h"
#include <queue>
#include <math.h>
#include <string>

using namespace std;

redBlack::redBlack(){
  TNULL = new Node;
  TNULL->color = 0;
  TNULL->left = NULL;
  TNULL->right = NULL;
  TNULL->friendRoot = NULL;
  TNULL->friendHead = NULL;
  TNULL->visited = false;
  root = TNULL;
  size = 0;
}

bool redBlack::isFriended(Node*a, Node*b){
  for(friendEdge* i = a->friendRoot; i; i = i->next){
    if(i->connectionNode == b){
      return true;
    }
  }
  return false;
}

void redBlack::dfs(Node* a, std::queue<Node*>& nodes){
  a->visited = true;
  friendEdge* adjacentIterator = a->friendRoot;
  while(adjacentIterator){
    if(!adjacentIterator->connectionNode->visited)
      dfs(adjacentIterator->connectionNode, nodes);
  }
}

void redBlack::addFriend(std::string nameA, std::string nameB){
  // find respective nodes
  Node* a = findPersonNode(nameA);
  Node* b = findPersonNode(nameB);
  if(a == TNULL || b == TNULL)
    return;
  // check if a and b are friendless, if true:
  // new network is created for each 
  if(!a->friendRoot && !b->friendRoot){

    a->friendRoot = new friendEdge;
    a->friendRoot->connectionNode = b;
    a->friendRoot->next = NULL;
    a->friendHead = a->friendRoot;

    b->friendRoot = new friendEdge;
    b->friendRoot->connectionNode = a;
    b->friendRoot->next = NULL;
    b->friendHead = b->friendRoot;
    return;
  }
  // check if a or b are friendless, if true:
  // update each accordingly
  if(!b->friendRoot){
    a->friendHead->next = new friendEdge;
    a->friendHead->next->connectionNode = b;
    a->friendHead->next->next = NULL;
    a->friendHead = a->friendHead->next;
    b->friendRoot = new friendEdge;
    b->friendRoot->connectionNode = a;
    b->friendRoot->next = NULL;
    b->friendHead = b->friendRoot;
    return;
  } else if (!a->friendRoot) {
    b->friendHead->next = new friendEdge;
    b->friendHead->next->connectionNode = a;
    b->friendHead->next->next = NULL;
    b->friendHead = b->friendHead->next;
    a->friendRoot = new friendEdge;
    a->friendRoot->connectionNode = b;
    a->friendRoot->next = NULL;
    a->friendHead = a->friendRoot;
    return;
  }
  // check if already friends:
  if(isFriended(a,b))
    return;
  // continue
  a->friendHead->next = new friendEdge;
  a->friendHead = a->friendHead->next;
  a->friendHead->connectionNode = b;
  a->friendHead->next = NULL;

  b->friendHead->next = new friendEdge;
  b->friendHead = b->friendHead->next;
  b->friendHead->connectionNode = a;
  b->friendHead->next = NULL;
  return;
}

void redBlack::createTree(string in){
  ifstream input;
  ifstream friendInput;
  input.open(in);
  friendInput.open(in);
  std::string word;

  // insert all names into rb tree
  int index = 0;
  while(getline(input, word)){
    if(index == 0){
      index++;
      continue;
    }
    char name[20];
    for(int i = 0; i < 20; i++){
      if(word[i] == ','){
        break;
      }
      name[i] = word[i];
    }
    insert(name);
    index++;
    memset(name, 0, 20);
  }

  // initialize all friends for each name in rb tree
  index = 0;
  while(getline(friendInput, word)){
    if(index == 0){
      index++;
      continue;
    }

    size_t i = 0;

    char name[20];
    for(int k = 0; k < 20; k++){
      if(word[k] == ','){
        i = k + 1;
        break;
      }
      name[k] = word[k];
    }
    for(int commas = 1; commas < 3; i++){
      if(word[i] == ','){
          commas++;
      }
    }

    vector<string> friends;
    char friendName[20];
    int n = 0;
    do{
      i++;
      if(word[i] == ','){
        friends.push_back(friendName);
        n = 0;
        memset(friendName, 0, 20);
        continue;
      }
      friendName[n] = word[i];
      n++;
    } while(word[i] != '"' && i <word.size());
    for(size_t j = 0; j < friends.size(); j++){
      addFriend(name, friends.at(j));
    }
    index++;
    memset(name, 0, 20);
  }
}

void redBlack::addUser(string n, int a, string o, string friends[], int friendsSize){
  insert(n);
  for(int i = 0; i < friendsSize; i++){
    addFriend(n, friends[i]);
  }
  ofstream prof;
  prof.open("ProfileData.txt", fstream::app);

  char name[20];
  char age[3];
  char occupation[30];

  strcpy(name, n.c_str());
  strcpy(age, to_string(a).c_str());
  strcpy(occupation, o.c_str());

  prof << name << ',' << age << ',' << occupation << "\n";
}


void redBlack::insert(std::string n){
  size++;
  Node* node = new Node;
  node->name = n;
  node->parent = NULL;
  node->left = TNULL;
  node->right = TNULL;
  node->index = getSize();
  node->color = 1; // inserted as RED
  node->visited = false;
  node->friendRoot = NULL;
  node->friendHead = NULL;
  Node* x = this->root;
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
    if(k->parent == k->parent->parent->right){
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

void redBlack::leftRotate(Node* x){
  Node* y = x->right;
  x->right = y->left;
  if(y->left != TNULL){
    y->left->parent = x;
  }
  y->parent = x->parent;
  if(x->parent == NULL){
    root = y;
  }else if(x == x->parent->left){
    x->parent->left = y;
  }else{
    x->parent->right = y;
  }

  y->left = x;
  x->parent = y;
}

void redBlack::rightRotate(Node* x){
  Node* y = x->left;
  x->left = y->right;
  if(y->right != TNULL){
    y->right->parent = x;
  }
  y->parent = x->parent;
  if(x->parent == NULL){
    root = y;
  }else if(x == x->parent->left){
    x->parent->left = y;
  }else{
    x->parent->right = y;
  }

  y->right = x;
  x->parent = y;
}

void redBlack::findPerson(std::string n){
  // int i = findPersonNode(n)->index;
  int i = findPersonHelper(root, n);
  if(i == -1){
    cout << "Person not found." << endl;
  }else{
    printPerson(i);
  }
}

int redBlack::findPersonHelper(Node* r, std::string n){
  if(r == TNULL){
    return -1;
  }
  if(r->name == n){
    return r->index;
  }else if((r->name) > n){
    return findPersonHelper(r->left, n);
  }else{
    return findPersonHelper(r->right, n);
  }
}
Node* redBlack::findPersonNode(std::string n){
  Node* i = findPersonHelperNode(root, n);
  return i;
}

Node* redBlack::findPersonHelperNode(Node* r, std::string n){
  if(r == TNULL){
    return r;
  }
  if(r->name == n){
    return r;
  }else if((r->name) > n){
    return findPersonHelperNode(r->left, n);
  }else{
    return findPersonHelperNode(r->right, n);
  }
}

int redBlack::findHeight(){
  if(root)
    return findHeightHelper(root, 0);
  return -1;
}
int redBlack::findHeightHelper(Node* root, int level){
  if(!root)
    return level;
  int left = findHeightHelper(root->left, level+1);
  int right = findHeightHelper(root->right, level+1);
  if(left > right)
    return left;
  return right;
}


std::string redBlack::friendsToString(const Node* a){
  std::string output = "";
  friendEdge* friendIterator = a->friendRoot;
  while(friendIterator){
    output += friendIterator->connectionNode->name + ", ";
    friendIterator = friendIterator->next;
  }
  return output;
}

void redBlack::printAll(){
  if(root){
    printHelper(root, "", true);
    cout << endl;
    printAllHelper(root, "", 1);
  }
}

void redBlack::listFriendsInfo(std::string main){
  
  Node* mainFriend = findPersonNode(main);
  /*
  if(mainFriend == TNULL){
    cout << "Input not found." << endl;
    return;
  }
  */
 cout << "Information of " << main <<"'s friends: " << endl;
 if(mainFriend == TNULL){
   cout << "Input not found." << endl;
   return;
 }
  
  for(friendEdge* i = mainFriend->friendRoot; i; i = i->next){
    findPerson(i->connectionNode->name);
  }
}

void redBlack::printAllHelper(Node* root, std::string indent, int level){
  if(root == TNULL)
    return;
  findPerson(root->name);
  printAllHelper(root->left, indent, level+1);
  printAllHelper(root->right, indent, level+1);
}

void redBlack::printHelper(Node* root, std::string indent, bool last){
  if(root != TNULL){
    cout << indent;
    if(last){
      cout << "R----";
      indent += "    ";
    }else{
      cout << "L----";
      indent += "|    ";
    }
    // std::string sColor = root->color?"RED":"BLACK";
    std::string sColor = root->color?"\033[1;31mRED\033[0m":"\033[1;30mBLACK\033[0m";
    cout << root->name << ":" << root->index << "(" << sColor << ")\"" << friendsToString(root) << "\"" << endl;
    printHelper(root->left, indent, false);
    printHelper(root->right, indent, true);
  }
}

int redBlack::getSize(){
  return size;
}

void redBlack::rangePrint(string a, string b){
  rangeHelp(a, b, root);
}

void redBlack::rangeHelp(string a, string b, Node* r){
  if(r == NULL){
    return;
  }
  if(a < r->name){
    rangeHelp(a, b, r->left);
  }
  if( a <= r->name && b >= r->name){
    printPerson(r->index);
  }
  if(b > r->name){
    rangeHelp(a, b, r->right);
  }
}