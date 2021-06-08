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
    string word = "";
    lim = 0;
    for(size_t j = 0; j < i.size() && lim < 3; j++){
      if(i[j] != ','){
        word += i[j];
      }else{
        if(lim < 2){
          word += ",";
        }
        lim++;
        data.push_back(word);
        word = "";
      }
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

void printPerson(int index){
  ifstream input;
  input.open("ProfileData.txt");
  int counter = 0;
  string line;
  while(getline(input, line)){
    if(counter == index){
      cout << line << endl;
      break;
    }else{
      counter++;
    }
  }
}