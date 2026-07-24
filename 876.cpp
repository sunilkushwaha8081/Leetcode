#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        if (head->next == NULL) {
            return head;
        }

        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }
};

int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution obj;
    ListNode* mid = obj.middleNode(head);

    cout << "Middle Node: " << mid->val << endl;

    // Print from middle node
    cout << "List from middle: ";
    while (mid != NULL) {
        cout << mid->val << " ";
        mid = mid->next;
    }
    cout << endl;

    return 0;
}