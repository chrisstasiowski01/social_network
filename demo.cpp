#include "redBlack.h"
#include "profData.h"

using namespace std;

int main(){
  cout << endl << "TESTING INITIALIZATION..." << endl;
  initializeFile("final_demo_users_5000.csv");
  
  redBlack rb;
  
  rb.createTree("final_demo_users_5000.csv");
  cout << "    initialization complete." << endl << endl;

  cout << "TESTING POINT QUERY..." << endl;
  cout << "    Searching for Ashley Garcia..." << endl;
  cout << "        ";
  rb.findPerson("Ashley Garcia");
  cout << endl;
  cout << "    Searching for Ryan Heath..." << endl;
  cout << "        ";
  rb.findPerson("Ryan Heath");
  cout << endl;
  cout << "    Searching for Holly Flores..." << endl;
  cout << "        ";
  rb.findPerson("Holly Flores");
  cout << endl;
  cout << "    Searching for non-existent person..." << endl;
  cout << "        ";
  rb.findPerson("Not in tree");
  cout << endl;

  cout << "TESTING RANGE QUERY..." << endl;
  cout << "    Running range query on Christie Smith, Evan Baldwin..." << endl;
  rb.rangePrint("Christie Smith", "Evan Baldwin");
  cout << endl;

  cout << "TESTING FOR ADDITION OF USER (Chris Stasi, 20, student, [Ashley Garcia, Holly Flores])" << endl;
  string chrisFriend[5] = {"Ashley Garcia", "Holly Flores"};
  rb.addUser("Chris Stasi", 20, "student", chrisFriend, 2);
  cout << "    Running point query on Chris Stasi..." << endl;
  cout << "        ";
  rb.findPerson("Chris Stasi");
  cout << "    Running friend query on Chris Stasi's friends..." << endl;
  rb.listFriendsInfo("Chris Stasi");

  cout << endl << "TESTING FOR FRIEND QUERY..." << endl;
  cout << "        ";
  rb.listFriendsInfo("Nicole Wilson");
  cout << endl;
  cout << "        ";
  rb.listFriendsInfo("Brenda Santos");
  cout << endl;
  cout << "        ";
  rb.listFriendsInfo("Non-existent user");
  cout << endl;
  cout << "        ";
  rb.listFriendsInfo("Ashley Garcia");
  
  cout << endl << "END TESTS" << endl << endl;
  return 0;
}