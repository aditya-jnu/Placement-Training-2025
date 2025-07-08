class Solution {
public:
    int calPoints(vector<string>& operations) {
        int ans = 0;
        stack<int> st;
        for(int i=0;i<operations.size();i++){
            if(operations[i] == "+"){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.push(x);
                st.push(x+y);
            }
            else if(operations[i] == "D"){
                int x = st.top();
                st.push(2*x);
            }
            else if(operations[i] == "C"){
                st.pop();
            }
            else{
                st.push( stoi(operations[i]) );
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};