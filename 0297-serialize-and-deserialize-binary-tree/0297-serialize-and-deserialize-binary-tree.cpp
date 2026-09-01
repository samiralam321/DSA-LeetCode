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
        if(root == NULL){
            s += "#,";
            return;
        }

        s += to_string(root->val) + ",";

        seriHelper(root->left, s);
        seriHelper(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s;
        seriHelper(root,s);

        return s; 
    }

    TreeNode* build(stringstream& ss){
        string x;

        getline(ss,x, ',');
        if(x == "#"){
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(x));

        root->left = build(ss);
        root->right = build(ss);

        return root;
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return build(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));