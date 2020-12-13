//
// Created by Rodolfo J. Galván Martínez on 12/11/20.
//

#include "BinaryNodeTree.h"
#include <iomanip>
#include "Employee.h"
#include "BinaryNode.h"
//    -------------------------------
//      Constructors and destructors
//    -------------------------------
template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree() : rootPtr(nullptr){};

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem)
        :rootPtr(std::make_shared<BinaryNode<ItemType>> (rootItem, nullptr, nullptr)) {};

template<class ItemType>
BinaryNodeTree<ItemType>::BinaryNodeTree(const ItemType& rootItem,
                               const std::shared_ptr<BinaryNodeTree<ItemType>> leftTreePtr,
                               const std::shared_ptr<BinaryNodeTree<ItemType>> rightTreePtr)
                               : rootPtr(std::make_shared<BinaryNode<ItemType>>(rootItem, copyTree(leftTreePtr->rootPtr), copyTree(rightTreePtr->rootPtr))){};

template<class ItemType>
BinaryNodeTree<ItemType>::~BinaryNodeTree(){
  destroyTree(rootPtr);
}

//    -------------------------------------------------
//      Protected Utility Methods
//      Recursive helper methods for the public methods.
//    -------------------------------------------------
template<class ItemType>
int BinaryNodeTree<ItemType>::getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const {
  if(subTreePtr == nullptr)
    return 0;
  else
    return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()),
                        getHeightHelper(subTreePtr->getRightChildPtr()));
}

template<class ItemType>
auto BinaryNodeTree<ItemType>::balancedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                                           std::shared_ptr<BinaryNode<ItemType>> newNodePtr) {
  if (subTreePtr == nullptr)
    return newNodePtr;
  else{
    auto leftPtr = subTreePtr->getLeftChildPtr();
    auto rightPtr = subTreePtr->getRightChildPtr();

    if (getHeightHelper(leftPtr) > getHeightHelper(rightPtr)){
      rightPtr = balancedAdd(rightPtr, newNodePtr);
      subTreePtr->setRightChildPtr(rightPtr);
    }else{
      leftPtr = balancedAdd(leftPtr, newNodePtr);
      subTreePtr->setLeftChildPtr(leftPtr);
    }

    return subTreePtr;
  }
};

template<class ItemType>
auto BinaryNodeTree<ItemType>::removeValue(std::shared_ptr<BinaryNode<ItemType>> subTreePtr, const ItemType target,
                                           bool &isSuccessful) {
  if(subTreePtr == nullptr){ //If the subtree is empty
    return subTreePtr;
  }else if(subTreePtr->getItem() == target){
    // Item is in the root of some subtree
    subTreePtr = moveValuesUpTree(subTreePtr);
    isSuccessful = true;
    return subTreePtr;
  }else{
    auto targetNodePtr = removeValue(subTreePtr->getLeftChildPtr(), target, isSuccessful);
    subTreePtr->setLeftChildPtr(targetNodePtr);
    if(!isSuccessful){
      targetNodePtr = removeValue(subTreePtr->getRightChildPtr(), target, isSuccessful);
      subTreePtr->getRightChildPtr(targetNodePtr);
    }
    return  subTreePtr;
  }
}

template<class ItemType>
auto BinaryNodeTree<ItemType>::moveValuesUpTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) {
  auto leftPtr = subTreePtr->getLeftChildPtr();
  auto rightPtr = subTreePtr->getRightChildPtr();
  int lHeight = getHeightHelper(leftPtr);
  int rHeight = getHeightHelper(rightPtr);
  if (lHeight > rHeight){
    subTreePtr->setItem(leftPtr->getItem());
    leftPtr = moveValuesUpTree(leftPtr);
    subTreePtr->setLeftChildPtr(leftPtr);
    return subTreePtr;
  } else{
    if (rightPtr != nullptr){
      subTreePtr->setItem(rightPtr->getItem());
      rightPtr = moveValuesUpTree(rightPtr);
      subTreePtr->setRightChildPtr(rightPtr);
      return subTreePtr;
    } else{
      return nullptr; // A leaf was reached
    }
  }
}

template<class ItemType>
auto BinaryNodeTree<ItemType>::copyTree(
        const std::shared_ptr<BinaryNode<ItemType>> oldTreeRootPtr) const {
  std::shared_ptr<BinaryNode<ItemType>> newTreePtr;

  // copy tree nodes during a preorder traversal
  if(oldTreeRootPtr != nullptr){
    // Copy node
    newTreePtr = std::make_shared<BinaryNode<ItemType>>(oldTreeRootPtr->getItem(), nullptr, nullptr);
    newTreePtr->setLeftChildPtr(copyTree(oldTreeRootPtr->getLeftChildPtr()));
    newTreePtr->setRightChildPtr(copyTree(oldTreeRootPtr->getRightChildPtr()));
  }
  return newTreePtr;
}

template<class ItemType>
void BinaryNodeTree<ItemType>::destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) {
  if (subTreePtr != nullptr){
    destroyTree(subTreePtr->getLeftChildPtr());
    destroyTree(subTreePtr->getRightChildPtr());
    subTreePtr.reset(); // Decrement reference count to node.
  }
}

template<class ItemType>
void BinaryNodeTree<ItemType>::inorder(void (*visit)(ItemType &),
                                       std::shared_ptr<BinaryNode<ItemType>> treePtr) const {
  if( treePtr != nullptr){
    inorder(visit, treePtr->getLeftChildPtr());
    ItemType theItem = treePtr->getItem();
    visit(theItem);
    inorder(visit, treePtr->getRightChildPtr());
  }
}

template<class ItemType>
void BinaryNodeTree<ItemType>::graphorder(std::ostream &out, int indent,
                                          std::shared_ptr<BinaryNode<ItemType>> treePtr) const {
  if (treePtr != nullptr){
    graphorder(out, indent+8, treePtr->getRightChildPtr());
    out << std::setw(indent) << " " << treePtr->getItem() << std::endl;
    graphorder(out, indent+8, treePtr->getLeftChildPtr());
  }
}

//    ---------------------------------------------
//      Public BinaryTreeInterface Methods Section
//    ---------------------------------------------
template<class ItemType>
bool BinaryNodeTree<ItemType>::add(const ItemType &newData) {
  auto newNodePtr = std::make_shared<BinaryNode<ItemType>>(newData);
  rootPtr = balancedAdd(rootPtr);
  return true;
}

template<class ItemType>
bool BinaryNodeTree<ItemType>::remove(const ItemType &data) {
  // Locate the target using the search algorithm,
  bool isSuccessful = false;
  rootPtr = removeValue(rootPtr, data, isSuccessful);
  return isSuccessful;
}


//    ---------------------------------------------
//      Public Traversals Section
//    ---------------------------------------------

template<class ItemType>
void BinaryNodeTree<ItemType>::inorderTraverse(void (*visit)(ItemType &)) const {
  inorder(visit, rootPtr);
}

template<class ItemType>
void BinaryNodeTree<ItemType>::graphdisplay(std::ostream &out) const {
  graphorder(out, 0, rootPtr);
}

//    ---------------------------------------------
//      Overload Operators Section
//    ---------------------------------------------
template<class ItemType>
BinaryNodeTree<ItemType>& BinaryNodeTree<ItemType>::operator=(const BinaryNodeTree<ItemType> &rightHandSide) {
  if (!isEmpty())
    clear();
  this = copyTree(&rightHandSide);
  return *this;
}

void temporaryBinaryNodeTree(){
//  Employee aTempEmployee(1, "1");
//  BinaryNode<Employee> aTempBinaryNode(aTempEmployee);
//  BinaryNodeTree<BinaryNode<Employee>> aTemporaryTree;
}