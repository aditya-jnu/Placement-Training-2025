class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> geInR(n, -1);
        vector<int> geInL(n, -1);
        int ans = 0;

        //geInR
        int tempMax = -1;
        for(int i=n-1;i>=0;i--){
           if(height[i] >= tempMax) geInR[i] = -1;
           else geInR[i] = tempMax;
           tempMax = max(tempMax, height[i]);
        }
        // cout<<"GE IN R "<<endl;
        // for(int i=0;i<geInR.size();i++){
        //     cout<<geInR[i]<<" ";
        // }
        // cout<<endl;

        //geInL
        tempMax = -1;
        for(int i=0;i<n;i++){
            if(height[i] >= tempMax) geInL[i] = -1;
            else geInL[i] = tempMax;
            tempMax = max(height[i], tempMax);
        }
        // cout<<"GE IN L "<<endl;
        // for(int i=0;i<geInL.size();i++){
        //     cout<<geInL[i]<<" ";
        // }
        // cout<<endl;

        for(int i=0;i<n;i++){
            if(geInL[i] == -1 || geInR[i] == -1) continue;
            else {
                ans += abs(min(geInL[i],geInR[i]) - height[i]);
            }
        }
        return ans;
    }
};