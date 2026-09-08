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
    ListNode* partition(ListNode* head, int x) {

        if(head == nullptr) return head;

        ListNode* curr = head;
        ListNode* smallDummy = new ListNode(0);
        ListNode* largeDummy = new ListNode(0);

        ListNode* small = smallDummy;
        ListNode* large = largeDummy;

        while(curr != nullptr){

            if(curr -> val < x){

                small -> next = curr;
                small = small -> next;
            }else {

                large -> next = curr;
                large = large -> next;
            }

            curr = curr -> next;
        }

        small -> next = largeDummy -> next;
        large -> next = nullptr;

        return smallDummy -> next;
          
    }
};