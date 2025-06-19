// User function Template for C++

class Solution {
  public:
    int findSingle(vector<int> &arr) {
        // code here
        int ans = 0;
        for(int i=0;i<arr.size();i++){
            ans = ans^arr[i];
        }
        return ans;
    }
};