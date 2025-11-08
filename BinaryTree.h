#pragma once

#include <vector>
#include<stdexcept>
#include <iostream>

template <typename T> //BinaryTree<int>, the compilator replace all T by int
class BinaryTree {
private :
    int _depth;
    std::vector<std::vector<T>> _tree;
public:
    // Constructors
    BinaryTree(int depth);
    BinaryTree() : _depth(0) {}

    // Destructor
    ~BinaryTree();
    
    void setDepth(int); //Set the depth of the tree and allocates/deallocate the vectors in tree 
    void setNode(int, int, T); //Set the value stored in value _tree at the given indices n,i
    T getNode(int, int) const ; //Get the value of the node at the indice n,i
    void display(); //Display in a beautiful way the tree
};
