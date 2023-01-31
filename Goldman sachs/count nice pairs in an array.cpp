// https://leetcode.com/problems/count-nice-pairs-in-an-array/description/


class Solution {
public:
    int rev(int num){
        int reverse_num = 0;
        while(num > 0){
            reverse_num = reverse_num*10 + num%10;
            num = num/10;
        }
        return reverse_num;
    }
    int countNicePairs(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i] = nums[i]-rev(nums[i]);
        }
        unordered_map<int,int> mpp;
        int mod = 1e9 + 7;
        int ans = 0;
        for(int j=nums.size()-1;j>=0;j--){
              ans += mpp[nums[j]];
              mpp[nums[j]]++;
              ans = ans%mod;
        }
        return ans;
    }
};
