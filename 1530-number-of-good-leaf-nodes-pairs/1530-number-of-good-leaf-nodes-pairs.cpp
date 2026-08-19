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
    
    vector<int> solve(TreeNode* root, int distance, int& goodLeafNodes){
        if(root == NULL) return {0};

        if(root->left == NULL && root->right == NULL){
            return {1};
        }

        vector<int> left_d = solve(root->left, distance, goodLeafNodes);
        vector<int> right_d = solve(root->right, distance, goodLeafNodes);

        for(int &l : left_d){
            for(int &r : right_d){
                if((l != 0 && r != 0) && l+r <= distance){
                    goodLeafNodes++;
                }
            }
        }

        vector<int> curr_d;

        for(int &ld : left_d){
            if(ld != 0 && ld+1 <= distance){
                curr_d.push_back(ld+1);
            }
        }

        for(int &rd : right_d){
            if(rd != 0 && rd+1 <= distance){
                curr_d.push_back(rd+1);
            }
        }
        return curr_d;
    }

    int countPairs(TreeNode* root, int distance) {
        int goodLeafNodes = 0;

        solve(root, distance, goodLeafNodes);
        return goodLeafNodes;
        
    }
};