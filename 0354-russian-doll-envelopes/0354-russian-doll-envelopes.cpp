class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b){
            if(a[0] == b[0]){
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });

        vector<int> lis;

        for(int i=0; i<envelopes.size(); i++){
            int height = envelopes[i][1];

            int pos = lower_bound(lis.begin(), lis.end(), height) - lis.begin();

            if(pos == lis.size()){
                lis.push_back(height);
            }
            else{
                lis[pos] = height;
            }
        }
        return lis.size();
    }
};