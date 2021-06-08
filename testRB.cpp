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

  cout << "TESTING insert()..." << endl;
  rb.insert("Christopher", 5);
  rb.printAll();

  return 0;
}