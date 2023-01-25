// https://leetcode.com/problems/factorial-trailing-zeroes/description/

class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        int count = 5;
        while(count<=n){
            ans += n/count;
            count = count * 5;
        }
        return ans;
    }
};