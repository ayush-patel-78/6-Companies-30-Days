// Andrew owns a large city with N houses connected using two-way roads. Each city has a name denoted by string . 
// Any house is reachable from any other houses using some number of roads . 
// In other words, the city denotes a connected undirected tree in the form of nodes and edges .
// He takes his walk by starting at any city , following its adjacent cities, which are not visited until he decides to stop at any arbitary city .
// This results in forming his walk as a path in the given tree he collects all the city names in the order of their visits and stores them in his notebook. 
// Ben gives him a string S and challenges him to discover a walk such that the string generated in his notebook equals S.

// Andrew is a lazy person and he wants to know the number of walks that satisfy the above condition.

#include <bits/stdc++.h>

using namespace std;

void dfs(int v,vector<vector<int>>& adj,vector<int>& vis,vector<string>& cities,string s,int index,string curr,int& ans){
    if(curr==s){
        ans++;
        return;
    }
    int it = index;
    for(int i=0;i<adj[v].size();i++){
        if(vis[adj[v][i]]==0){
            vis[adj[v][i]]=1;
            string temp = cities[adj[v][i]];
            bool check = true;
            for(int x=0;x<cities[adj[v][i]].size();x++,it++){
                if(cities[adj[v][i]][x]!=s[it]){
                    check = false;
                }
                else{
                    it=index;
                    break;
                } 
            }
            if(check){
                string hehe = curr;
                curr += cities[adj[v][i]];
                dfs(adj[v][i],adj,vis,cities,s,it,curr,ans);
                curr = hehe;
                
            }
            vis[adj[v][i]]=0;
        }
    }
}
int findPaths(int N,vector<vector<int>>& edges,vector<string>& cities,string s){
    
    vector<vector<int>> adj(N);
    for(auto edge:edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    vector<int> vis(N,0);
    int it = 0;
    int ans = 0;
    bool check = true;
    string curr ="";
    for(int i=0;i<N;i++){
        string temp = cities[i];
        for(int x=0;x<cities[i].size();x++,it++){
            if(cities[i][x]!=s[it]){
                check = false;
            }
            else{
                it=0;
                break;
            } 
        }
        if(check){
            curr += cities[i];
            vis[i]=1;
            dfs(i,adj,vis,cities,s,it,curr,ans);
            vis[i]=0; 
        }
        check = true;
        
    }
    return ans;
}