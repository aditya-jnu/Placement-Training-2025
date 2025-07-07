class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st; int ans = 0;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i] == "+"){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push( x + y );
            }
            else if(tokens[i] == "-"){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push( y - x );
            }
            else if(tokens[i] == "*"){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push( x * y );
            }
            else if(tokens[i] == "/"){
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                st.push( y / x );
            }
            else st.push( stoi(tokens[i]));
        }
        return st.top();
    }
};