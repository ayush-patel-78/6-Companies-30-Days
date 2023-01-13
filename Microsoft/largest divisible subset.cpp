// https://leetcode.com/problems/largest-divisible-subset/description/

class Solution {
public:

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> hash(nums.size());
        sort(nums.begin(),nums.end());
        int maxi = 0;
        int last_index = 0;
        vector<int> dp(nums.size()+1,1);
        for(int i=1;i<nums.size();i++){
            hash[i]=i;
            for(int prev = 0;prev<i;prev++){
               if(nums[i]%nums[prev]==0 && dp[i] < 1 +dp[prev]){
                   dp[i] = 1 + dp[prev];
                   hash[i]=prev;
               }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
                last_index = i;
            }
        }
        vector<int> ans;
        ans.push_back(nums[last_index]);
        while(hash[last_index] != last_index){
            last_index = hash[last_index];
            ans.push_back(nums[last_index]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
       
    }
};