class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int len = s.size();
        vector<int> ans;

        for(int i=0; i<len; i++){
            int row = startPos[0];
            int col = startPos[1];
            int count = 0;

            for(int j=i; j<len; j++){
                if(s[j] == 'U') row--;
                else if(s[j] == 'D') row++;
                else if(s[j] == 'L') col--;
                else col++;

                if(row < 0 || row >= n || col < 0 || col >= n){
                    break;
                }
                count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};