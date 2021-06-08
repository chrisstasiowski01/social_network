#include "redBlack.h"
#include "profData.h"

using namespace std;

int main(){
  cout << "TESTING INITIALIZATION..." << endl;
  initializeFile("final_demo_users_5000.csv");
  
  redBlack rb;
  
  rb.createTree("final_demo_users_5000.csv");

  cout << "TESTING POINT QUERY..." << endl;
  cout << "Searching for Ashley Garcia..." << endl;
  rb.findPerson("Ashley Garcia");
  cout << endl;
  cout << "Searching for Ryan Heath..." << endl;
  rb.findPerson("Ryan Heath");
  cout << endl;
  cout << "Searching for Holly Flores..." << endl;
  rb.findPerson("Holly Flores");
  cout << endl;
  cout << "Searching for non-existent person..." << endl;
  rb.findPerson("Not in tree");
  cout << endl;

  cout << "TESTING FOR ADDITION OF USER Chris Stasi, 20, student, [Ashley Garcia, Holly Flores], 2" << endl;
  string chrisFriend[5] = {"Ashley Garcia", "Holly Flores"};
  rb.addUser("Chris Stasi", 20, "student", chrisFriend, 2);
  cout << "Running point query on Chris Stasi..." << endl;
  rb.findPerson("Chris Stasi");
  cout << "Running friend query on Chris Stasi's friends..." << endl;
  rb.listFriendsInfo("Chris Stasi");

  cout << endl << "TESTING FOR FRIEND QUERY..." << endl;
  rb.listFriendsInfo("Nicole Wilson");
  cout << endl;
  rb.listFriendsInfo("Brenda Santos");
  cout << endl;
  rb.listFriendsInfo("Non-existent user");
  cout << endl;
  rb.listFriendsInfo("Chris Stasio");
  cout << endl;
  rb.listFriendsInfo("Ashley Garcia");
  return 0;
}