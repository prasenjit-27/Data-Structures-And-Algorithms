class Solution {
public:
    Node* connect(Node* root) {
        Node* head = root;
        while (head != nullptr) {
            Node dummy(0);
            Node* tail = &dummy;
            Node* curr = head;
            
            while (curr != nullptr) {
                if (curr->left != nullptr) {
                    tail->next = curr->left;
                    tail = tail->next;
                }
                if (curr->right != nullptr) {
                    tail->next = curr->right;
                    tail = tail->next;
                }
                curr = curr->next;
            }
            
            head = dummy.next;
        }
        return root;
    }
};