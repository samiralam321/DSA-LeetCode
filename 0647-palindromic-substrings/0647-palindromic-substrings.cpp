class Solution {
public:
    bool check(int i, int j, string&s){
        if(i>j) return true;

        if(s[i] == s[j]){
            return check(i+1, j-1, s);
        }
        return false;
    }
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;

        // find all substrings
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(check(i,j,s)){
                    count++;
                }
            }
        }
        return count;  
    }
};

