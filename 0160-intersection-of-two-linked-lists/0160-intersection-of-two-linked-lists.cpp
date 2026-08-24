/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        int lenA = 0, lenB = 0;

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while (temp1) {
            lenA++;
            temp1 = temp1->next;
        }
        while (temp2) {
            lenB++;
            temp2 = temp2->next;
        }

        while (lenA > lenB) {

            headA = headA->next;
            lenA--;
        }

        while (lenB > lenA) {

            headB = headB->next;
            lenB--;
        }

        while(headA != headB){

            headA = headA->next;
            headB = headB-> next;
        }

        return headA;
    }
};