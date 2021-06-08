#include "redBlack.h"
#include "profData.h"

using namespace std;

int main(){

  initializeFile("users_10.csv");

  cout << "TESTING createTree() USING PROFILE DATA.TXT..." << endl;
  redBlack rb;
  rb.createTree();

  cout << "TESTING printAll()..." << endl;
  rb.printAll();

  cout << "TESTING insert('Christopher')..." << endl;
  rb.insert("Christopher");
  rb.printAll();

  cout << "TESTING findHeight()..." << endl;
  cout << rb.findHeight() << endl;

  cout << "TESTING printFriends()..." << endl;


  return 0;
}