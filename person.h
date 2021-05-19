#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Person{
  
  public:
    Person(); // constructor for empty person object
    Person(std::string iname, std::string iage, std::string ioccupation); // creates person object w/o list of friends
    Person(std::string iname, std::string iage, std::string ioccupation, std::vector<std::string> ifriends); // creates full person object

  private:
    std::string name;
    std::string age;
    std::string occupation;
    std::vector<std::string> friends;
};

#endif