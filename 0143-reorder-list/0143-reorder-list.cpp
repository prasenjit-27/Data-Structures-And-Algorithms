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
    void reorderList(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {

            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* temp = slow-> next;
        slow -> next = nullptr;
        slow = temp;

        ListNode* prev = nullptr;

        while (slow != nullptr) {

            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }



        ListNode* first = head;
        ListNode* second = prev;

        while (second != nullptr) {

            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;

            first->next = second;
            second->next = firstNext;

            first = firstNext;
            second = secondNext;
        }
    }
};