// https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/description/


#define ll long long
class Solution {
public:
    int countNodes(ll n,ll curr){
        ll total = 0;
        ll next = curr + 1;
        while(curr <= n){
            total += min(n - curr + 1,next - curr);
            curr *= 10;
            next *= 10;
        }
        return total;
    }
    int findKthNumber(int n, int k) {
        ll curr = 1;
        k--;

        while(k>0){
            int nodes = countNodes(n,curr);
            if(k >= nodes){
                curr++;
                k -= nodes;
            }
            else{
                curr *= 10;
                k--;
            }
        }
        return curr;
    }

};