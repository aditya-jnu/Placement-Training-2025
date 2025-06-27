class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int s = 0, e = 0, n = nums.size(), sum = nums[0];
        int ans = INT_MAX;
        while(e < n){
            if(sum >= target) {
                if(e-s+1 < ans) ans = e-s+1;
                sum -= nums[s];
                s++;
            }
            else{
                e++;
                if(e<n) sum += nums[e];
            }
        }
        if(ans == INT_MAX) return 0;
        return ans;
    }
};