#include "Node.h"


//contains data and a pointer to the next node

//default constructor
Node::Node(){
    data = 0;
    next = nullptr;
}
//constructor with data
Node::Node(int data){
    this->data = data;
    next = nullptr;
}

//deconstructor
Node::~Node(){}
