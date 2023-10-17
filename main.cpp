#include <iostream>

#include "LinkedList.h"

using namespace std;

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
