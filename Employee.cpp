//
// Created by Rodolfo J. Galván Martínez on 12/11/20.
//
#include "Employee.h"

// Default constructor
Employee::Employee() = default;

// Overloaded constructor
// Pre: Takes in an id as an int and a name as a string.
Employee::Employee(int id, string name) : ID(id), NAME(name)  { };

// Sets a given ID.
// Pre: Takes in an id as an int. ID cannot be -1.
// Post: Returns true if set successfully or false if not.
bool Employee::setID(int id) {
  if (id != -1){
    ID = id;
    return true;
  }else {
    return false;
  }
}

// Sets a given name.
// Pre: Takes in a name as a string. String cannot be empty.
// Post: Returns true if set successfully or false if not
bool Employee::setName(string name) {
  if (name != " " || name != ""){
    NAME = name;
    return true;
  }else{
    return false;
  }

}

// Gets the emloyee's ID
// Pre: none
// Post: Returns an int. If no ID exists, function returns -1.
int Employee::getID() const {
  return ID;
}

// Gets an employee's name
// Pre: none
// Post: Returns a string. If no name exists, function returns an empty string.
string Employee::getName() const {
  if (NAME != " "){
    return NAME;
  }
}