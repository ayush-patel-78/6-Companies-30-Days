// https://leetcode.com/problems/number-of-pairs-satisfying-inequality/description/

class Solution {
public:

    long long merge_sort(vector<int>& nums,int l,int r,int& diff){
        if(l==r) return 0;
        int mid = l + (r-l)/2;
        long long ans = 0;
        ans += merge_sort(nums,l,mid,diff);
        ans += merge_sort(nums,mid+1,r,diff);
        auto it = nums.begin();
        for(int i=mid+1;i<=r;i++){
            auto upper = upper_bound(it+l,it+mid+1,nums[i]+diff);
            ans += upper - (it+l);
        }
        sort(it+l,it+r+1);
        return ans;
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        vector<int> nums;
        for(int i=0;i<nums1.size();i++){
            nums.push_back(nums1[i]-nums2[i]);
        }
        return merge_sort(nums,0,nums.size()-1,diff);

    }
};