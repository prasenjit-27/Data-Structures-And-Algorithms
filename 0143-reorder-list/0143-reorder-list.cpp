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

        ListNode* curr = head;

        vector<ListNode*> store;

        while(curr != nullptr){

            store.push_back(curr);
            curr = curr-> next;


        }

        int n = store.size();

        int left = 0;
        int right = n-1;

        while(left < right){

            store[left] -> next = store[right];
            left++;

            if(left == right){

                
                break;
            }

            store[right] -> next = store[left];
            right--;
        }

        store[left] -> next = nullptr;
        
    }
};