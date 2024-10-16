#include <iostream>
#include "intLinkedList.h"

using namespace std;

int main() {
    intLinkedList list;
    intLinkedList evensList;
    intLinkedList oddsList;
    int num;

    cout << "Enter integers ending with -999" << endl;
    cin >> num;

    while (num != -999) {
        list.insertLast(num);
        cin >> num;
    }

    cout << "list: ";
    list.print();  //  print function in linked list

    list.splitEvensOddsList(evensList, oddsList);

    cout << "evensList: ";
    evensList.print();  // Even print function in the linked list

    cout << "oddsList: ";
    oddsList.print();  // Odd print function in the linked list

    return 0;
}
