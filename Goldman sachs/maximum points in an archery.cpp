// https://leetcode.com/problems/maximum-points-in-an-archery-competition/description/

class Solution {
public:
    void solve(int numArrows, vector<int>& aliceArrows,int i,int bob_score,int& max_score,vector<int> curr,vector<int>& ans){
        if(i==12){
            if(max_score < bob_score){
               ans = curr;
                max_score = bob_score;
                if(numArrows > 0){
                    ans[0]+=numArrows;
                }
            }
          return;
        }
        
        solve(numArrows,aliceArrows,i+1,bob_score,max_score,curr,ans);
        if(numArrows > aliceArrows[i]){
            curr[i] = aliceArrows[i]+1;
            bob_score += i;
            solve(numArrows-aliceArrows[i]-1,aliceArrows,i+1,bob_score,max_score,curr,ans);
        }
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int> ans(12);
        vector<int> curr(12);
        int max_score = INT_MIN;
        solve(numArrows,aliceArrows,0,0,max_score,curr,ans);
        return ans;
    }
};