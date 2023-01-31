// https://leetcode.com/problems/number-of-people-aware-of-a-secret/

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> days(2001,0);
        days[0]=1;
        int mod = 1e9 + 7;
        for(int i=0;i<n;i++){
            for(int j=i+delay;j<i+forget;j++){
                days[j] += days[i];
                days[j] %= mod;
            }
        }
        long long ans = 0;
        n--;
        int count = 0;
        while(count<forget){
            ans += days[n];
            ans %= mod;
            n--;
            count++;
        }
        return ans;
    }
};