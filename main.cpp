#include <iostream>

using namespace std;

//contains data and a pointer to the next node
class Node{
    public:
        int data;
        Node* next;


        //default constructor
        Node(){
            data = 0;
            next = NULL;
        }
        //constructor with data
        Node(int data){
            this->data = data;
            next = NULL;
        }

    private:
};

class LinkedList{

    Node* head;

    public:
        LinkedList(){
            head = NULL;
        };

        LinkedList(int data[]){
            head = new Node(data[0]);
            int sizeOfArr = sizeof(data) / sizeof(int);
            for(int i = 1; i < sizeOfArr; i++){
                insertNode(data[i]);
            }
        }

        //print out nodes to console
        void print(){

        }

        //add node to back of list
        void insertNode(int value){

        }

        //delete node at given position
        void deleteNode(int position){

        }

    private:

};

int main()
{

    LinkedList myList();

    return 0;
}
