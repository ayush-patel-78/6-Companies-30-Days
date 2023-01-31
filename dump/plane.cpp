// A cargo plane is going from country to country to deliver grains . 
// The air route is unidirectional, and the countries are numbered from 1 to N along the way . 
// A country i produces Pi tonnes of grains , but no more than Si tonnes of grains can be distributed to the citizens in a country i.
// for each pair of countries (i,j), where i<j, the plane is instructed not to deliver more than once to that country.
// It is instructed that a plane cannot deliver more than X tonnes of grains from country i to country j.
// The plane can deliver the grains in any order, but grains can only be produced from a country with a lower index to a country with a higher index.

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> p(n);
    vector<int> s(n);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    vector<ll> grains(n);
    ll extra = 0;
    for(int i=0;i<n;i++){
        p[i] += extra;
        grains[i] = min(p[i],s[i]);
        if(p[i] > s[i]){
            extra = p[i] - grains[i];
            if(extra > x){
                extra = x;
            }

        }
        else{
            extra = 0;
        }
        
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        ans += grains[i];
    }
    cout<<ans<<endl;
    return 0;
}

