class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(), carry = 1;
        stack<int> st; vector<int> ans;
        for(int i=n-1;i>=0;i--){
            int temp = digits[i] + carry;
            if(temp == 10){
                st.push(0);
                carry = 1;
            }
            else{
                st.push(temp);
                carry = 0;
            }
        }
        if(carry == 1) st.push(1);
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;

    }
};