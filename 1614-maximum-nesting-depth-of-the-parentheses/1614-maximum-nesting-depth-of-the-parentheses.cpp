class Solution {
public:
    int maxDepth(string s) {
        int maxDepth = 0;
        stack<char> st;

        for(int i=0; i<s.length(); i++){
            if(s[i] == '('){
                st.push(s[i]);
                if(st.size() > maxDepth){
                    maxDepth = st.size();
                }
            }
            else if(s[i] == ')'){
                st.pop();
            }
        }
        return maxDepth;   
    }
};