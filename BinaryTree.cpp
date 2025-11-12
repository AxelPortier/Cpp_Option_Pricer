#include <iostream>
#include "BinaryTree.h"

#include <vector>
#include<stdexcept>
#include <iostream>

// Constructor
template <typename T>
BinaryTree<T>::BinaryTree(int depth) {
    _depth = depth;
    _tree.resize(_depth + 1);  //Initialize the full tree 
    for (int i = 0; i < _tree.size(); i++)
        _tree[i].resize(i + 1); // Initialize the size of each level [[..,..],[[..,..][..,..]],..]
}

//Destructor
template <typename T>
BinaryTree<T>::~BinaryTree(){}

template<typename T>
void BinaryTree<T>::setDepth(int depth){
    if(_depth > depth){ //Erase a part of the tree
        _depth = depth;
        _tree.resize(_depth + 1);
    }
    else{ //Create new branches in this case
        _tree.resize(depth + 1);
        for(int i = _depth; i < _tree.size(); i++){
            _tree[i].resize(i+1);
        }
        _depth = depth;
    }
}

template <typename T>
void BinaryTree<T>::setNode(int n, int i, T value){ //Set the value stored in value _tree at the given indices n,i
    if((n <= _depth) && (n >= 0) && (i >= 0) && (i < _tree[n].size())){
        _tree[n][i] = value;
    }
    else{
        throw std::invalid_argument("Node or Depth is incorrect");
    }
}

template <typename T>
T BinaryTree<T>::getNode(int n, int i) const { //Get the value of the node at the indice n,i
    if((n <= _depth) && (n >= 0) && (_tree[n].size() > i) && (_tree[n].size()>=0)){
        return _tree[n][i];
    }
    else{
        throw std::invalid_argument("Node or Depth is incorrect");
    }
}
template <typename T>
void BinaryTree<T>::display() {     //Display in a beautiful way the tree
    for(int i=0; i <= _depth; i++){
        for(int j=0; j < _tree[i].size(); j++){
            std::cout << _tree[i][j] <<" "; 
        }
        std::cout << std::endl;
    }
} 

template class BinaryTree<double>;
template class BinaryTree<bool>;
template class BinaryTree<int>;
