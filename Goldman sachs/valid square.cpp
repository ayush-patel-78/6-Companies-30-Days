// https://leetcode.com/problems/valid-square/description/

#define ll long long
class Solution {
public:
    ll distance(vector<int> p1,vector<int> p2){
        return (abs(p1[0]-p2[0])*abs(p1[0]-p2[0]))+(abs(p1[1]-p2[1])*abs(p1[1]-p2[1]));

    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if(p1==p2 || p1==p3 || p1==p4 || p2==p3 || p2==p4 || p3==p4) return false;
        unordered_map<ll,ll> mpp;
        mpp[distance(p1,p2)]++;
        mpp[distance(p2,p3)]++;
        mpp[distance(p3,p4)]++;
        mpp[distance(p4,p1)]++;
        mpp[distance(p1,p3)]++;
        mpp[distance(p2,p4)]++;
    
        if(mpp.size()==2 || mpp.size()==1){
             return true;
        }
        return false;
    }
};