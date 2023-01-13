// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
       vector<int> ans = nums;
       sort(ans.begin(),ans.end());
       int k = 0;
       bool check = true;
       int l=0;
       for(int i=0;i<ans.size();i++){
           if(nums[i] != ans[i]){
               if(check) k=i;
               l=i+1;
               check =false;
           }
       }
       return l-k;
    }
};