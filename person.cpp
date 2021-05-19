#include "person.h"

using namespace std;

Person::Person(){
  name = "";
  age = "";
  occupation = "";
}

Person::Person(string iname, string iage, string ioccupation){
  name = iname;
  age = iage;
  occupation = ioccupation;
}

Person::Person(string iname, string iage, string ioccupation, vector<string> ifriends){
  name = iname;
  age = iage;
  occupation = ioccupation;
  friends = ifriends;
}