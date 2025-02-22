class Solution {
public:
    TreeNode* recoverFromPreorder(string &s) {
        vector<pair<int, int>> tree
        ;
        int n = int(s.size());
        int d = 0;

        for(int i = 0; i < n; i ++){
            if( s[i] == '-' )
                d ++;
            else{
                int num = 0;
                while( i < n and s[i] != '-' )
                    num = num * 10 + s[i] - '0', i++;
                i --;
                tree.push_back({d, num}) , d = 0;
            }

        }

        TreeNode* root = new TreeNode(tree[0].second);

        int idx = 1;
        function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int currdepth){

            while((idx < tree.size()) and (currdepth == tree[idx].first) and (node->val == 0) ){
                node->val = tree[idx].second;
                idx ++ ;
            }

            while((idx < tree.size()) and (tree[idx].first > currdepth) ){

                if( node->left == nullptr ){
                    node->left = new TreeNode();
                    dfs(node->left, currdepth + 1);
                }
                else if(node->right == nullptr){
                    node->right = new TreeNode();
                    dfs(node->right, currdepth + 1);
                }
            }
        };
        dfs(root, 0);
        return root;
    }
};
