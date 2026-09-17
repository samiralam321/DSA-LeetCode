class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int INF = 1e9;

        vector<int> best(n, INF);

        int i = 0;
        int j = 0;
        int sum = 0;

        int minLen = INF;
        int ans = INF;

        while(j<n){
            sum += arr[j];
            while(sum > target){
                sum -= arr[i];
                i++;
            }
            if(sum == target){
                int len = j-i+1;

                if(i > 0 && best[i-1] != INF){
                    ans = min(ans, len + best[i-1]);
                }
                minLen = min(minLen, len);
            }
            best[j] = minLen;
            j++;
        }
        if(ans == INF) return -1;
        return ans;
    }
};