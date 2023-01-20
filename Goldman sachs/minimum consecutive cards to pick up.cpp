https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,vector<int>> mpp;
        for(int i=0;i<cards.size();i++){
            mpp[cards[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(auto x:mpp){
            if(x.second.size()>1){
                for(int j=1;j<x.second.size();j++){
                    ans = min(ans,x.second[j]-x.second[j-1]);
                }
            }
        }
        if(ans == INT_MAX) return -1;
        return ans+1;
    }
};