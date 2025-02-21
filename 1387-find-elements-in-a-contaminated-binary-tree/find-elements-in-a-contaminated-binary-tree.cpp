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
class FindElements {
private:
    bitset<int(1e6 + 4)> isExists; 
public:
    FindElements(TreeNode* root) {
        
        function<void(TreeNode*, int val)> dfs = [&](TreeNode *node, int val){
            if(val > int(1e6))
                return;

            isExists[val] = true;

            if( node->left != nullptr )
                dfs(node->left, val * 2 + 1);
            if( node->right != nullptr )
                dfs(node->right, val * 2 + 2);
            
        };

        root ? dfs(root, 0) : void();

    }
    
    bool find(int target) {
        return isExists[target];
    }
};


/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */