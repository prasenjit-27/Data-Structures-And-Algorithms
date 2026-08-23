class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = next;
            curr = next;
        }
        
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        
        curr = head;
        Node* copyHead = head->next;
        while (curr) {
            Node* copy = curr->next;
            curr->next = copy->next;
            curr = curr->next;
            if (curr) {
                copy->next = curr->next;
            }
        }
        
        return copyHead;
    }
};