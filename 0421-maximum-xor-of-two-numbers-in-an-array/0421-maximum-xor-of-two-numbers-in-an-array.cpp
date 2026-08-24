class Solution {
private:
    struct TrieNode {
        TrieNode* children[2] = {nullptr, nullptr};
    };

    void insert(TrieNode* root, int num) {
        TrieNode* curr = root;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            if (!curr->children[bit]) {
                curr->children[bit] = new TrieNode();
            }
            curr = curr->children[bit];
        }
    }

    int getMax(TrieNode* root, int num) {
        TrieNode* curr = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; --i) {
            int bit = (num >> i) & 1;
            int oppositeBit = 1 - bit;
            if (curr->children[oppositeBit]) {
                maxNum |= (1 << i);
                curr = curr->children[oppositeBit];
            } else {
                curr = curr->children[bit];
            }
        }
        return maxNum;
    }

public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        for (int num : nums) {
            insert(root, num);
        }
        int maxXor = 0;
        for (int num : nums) {
            maxXor = max(maxXor, getMax(root, num));
        }
        return maxXor;
    }
};