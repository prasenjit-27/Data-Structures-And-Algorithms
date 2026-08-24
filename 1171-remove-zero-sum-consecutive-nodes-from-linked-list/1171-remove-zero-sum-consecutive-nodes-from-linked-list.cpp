class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        unordered_map<int, ListNode*> prefixMap;
        
        int prefixSum = 0;
        for (ListNode* curr = dummy; curr != nullptr; curr = curr->next) {
            prefixSum += curr->val;
            prefixMap[prefixSum] = curr;
        }
        
        prefixSum = 0;
        for (ListNode* curr = dummy; curr != nullptr; curr = curr->next) {
            prefixSum += curr->val;
            curr->next = prefixMap[prefixSum]->next;
        }
        
        return dummy->next;
    }
};