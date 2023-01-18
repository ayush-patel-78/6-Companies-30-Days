// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

#define ll long long
class Solution {
public:
   
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<ll,ll>>> adjList(n);
        for(auto x:roads){
            adjList[x[0]].push_back({x[1],x[2]});
            adjList[x[1]].push_back({x[0],x[2]});
        }        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        vector<ll> dist(n,10000000000000),ways(n,0);
        ways[0]=1;
        dist[0]=0;
        ll mod = 1e9 + 7;
        pq.push({0,0});
        while(!pq.empty()){
            ll dis = pq.top().first;
            ll node = pq.top().second;
            pq.pop();
            for(auto x:adjList[node]){
                if(x.second + dis < dist[x.first]){
                    dist[x.first] = x.second + dis;
                    ways[x.first] = ways[node];
                    pq.push({dist[x.first],x.first});
                }
                else if(x.second + dis == dist[x.first]){
                    ways[x.first] = (ways[x.first]+ ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;

    }
};