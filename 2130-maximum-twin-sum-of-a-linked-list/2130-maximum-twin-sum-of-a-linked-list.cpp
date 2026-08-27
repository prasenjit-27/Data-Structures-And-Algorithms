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
    int pairSum(ListNode* head) {

        ListNode* temp = head;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!= nullptr && fast -> next != nullptr){

            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* prev = nullptr;

        while(slow != nullptr){

            ListNode* next = slow -> next;
            slow -> next = prev;
            prev = slow;
            slow = next;
        }

        int maxi = INT_MIN;

        while(prev != nullptr){

            maxi = max(maxi, head -> val + prev -> val);
            head = head -> next;
            prev = prev -> next;

            
        }

        return maxi;


        
    }
};