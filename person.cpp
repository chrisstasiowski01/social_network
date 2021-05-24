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

void Person::setName(string n){
  name = n;
}

void Person::setAge(string a){
  age = a;
}

void Person::setOccupation(string o){
  occupation = o;
}

string Person::getName(){
  return name;
}

string Person::getAge(){
  return age;
}

string Person::getOccupation(){
  return occupation;
}