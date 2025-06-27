class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int maxAns = INT_MIN, n = customers.size();
        
        int alwaysSatisfied = 0;
        for(int i = 0; i < n; i++){
            if(grumpy[i] == 0) alwaysSatisfied += customers[i];
        }

        int tempSatisfied = INT_MIN;
        int s = 0, e = minutes-1, temp = 0;
        for(int i = s; i<=e; i++){
            if(grumpy[i] == 1) temp += customers[i];
        }
        if(temp > tempSatisfied) tempSatisfied = temp;
        while(e < n-1){
           if(grumpy[s] == 1) temp -= customers[s];
           
           if(grumpy[e+1] == 1) temp += customers[e+1];
           
           if(temp > tempSatisfied) tempSatisfied = temp;
           e++; s++;
        }
        return alwaysSatisfied+tempSatisfied;
    }
};