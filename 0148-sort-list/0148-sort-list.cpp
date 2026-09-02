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

    ListNode* merge(ListNode* a, ListNode* b){

        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;


        while(a != nullptr && b != nullptr){

            if(a -> val < b -> val){

                curr -> next = a;
                a = a-> next;
            }else{

                curr -> next = b;
                b = b-> next;
            }

            curr = curr-> next;
        }


        if(a != nullptr) curr -> next = a;
        
        if(b != nullptr) curr -> next = b;

        return dummy -> next;
    }




    ListNode* sortList(ListNode* head) {

        if(head == nullptr || head -> next == nullptr) return head;

        ListNode* slow = head;
        ListNode* fast = head-> next;

        while(fast != nullptr && fast -> next != nullptr){

            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* second = slow -> next;
        slow -> next = nullptr;

        ListNode* left = sortList(head);
        ListNode* right = sortList(second);

        return merge(left, right);

        


        
    }
};