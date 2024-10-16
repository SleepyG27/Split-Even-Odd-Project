
#include "linkedList.h"
#include "unorderedLinkedList.h"

class intLinkedList : public unorderedLinkedList<int> {
public:
    void splitEvensOddsList(intLinkedList& evensList, intLinkedList& oddsList);
};

void intLinkedList::splitEvensOddsList(intLinkedList& evensList, intLinkedList& oddsList) {
    nodeType<int>* current = this->first;  // Pointer to traverse the original list
    nodeType<int>* evenTail = nullptr;     // Tail of the evensList
    nodeType<int>* oddTail = nullptr;      // Tail of the oddsList

    // Reset the counts for the new lists
    int evensCount = 0;
    int oddsCount = 0;

    // Traverse the original list and move nodes to evensList or oddsList
    while (current != nullptr) {
        nodeType<int>* nextNode = current->link;  // Save the next node
        current->link = nullptr;  // Disconnect the current node from the list

        // Check if the current node contains an even or odd value
        if (current->info % 2 == 0) {
            // Add to the evens list
            if (evensList.first == nullptr) {
                evensList.first = current;
                evenTail = current;
            } else {
                evenTail->link = current;
                evenTail = current;
            }
            evensCount++;  // Increment evens count
        } else {
            // Add to the odds list
            if (oddsList.first == nullptr) {
                oddsList.first = current;
                oddTail = current;
            } else {
                oddTail->link = current;
                oddTail = current;
            }
            oddsCount++;  // Increment odds count
        }

        current = nextNode;  // Move to the next node
    }

    // Update the last pointers and counts for both lists
    if (evenTail != nullptr) {
        evensList.last = evenTail;
    }
    evensList.count = evensCount;  // Update the correct count for evens

    if (oddTail != nullptr) {
        oddsList.last = oddTail;
    }
    oddsList.count = oddsCount;  // Update the correct count for odds

    // Reset the original list
    this->first = nullptr;
    this->last = nullptr;
    this->count = 0;
}
