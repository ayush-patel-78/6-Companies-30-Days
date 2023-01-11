// https://leetcode.com/problems/rotate-function/description/

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int rotate = 0;
        int sum_array = 0;
        for(int i=0;i<nums.size();i++){
            sum_array += nums[i];
            rotate += i*nums[i];
        }
        int rotate_max = rotate;
        for(int i=nums.size()-1;i>0;i--){
              rotate += sum_array-(nums.size()*nums[i]);
              if(rotate > rotate_max) rotate_max = rotate;
        }
        return rotate_max;
    }
};