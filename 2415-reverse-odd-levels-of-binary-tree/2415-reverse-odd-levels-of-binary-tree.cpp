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
    TreeNode* bfs(TreeNode* root,int level){
        if(root == NULL) return root;

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            int n = que.size();
            vector<TreeNode*> nodes;

            while(n--){
                TreeNode* node = que.front();
                que.pop();

                nodes.push_back(node);

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }

            if(level % 2 == 1){
                int i = 0;
                int j = nodes.size()-1;

                while(i < j){
                    swap(nodes[i]->val,nodes[j]->val);
                    i++;
                    j--;
                }
            }
            level++;
        }
        return root;
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        return bfs(root,0);
    }
};