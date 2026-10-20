class Solution {
public:
    void computeLPS(vector<int>& pat, vector<int>& lps){
        int m = pat.size();
        int len = 0;
        lps[0] = 0;

        int i = 1;
        while(i < m){
            if(pat[i] == pat[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len != 0){
                    len = lps[len - 1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    bool search(vector<int>& pat, vector<int>& txt){
        int n = txt.size();
        int m = pat.size();

        vector<int> lps(m, 0);
        computeLPS(pat, lps);

        int i = 0, j = 0;

        while(i < n){
            if(pat[j] == txt[i]){
                i++;
                j++;
            }

            if(j == m){
                return true;
            }
            else if(i < n && pat[j] != txt[i]){
                if(j != 0){
                    j = lps[j - 1];
                }
                else{
                    i++;
                }
            }
        }

        return false;
    }

    bool isRotation(vector<int>& a, vector<int>& b){
        vector<int> txt = b;
        txt.insert(txt.end(), b.begin(), b.end());

        return search(a, txt);
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int ans = 0;
        for(int k = 1; k <= n; k++){
            if(n % k != 0){
                continue;
            }

            int valid = 1;
            for(int start = 0; start < n; start += k){
                vector<int> a(nums.begin() + start, nums.begin() + start + k);
                vector<int> b(sorted.begin() + start, sorted.begin() + start + k);

                if(!isRotation(a, b)){
                    valid = 0;
                    break;
                }
            }
            if(valid){
                ans += k;
            }
        }
        return ans;
    }
};