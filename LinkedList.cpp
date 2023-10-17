#include "LinkedList.h"
#include "Node.h"


LinkedList::LinkedList(){
    head = nullptr;
};

//constructor with array
LinkedList::LinkedList(int* dataStart, int dataSize){
    head = nullptr;
    //iterates through array and inserts them into list
    for(int i = 0; i != dataSize; i++){
        insertNode(*(dataStart + i));
    }
}

//returns value at index
int LinkedList::getIndex(int index){
    //sets first node to iterate through
    Node* currentNode = head;
    //iterates through nodes until index is found
    for(int i = 0; i < index; i++){
        //sets current node to the next node
        currentNode = currentNode->next;
    }
    //returns value of current node
    return currentNode->data;
}

//returns true if list has an index
bool LinkedList::hasIndex(int index){
    //sets first node to iterate through
    Node* currentNode = head;
    //iterates through nodes until index is found
    for(int i = 0; i < index; i++){
        //if next node does not exist return false
        if(!currentNode->next){
            return false;
        };
        //sets current node to the next node
        currentNode = currentNode->next;
    };
    return true;
}


//print out nodes to console
string LinkedList::toString(){
    //instantiates the output string
    string output = "(";
    //if the first node exists iterate through nodes
    if(head){
        //iterate through nodes until the last node
        for(Node* i = head; i; i = i->next){
                output += std::to_string(i->data) + ", ";
        };
        //removes last ", " as there are no more nodes to follow
        output = output.substr(0, output.length() - 2);
    };
    output += ")";
    return output;
}

//add node to back of list
void LinkedList::insertNode(int value){
    //if there is a starting node iterate to end of list then add new node
    if(head){
        //set iterator to starting node
        Node* i = head;
        //iterate through list until at the end
        while(i->next){
            i = i->next;
        };
        //set next node to a new node
        i->next = new Node(value);
    }
    //if starting node is null, create it
    else{
        head = new Node(value);
    };
}

//delete node at given position
void LinkedList::deleteNode(int position){
    //set start of iteration to list head
    Node* currentNode = head;
    //iterate through list until at the node before node to be deleted
    for(int i = 0; i < position - 1; i++){
        //set current node to next node in list
        currentNode = currentNode->next;
    }
    //get node after deleted node
    Node* nodeAfterDeleted = currentNode->next->next;
    //delete node
    delete currentNode->next;
    //set next of current node to the next of the deleted node
    currentNode->next = nodeAfterDeleted;
}

//deconstructor
LinkedList::~LinkedList(){
    delete head;
};
