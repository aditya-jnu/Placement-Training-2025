class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ind = 0, ans = 0;
        for(int i=0;i<g.size();i++){
            if(ind >= s.size()) break;
            while(ind < s.size()){
                if(s[ind] >= g[i]){
                    ans++;
                    ind++;
                    break;
                }
                ind++;
           }
        }
        return ans;
    }
};