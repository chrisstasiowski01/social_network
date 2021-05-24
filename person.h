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
    
    // setters
    void setName(std::string n);
    void setAge(std::string a);
    void setOccupation(std::string o);

    // getters
    std::string getName();
    std::string getAge();
    std::string getOccupation();
  private:
    std::string name;
    std::string age;
    std::string occupation;
    std::vector<std::string> friends;
};

#endif