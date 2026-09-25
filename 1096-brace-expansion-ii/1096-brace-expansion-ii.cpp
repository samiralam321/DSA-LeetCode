class Solution {
public:
    set<string> solve(string &s, int &i){
        set<string> ans;
        set<string> cur = {""};

        while(i < s.size() && s[i] != '}'){
            if(s[i] == '{') {
                i++;

                set<string> inside = solve(s, i);
                i++;

                set<string> temp;
                for(string a : cur) {
                    for(string b : inside) {
                        temp.insert(a + b);
                    }
                }
                cur = temp;
            }

            else if(s[i] == ','){
                for(string x : cur){
                    ans.insert(x);
                }
                cur = {""};
                i++;
            }

            else{
                set<string> temp;

                for(string x : cur){
                    x += s[i];
                    temp.insert(x);
                }
                cur = temp;
                i++;
            }
        }

        for(string x : cur){
            ans.insert(x);
        }
        return ans;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> ans = solve(expression, i);
        return vector<string>(ans.begin(), ans.end());
    }
};