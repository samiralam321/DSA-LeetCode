class Solution {
public:
    int digitSum(int x){
        int sum = 0;

        while(x > 0){
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        vector<int> sorted = nums;

        sort(sorted.begin(), sorted.end(), [&](int a, int b){
            if(digitSum(a) == digitSum(b)) {
                return a < b;
            }
            return digitSum(a) < digitSum(b);
        });

        int n = nums.size();
        int swaps = 0;

        unordered_map<int, int> pos;

        for(int i=0; i<n; i++){
            pos[nums[i]] = i;
        }

        for(int i=0; i<n; i++){
            if(nums[i] == sorted[i]){
                continue;
            }

            int j = pos[sorted[i]];

            pos[nums[i]] = j;
            pos[nums[j]] = i;

            swap(nums[i], nums[j]);
            swaps++;
        }
        return swaps;
    }
};
