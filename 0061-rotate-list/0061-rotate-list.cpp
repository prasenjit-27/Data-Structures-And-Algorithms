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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == nullptr || head -> next == nullptr || k == 0) return head;

        ListNode* curr = head;

        int length = 1;

        while(curr -> next != nullptr){

            curr = curr -> next;
            length++;
        }


        k %= length;

        if(k == 0) return head;
        curr -> next = head;
        curr = head;

        int steps = length - k;

        

        for(int i = 1; i< steps; i++){

            curr = curr -> next;

        }

        ListNode* newHead = curr -> next;
        curr -> next = nullptr;

        return newHead;
        
    }
};