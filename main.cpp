#include <iostream>
#include "Problems/problem25.cpp"

using namespace problem25;

void printList(ListNode* head) {
    while (head) {
        std::cout << head->val;
        if (head->next) std::cout << " -> ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create sample input: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* n5 = new ListNode{5, nullptr};
    ListNode* n4 = new ListNode{4, n5};
    ListNode* n3 = new ListNode{3, n4};
    ListNode* n2 = new ListNode{2, n3};
    ListNode* n1 = new ListNode{1, n2};

    int k = 2;
    std::cout << "Original list: ";
    printList(n1);

    ListNode* result = reverseKGroup(n1, k);

    std::cout << "After reverseKGroup with k = " << k << ": ";
    printList(result);

    // Free memory
    while (result) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}