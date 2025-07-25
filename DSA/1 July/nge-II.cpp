class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        stack<int> st;
        
        for(int i=2*n-1;i>=0;i--){
            int index = i%n;
            while(!st.empty() && st.top() <= nums[index]) st.pop();
            if(i < n){
                if(st.empty()) ans[index] = -1;
                else ans[index] = st.top();
            }
            st.push(nums[index]);
        }
        return ans;
    }
};