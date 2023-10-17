#ifndef LINKEDLIST
#define LINKEDLIST

#include <iostream>

#include "Node.h"

using std::string;

class LinkedList{

    //pointer to first node of list
        Node* head;

    public:
        //default constructor
        LinkedList();

        //constructor with array
        LinkedList(int* dataStart, int dataSize);


        //returns value at index
        int getIndex(int index);

        //returns true if list has an index
        bool hasIndex(int index);

        //print out nodes to console
        string toString();

        //add node to back of list
        void insertNode(int value);

        //delete node at given position
        void deleteNode(int position);

        //deconstructor
        ~LinkedList();

    private:

};

#endif // LINKEDLIST

