/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, vector<TreeNode*>> graph;
    void makeGraph(TreeNode* root, TreeNode* parent){
        if(root == NULL) return;

        if(parent != NULL){
            graph[root].push_back(parent);
            graph[parent].push_back(root);
        }
        makeGraph(root->left, root);
        makeGraph(root->right, root);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        makeGraph(root, NULL);

        vector<int> ans;
        queue<TreeNode*> que;
        que.push(target);

        unordered_map<TreeNode*, bool> visited;
        visited[target] = true;

        int count  = 0;
        while(!que.empty()){
            int n = que.size();
            if(count == k){
                while(n--){
                    TreeNode* curr = que.front();
                    que.pop();
                    ans.push_back(curr->val);
                }
                return ans;
            }
            while(n--){
                TreeNode* curr = que.front();
                que.pop();

                for(TreeNode* next : graph[curr]){
                    if(visited[next] == false){
                        visited[next] = true;
                        que.push(next);
                    }
                }
            }
            count++;
        }
        return ans;  
    }
};