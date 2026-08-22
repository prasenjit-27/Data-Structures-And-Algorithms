/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Count total nodes in the linked list
        int length = 0;
        ListNode* curr = head;
        while (curr) {
            length++;
            curr = curr->next;
        }

        // Dummy node to handle edge cases easily (like reversing the first group)
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prevGroupEnd = dummy;
        curr = head;

        // Process groups of size k
        while (length >= k) {
            ListNode* groupStart = curr;
            ListNode* prev = nullptr;
            ListNode* next = nullptr;

            // Reverse k nodes
            for (int i = 0; i < k; ++i) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // Connect the reversed group with the rest of the list
            prevGroupEnd->next = prev;
            groupStart->next = curr;

            // Move prevGroupEnd to the end of the newly reversed group
            prevGroupEnd = groupStart;

            // Decrease length count by k for the processed group
            length -= k;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};