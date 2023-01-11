//  https://leetcode.com/problems/evaluate-reverse-polish-notation/

#define ll long long
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<ll> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
               
                ll y = st.top();
                st.pop();
                ll x = st.top();
                st.pop();
                if(tokens[i][0]==42){
                    ll ans = x*y;
                    st.push(ans);
                }
                else if(tokens[i][0]==43){
                    ll ans = x+y;
                    st.push(ans);
                }
                else if(tokens[i][0]==45){
                    ll ans = x-y;
                    st.push(ans);
                }
                else{
                    ll ans = x/y;
                    st.push(ans);
                }

            }
            else {
                ll t = stoi(tokens[i]);
                st.push(t);
            }
        }
        return st.top();
    }
};
