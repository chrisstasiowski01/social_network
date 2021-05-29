#include "profData.h"

using namespace std;

void initializeFile(string inputFile){
  Person x;
  ifstream input;
  input.open(inputFile);
  string i;
  string k;
  vector<string> data;
  int lim;
  ofstream prof;
  prof.open("ProfileData.txt");

  while(getline(input, i)){
    lim = 0;
    while(getline(input, k, ',') && lim < 3){
      data.push_back(k);
    }
    x.setName(data[0]);
    x.setAge(data[1]);
    x.setOccupation(data[2]);

    char name[20];
    char age[3];
    char occupation[30];

    strcpy(name, (x.getName()).c_str());
    strcpy(age, (x.getAge()).c_str());
    strcpy(occupation, (x.getOccupation()).c_str());

    prof << name << age << occupation << "\n";

    data.pop_back();
    data.pop_back();
    data.pop_back();

  }
}

void addPerson(Person p){
  ofstream prof;
  prof.open("ProfileData.txt");

  char name[20];
  char age[3];
  char occupation[30];

  strcpy(name, (p.getName()).c_str());
  strcpy(age, (p.getAge()).c_str());
  strcpy(occupation, (p.getOccupation()).c_str());

  prof << name << age << occupation << "\n";
}