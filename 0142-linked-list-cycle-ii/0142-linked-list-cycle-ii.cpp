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
    ListNode *detectCycle(ListNode *head) {
        
        if(head == nullptr || head -> next == nullptr) return nullptr;

        ListNode* temp = head;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast -> next != nullptr){

            slow = slow -> next;
            fast = fast -> next -> next;

            if(slow == fast){

                fast = head;

                while(fast != slow){

                    slow = slow -> next;
                    fast = fast -> next;
                }

                return fast;
            }
        }

        return nullptr;

        
    }
};