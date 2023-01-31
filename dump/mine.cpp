#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    string t;
    cin>>t;
    int n = t.size();
    ll ans = 0;
    string s="";
    int count = 0;
    for(int i=0;i<n;i++){
        if((t[i]-'0') >= 0 && (t[i]-'0')<= 9){
            ans = ans * 10 + (t[i]-'0');
            count++;
            if(count == 10){
                string temp = to_string(ans);
                if(temp.size() == 10){
                    cout<<ans;
                    return 0;
                }
                else{
                    count = 0;
                    ans = 0;
                }
            }
        }
        else{
            count = 0;
            ans = 0;
        }
    }
    cout<<-1;
    return 0;

}