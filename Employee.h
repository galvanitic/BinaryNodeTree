//
// Created by Rodolfo J. Galván Martínez on 12/11/20.
//

#ifndef BINARYTREES_EMPLOYEE_H
#define BINARYTREES_EMPLOYEE_H
#include <string>
#include <iostream>
using namespace std;

class Employee {
private:
    int ID = -1; // An employee's ID.
    string NAME = " "; // An employee's name.
public:
    Employee();
    Employee(int id, string name);

    // Sets a given ID.
    // Returns true if set successfully
    bool setID(int id);
    // Sets a given name.
    // Returns true if set successfully
    bool setName(string name);

    // Gets an employee's ID
    // Returns an int
    int getID() const;
    // Gets an employee's name
    // Returns a string
    string getName() const;
};


#endif //BINARYTREES_EMPLOYEE_H
