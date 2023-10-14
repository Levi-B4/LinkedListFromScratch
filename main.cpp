#include <iostream>

using namespace std;

//contains data and a pointer to the next node
class Node{
    public:
        //value and pointer to another node
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
    //pointer to first node of list
    Node* head;

    public:
        //default constructor
        LinkedList(){
            head = NULL;
        };

        //constructor with array
        LinkedList(int* dataStart, int dataSize){
            head = NULL;
            //iterates through array and inserts them into list
            for(int i = 0; i != dataSize; i++){
                insertNode(*(dataStart + i));
            }
        }

        //returns value at index
        int getIndex(int index){
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
        bool hasIndex(int index){
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
        string toString(){
            //instantiates the output string
            string output = "(";
            //if the first node exists iterate through nodes
            if(head){
                //iterate through nodes until the last node
                for(Node* i = head; i; i = i->next){
                        output += to_string(i->data) + ", ";
                };
                //removes last ", " as there are no more nodes to follow
                output = output.substr(0, output.length() - 2);
            };
            output += ")";
            return output;
        }

        //add node to back of list
        void insertNode(int value){
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
        void deleteNode(int position){
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

    private:

};

int main()
{
    //test an empty list
    LinkedList* emptyList = new LinkedList();
    cout << "Empty List: " << emptyList->toString() << endl;

    //test inserting nodes
    emptyList->insertNode(8);
    cout << "Empty List with value added: " << emptyList->toString() << endl;

    emptyList->insertNode(5);
    cout << "Empty List with values added: " << emptyList->toString() << endl;

    //test instantiating list with an array
    int intArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    LinkedList* countToTen = new LinkedList(intArray, sizeof(intArray) / sizeof(int));
    cout << "Count To Ten: " << countToTen->toString() << endl;

    //test deleting nodes
    for(int i = 0; countToTen->hasIndex(i); i++){
        if(countToTen->getIndex(i) % 2 == 0){
            countToTen->deleteNode(i);
        }
    }
    cout << "Count Odd To Ten: " << countToTen->toString() << endl;

    return 0;
}
