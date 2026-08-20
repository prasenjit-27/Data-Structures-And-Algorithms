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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int val = 0;

        ListNode* temp = head;

        while (temp) {

            val++;
            temp = temp->next;
        }

        int fin = val - n;

        if (fin == 0)
            return head->next;

        temp = head;

        for (int i = 0; i < fin - 1; i++) {

            temp = temp->next;
        }

        temp->next = temp->next->next;

        return head;
    }
};