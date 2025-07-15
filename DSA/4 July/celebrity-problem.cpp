class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n = mat.size();
        vector<int> possibleAns;
        for(int i=0;i<n;i++){
            int flag = -1;
            for(int j=0;j<n;j++){
                if(i != j && mat[i][j] == 1 ){
                    flag = 1;
                    break;
                }
            }
            if(flag == -1) possibleAns.push_back(i);
        }
        if(possibleAns.size() == 0) return -1;
      
        for(auto it : possibleAns){
            int flag = -1;
            for(int i = 0;i<n;i++){
                if(i!=it && mat[i][it] == 0){
                    flag = 1;
                    break;
                }   
            }
            if(flag == -1) return it;
        }
        return -1;
    }
};