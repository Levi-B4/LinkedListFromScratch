#ifndef NODE_H
#define NODE_H

//contains data and a pointer to the next node
class Node{
    public:
        //value and pointer to another node
        int data;
        Node* next;
        //default constructor
        Node();
        //constructor with data
        Node(int data);
        //deconstructor
        ~Node();
    private:

};

#endif // NODE_H
