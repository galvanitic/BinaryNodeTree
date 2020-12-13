//
// Created by Rodolfo J. Galván Martínez on 12/11/20.
//

#ifndef BINARYTREES_BINARYNODE_H
#define BINARYTREES_BINARYNODE_H
#include <memory>

template<class ItemType>
class BinaryNode {
private:
    ItemType item; // item data
    std::shared_ptr<BinaryNode<ItemType>> leftChildPtr; // Pointer to left child
    std::shared_ptr<BinaryNode<ItemType>> rightChildPtr; // Pointer to right child

public:
    BinaryNode();
    explicit BinaryNode(const ItemType& anItem);
    BinaryNode(const ItemType& anItem,
               std::shared_ptr<BinaryNode<ItemType>> leftPtr,
               std::shared_ptr<BinaryNode<ItemType>> rightPtr);

    void setItem(const ItemType& anItem);
    ItemType getItem() const;

    bool isLeaf() const;

    auto getLeftChildPtr() const;
    auto getRightChildPtr() const;

    void setLeftChildPtr(std::shared_ptr<BinaryNode<ItemType>> leftPtr);
    void setRightChildPtr(std::shared_ptr<BinaryNode<ItemType>> rightPtr);
};


#endif //BINARYTREES_BINARYNODE_H
