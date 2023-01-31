#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<string> print_string(int i,int j,int a,int b){
    string s ="";
    for(int k=0;k<i;k++){
        s += to_string(a);
    }
    for(int k=0;k<j;k++){
        s += to_string(b);
    }
    vector<string> ans;
    // print all permutations of s 
    sort(s.begin(),s.end());
    do{
        ans.push_back(s);
    }while(next_permutation(s.begin(),s.end()));
    return ans;

}
ll calc_perm(int half,int i){
    ll ans =  1;
    int x = i;
    int y = half - i;
    int maxi = max(x,y);
    for(int k=half;k>maxi;k--){
        ans *= k;
    }
    int mini = min(x,y);
    for(int k=mini;k>1;k--){
        ans /= k;
    }
    return ans;
}
int main(){
    int a,b;
    cin>>a>>b;
    int mini = min(a,b);
    int maxi = max(a,b);
    a = mini;
    b = maxi;
    int n;
    cin>>n;
    int half = n/2;
    ll perm = 0;
    // vector<string> ans;
    vector<string> ans1;
    for(int i=0;i<=half;i++){
        ll temp = calc_perm(half,i);
        perm += temp*temp;
        vector<string> ans = print_string(i,half-i,a,b);
        for(int i=ans.size()-1;i>=0;i--){
            for(int j=0;j<ans.size();j++){
                string temp = ans[i] + ans[j] ;
                ans1.push_back(temp);
            }
        }

    }
    reverse(ans1.begin(),ans1.end());

    for(auto x:ans1){
        cout<<x<<endl;
    }
    cout<<perm;
    return 0;
}