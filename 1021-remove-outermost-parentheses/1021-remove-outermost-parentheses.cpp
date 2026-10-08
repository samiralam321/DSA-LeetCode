class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        stack<char> st;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                if(!st.empty()){
                    ans += s[i];
                }
                st.push('(');
            }
            else{ 
                st.pop();
                if(!st.empty()){
                    ans += s[i];
                }
            }
        }
        return ans;
    }
};