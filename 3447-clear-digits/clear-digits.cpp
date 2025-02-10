class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(auto c:s){
            if(c >= '0' && c<= '9'){
                st.pop();
            }
            else{
                st.push(c);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};