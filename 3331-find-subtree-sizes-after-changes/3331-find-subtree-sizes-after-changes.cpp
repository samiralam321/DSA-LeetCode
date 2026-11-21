class Solution {
public:
    vector<vector<int>> adj, tree;
    vector<int> newParent, lastSeen, ans;

    void dfs(int u){
        int c = s[u] - 'a';
        int old = lastSeen[c];

        if(u != 0){
            newParent[u] = (old != -1) ? old : parent[u];
        }

        lastSeen[c] = u;

        for(int v : adj[u]){
            dfs(v);
        }
        lastSeen[c] = old;
    }

    int calculate(int u){
        int sz = 1;
        for(int v : tree[u]){
            sz += calculate(v);
        }
        
        return ans[u] = sz;
    }

    vector<int> parent;
    string s;

    vector<int> findSubtreeSizes(vector<int>& p, string str) {
        parent = p;
        s = str;

        int n = p.size();

        adj.resize(n);
        tree.resize(n);
        newParent.assign(n, -1);
        lastSeen.assign(26, -1);
        ans.assign(n, 1);

        for(int i = 1; i < n; i++){
            adj[parent[i]].push_back(i);
        }
        dfs(0);
        for(int i = 1; i < n; i++){
            tree[newParent[i]].push_back(i);
        }
        calculate(0);
        return ans;
    }
};