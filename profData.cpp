#include "profData.h"

using namespace std;

void initializeFile(string inputFile){
  // WORK IN PROGRESS
  Person x;
  ifstream input;
  input.open(inputFile);
  string i;
  string k;
  vector<string> data;
  int lim;

  while(getline(input, i)){
    lim = 0;
    while(getline(i, k, ',') && lim < 3){
      data.push_back(k);

    }
  }
}