#include <iostream>
using namespace std;

// Definition for singly-linked list
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
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect if a cycle exists
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Step 2: Find the starting node of the cycle
                ListNode* ptr = head;
                while (ptr != slow) {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }

        return NULL;
    }
};

int main() {
    // Create nodes
    ListNode* head = new ListNode(3);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(0);
    ListNode* fourth = new ListNode(-4);

    // Link them: 3 -> 2 -> 0 -> -4
    head->next = second;
    second->next = third;
    third->next = fourth;

    // Create cycle: -4 -> 2
    fourth->next = second;

    Solution obj;
    ListNode* cycleStart = obj.detectCycle(head);

    if (cycleStart != NULL)
        cout << "Cycle starts at node with value: " << cycleStart->val << endl;
    else
        cout << "No cycle found." << endl;

    return 0;
}