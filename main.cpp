#include <iostream>
#include "Employee.h"
#include "BinaryNode.h"
#include "BinaryNodeTree.h"
int main() {
  // Predetermined Data
  int employeeIds [10] = {6702, 1255, 1071, 2390, 1558, 7406, 7562, 3004, 4922, 8483};
  string employeeNames [10] = {"James B W Bevis", "Romney Wordsworth", "Revis Jacara", "Clegg Forbes", "Kalin Tros", "Archibald Beechcroft", "Penthor Mul", "Bartlet Finchley", "Latham Bine", "Jeff Myrtlebank"};

  // Begin creating employees, nodes, and trees from given data.
  BinaryNodeTree<BinaryNode<Employee>> aBinaryTree; // Create an empty binary tree
  for (int i = 0; i <= 10; i++){
    Employee anEmployee(employeeIds[i], employeeNames[i]); // Grab employee data...
    BinaryNode<Employee> employeeNode(anEmployee); // Make a node with employee data...
    aBinaryTree.add(employeeNode); // Add employee data to our tree
  }

  aBinaryTree.graphdisplay(cout);

  return 0;
}
