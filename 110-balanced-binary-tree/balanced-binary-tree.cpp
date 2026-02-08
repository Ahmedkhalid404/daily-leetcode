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

    bool ans = true;
    int depth(TreeNode* root){
        if(ans == false){
            return 0;
        }
        if(root == nullptr){
            return 0;
        }

        int leftDepth = depth(root->left) + 1;
        int rightDepth = depth(root->right) + 1;

        if(abs(leftDepth-rightDepth) > 1){
            ans = false;
            return 0;
        }

        return max(leftDepth, rightDepth);
    }



    bool isBalanced(TreeNode* root) {
        depth(root);
        return ans;
    }
};