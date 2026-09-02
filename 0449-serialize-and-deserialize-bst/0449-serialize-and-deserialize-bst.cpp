/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    public:

    void seriHelper(TreeNode* root, string &s){
        if(root == NULL) return;

        s += to_string(root->val) + ",";

        seriHelper(root->left, s);
        seriHelper(root->right, s);
    }

    string serialize(TreeNode* root){
        string s;
        seriHelper(root,s);
        return s;
    }

    TreeNode* deseri(vector<int>&nums, int &i, int lo, int hi){
        if(i == nums.size() || nums[i] > hi || nums[i] < lo){
            return NULL;
        }

        TreeNode* root = new TreeNode((nums[i]));
        i++;

        root->left = deseri(nums, i, lo, root->val);
        root->right = deseri(nums, i, root->val, hi);

        return root;
    }

    TreeNode* deserialize(string data){
        if(data == "") return NULL;

        stringstream ss(data);

        string x;
        vector<int> nums;

        while(getline(ss,x, ',')){
            nums.push_back(stoi(x));
        }

        int i = 0;
        return deseri(nums, i, INT_MIN, INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;