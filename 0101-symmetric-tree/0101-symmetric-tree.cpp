/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool isChecker(TreeNode* a, TreeNode* b){

        if(a == nullptr && b == nullptr) return true;
        if(a == nullptr || b == nullptr) return false;

        if(a -> val != b-> val) return false;

        bool m = isChecker(a-> left, b-> right);
        bool n = isChecker(a-> right, b-> left);

        return m && n;
    }
    bool isSymmetric(TreeNode* root) {

        return isChecker(root->left, root->right);


        
    }
};