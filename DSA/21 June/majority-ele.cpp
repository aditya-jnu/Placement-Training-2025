class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans; int n = nums.size();
        unordered_map<int, int> mpp;
        for(int i=0;i<n;i++) mpp[nums[i]]++;
        for(auto it : mpp){
            if(it.second > n/3) ans.push_back(it.first);
            if(ans.size() == 2) break;
        }
        return ans;
    }
};