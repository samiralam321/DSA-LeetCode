class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& arr, int firstLen, int secondLen) {
        int n = arr.size();
        int ans = 0;

        vector<int> best(n,0);

        int i = 0;
        int j = 0;
        int sum = 0;
        int mx = 0;

        while(j < n){
            sum += arr[j];
            if(j-i+1 == firstLen){
                mx = max(mx,sum);
                best[j] = mx;
                sum -= arr[i];
                i++;
            }
            j++;
        }

        i = 0;
        j = 0;
        sum = 0;

        while(j < n){
            sum += arr[j];
            if(j-i+1 == secondLen){
                if(i > 0){
                    ans = max(ans,sum + best[i-1]);
                }
                sum -= arr[i];
                i++;
            }
            j++;
        }

        i = 0;
        j = 0;
        sum = 0;
        mx = 0;

        while(j < n){
            sum += arr[j];
            if(j-i+1 == secondLen){
                mx = max(mx,sum);
                best[j] = mx;
                sum -= arr[i];
                i++;
            }
            j++;
        }

        i = 0;
        j = 0;
        sum = 0;

        while(j < n){
            sum += arr[j];
            if(j-i+1 == firstLen){
                if(i > 0){
                    ans = max(ans,sum + best[i-1]);
                }
                sum -= arr[i];
                i++;
            }
            j++;
        }
        return ans;
    }
};