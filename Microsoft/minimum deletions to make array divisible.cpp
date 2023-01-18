// https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/description/

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int temp = numsDivide[0];
        for(int i = 1 ;i<numsDivide.size();i++){
            temp = __gcd(temp,numsDivide[i]);
        }
        int ans = INT_MAX;
        int ans_index = -1;

        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(temp%nums[i]==0){
                if(nums[i]<ans){
                    ans=nums[i];
                    ans_index = i;
                }
            }
        }
        return ans_index;
    }
};
