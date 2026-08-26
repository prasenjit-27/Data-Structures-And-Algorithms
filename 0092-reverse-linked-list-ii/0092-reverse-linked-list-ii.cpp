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
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(left == right) return head;

        ListNode* dummy = new ListNode(0);

        dummy -> next = head;

        ListNode* prevLeft = dummy;

        for(int i = 1; i<left; i++){

            prevLeft = prevLeft -> next;
        }

        ListNode* curr = prevLeft -> next;

        ListNode* prev = nullptr;

        for(int i = 0; i<= right - left; i++){

            ListNode* next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }

        ListNode* prevRight = prevLeft -> next;
        prevLeft -> next = prev;
        prevRight -> next = curr;

        return dummy -> next;


        
    }
};