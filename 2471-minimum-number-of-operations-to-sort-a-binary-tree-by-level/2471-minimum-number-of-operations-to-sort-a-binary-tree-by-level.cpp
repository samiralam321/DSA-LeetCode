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
    int minSwaps(vector<int>& arr){
       vector<int> sorted=arr;

       sort(sorted.begin(), sorted.end());

       unordered_map<int,int> mp;

       for(int i=0; i<arr.size(); i++){
           mp[arr[i]] = i;
       }

       int swaps = 0;

       for(int i=0; i<arr.size(); i++){
           if(arr[i] == sorted[i]){
               continue;
           }

           int j = mp[sorted[i]];
           swap(arr[i], arr[j]);

           mp[arr[j]] = j;
           mp[arr[i]] = i;

           swaps++;
       }
       return swaps;
       
    }
    int minimumOperations(TreeNode* root) {
        int ans = 0;

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            int n = que.size();
            vector<int> arr;

            while(n--){
                TreeNode* temp = que.front();
                que.pop();

                arr.push_back(temp->val);

                if(temp->left){
                    que.push(temp->left);
                }
                if(temp->right){
                    que.push(temp->right);
                }
            }
            ans += minSwaps(arr);
        }
        return ans;
    }
};