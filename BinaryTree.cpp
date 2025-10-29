#include <iostream>
#include "BinaryTree.h"

#include <vector>
#include<stdexcept>
#include <iostream>

template <typename T>
void BinaryTree<T>::setDepth(int n) {
    _tree.resize(n);   // Resize the number of levels
    for (int i = 0; i < n; i++) {
        _tree[i].resize(i + 1); //Each level has i has i+1 nodes
    }
    _depth = n; //Update the attribut of the class
}

template <typename T>
void BinaryTree<T>::setNode(int n, int i, T value){ //Set the value stored in value _tree at the given indices n,i
    if((n < _depth) && (n >= 0) && (_tree[n].size() > i) && (_tree[n].size()>=0)){
        _tree[n][i] = value;
    }
    else{
        throw std::invalid_argument("Node or Depth is incorrect");
    }
}

template <typename T>
T BinaryTree<T>::getNode(int n, int i) const { //Get the value of the node at the indice n,i
    if((n < _depth) && (n >= 0) && (_tree[n].size() > i) && (_tree[n].size()>=0)){
        return _tree[n][i];
    }
    else{
        throw std::invalid_argument("Node or Depth is incorrect");
    }
}
template <typename T>
void BinaryTree<T>::display() {     //Display in a beautiful way the tree
    for(int i=0; i < _depth; i++){
        for(int j=0; j < _tree[i].size(); j++){
            std::cout << _tree[i][j] <<" "; 
        }
        std::cout << std::endl;
    }
} 