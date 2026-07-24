#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x = 0) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};

// Function to print linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // First number: 342 (stored as 2 -> 4 -> 3)
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // Second number: 465 (stored as 5 -> 6 -> 4)
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution obj;
    ListNode* result = obj.addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);

    return 0;
}