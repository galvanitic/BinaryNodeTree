//
// Created by Rodolfo J. Galván Martínez on 12/11/20.
//

#include "BinaryNode.h"
#include "Employee.h"
// Default constructor.
template<class ItemType>
BinaryNode<ItemType>::BinaryNode() : item(nullptr), leftChildPtr(nullptr), rightChildPtr(nullptr) {};
// Constructor that accepts item data.
template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem) : item(anItem), leftChildPtr(nullptr), rightChildPtr(nullptr) {};
template<class ItemType>
// Constructor that takes in item data, a leftPtr, and a rightPtr.
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem, std::shared_ptr<BinaryNode<ItemType>> leftPtr,
                       std::shared_ptr<BinaryNode<ItemType>> rightPtr)
                       : item(anItem),
                       leftChildPtr(leftPtr),
                       rightChildPtr(rightPtr){};

// Sets the item data in the node.
// Pre: Takes in item data.
// Post: void.
template<class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& anItem) {
  item = anItem;
}

// Retrieves item data.
// Pre: None.
// Post: Returns item data.
template<class ItemType>
ItemType BinaryNode<ItemType>::getItem() const {
  return item;
}

// Checks to see if node is a leaf
// Pre: none
// Post: Returns true if node is a leaf, false if not.
template<class ItemType>
bool BinaryNode<ItemType>::isLeaf() const {
  // Check to see if node has any children.
  if(leftChildPtr || rightChildPtr){ // if left or right pointer exist
    return false;
  }else{
    return true;
  }
}

// Retrieves the left child pointer.
// Pre: There's a left child pointer.
// Post: Returns a BinaryNode ptr.
template<class ItemType>
auto BinaryNode<ItemType>::getLeftChildPtr() const {
  if(leftChildPtr){ // If the left child pointer has something inside.
    return leftChildPtr;
  }
}

// Retrieves the right child pointer.
// Pre: There is a right child pointer.
// Post: Returns a BinaryNode ptr.
template<class ItemType>
auto BinaryNode<ItemType>::getRightChildPtr() const {
  if(rightChildPtr){ // If the right child pointer has something inside.
    return rightChildPtr;
  }
}

// Sets the left child pointer.
// Pre: Accepts a pointer as leftPtr.
// Post: void
template<class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(std::shared_ptr<BinaryNode<ItemType>> leftPtr) {
  leftChildPtr = std::move(leftPtr);
}

// Sets the right child pointer.
// Pre: Accepts a pointer as rightPtr.
// Post: void.
template<class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(std::shared_ptr<BinaryNode<ItemType>> rightPtr) {
  rightChildPtr = std::move(rightPtr);
}

//void TemporaryBinaryNode(){
//  Employee aTempEmployee(1, "1");
//  BinaryNode<Employee> aTempBinaryNode(aTempEmployee);
//  aTempBinaryNode.getLeftChildPtr();
//  aTempBinaryNode.getRightChildPtr();
//  aTempBinaryNode.getItem();
//}