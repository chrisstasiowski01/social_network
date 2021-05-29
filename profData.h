#ifndef PROFDATA_H
#define PROFDATA_H

#include "person.h"

#include <cstring>
#include <string>

void initializeFile(std::string inputfile); // initializes Profile Data file given input file

void addPerson(Person p); // adds person to file

void printPerson(int index); // given an index, prints person's name, age, occupation

#endif