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
    int i = 0;
    TreeNode* solve(string &s, int depth){
        int n = s.size();

        int j = i;
        int dash = 0;

        while(j < n && s[j] == '-'){
            dash++;
            j++;
        }
        if(dash != depth){
            return NULL;
        }
        i = j;
        int num = 0;

        while(i<n && s[i] >= '0' && s[i] <= '9'){
            num = num*10 + (s[i] - '0');
            i++;
        }
        TreeNode* root = new TreeNode(num);

        root->left = solve(s, depth+1);
        root->right = solve(s, depth+1);

        return root;
    }
    
    TreeNode* recoverFromPreorder(string traversal) {
        return solve(traversal, 0); 
    }
};