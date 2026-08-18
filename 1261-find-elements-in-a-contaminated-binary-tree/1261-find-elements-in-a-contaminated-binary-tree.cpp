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
public:
    unordered_set<int> st;
    void DFS(TreeNode* root, int rootVal){
        if(root == NULL) return;

        root->val = rootVal;
        st.insert(rootVal);

        DFS(root->left, 2*rootVal + 1);
        DFS(root->right, 2*rootVal + 2);
    }

    FindElements(TreeNode* root) {
        st.clear();
        DFS(root,0);
        
    }
    
    bool find(int target) {
        return st.count(target);   
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */