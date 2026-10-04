class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> parts;

        int open = 0;
        int close = 0;
        int start = 0;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '1') open++;
            else close ++;

            if(open == close){
                string inside = s.substr(start+1, i-start-1);

                string part = "1" + makeLargestSpecial(inside) + "0";

                parts.push_back(part);
                start = i+1;
            }
        }
        sort(parts.rbegin(),parts.rend());

        string ans = "";
        for(string part : parts) {
            ans += part;
        }
        return ans;
    }
};