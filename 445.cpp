#include <iostream>
#include <stack>
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
        stack<int> s1, s2;

        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }

        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        ListNode* head = NULL;

        while (!s1.empty() || !s2.empty() || carry) {
            int sum = carry;

            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }

            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }

            ListNode* node = new ListNode(sum % 10);
            node->next = head;
            head = node;

            carry = sum / 10;
        }

        return head;
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Number 7243
    ListNode* l1 = new ListNode(7);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);
    l1->next->next->next = new ListNode(3);

    // Number 564
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution obj;
    ListNode* result = obj.addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);

    return 0;
}