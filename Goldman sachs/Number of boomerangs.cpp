// https://leetcode.com/problems/number-of-boomerangs/
#define ll long long
class Solution {
public:
    ll distance(vector<int> p1,vector<int> p2){
        int x1 = p1[0];
        int y1 = p1[1];
        int x2 = p2[0];
        int y2 = p2[1];

        int diff_x = abs(x1-x2);
        int diff_y = abs(y1-y2);
        ll sum_diff = (diff_x * diff_x) + (diff_y*diff_y);
        return sum_diff;
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        for(int i=0;i<points.size();i++){
            map<ll,int> mpp;
            for(int j=0;j<points.size();j++){
              int dis = distance(points[i],points[j]);
              mpp[dis]++;
            }
            for(auto x:mpp){
                // cout<<x.first<<" "<<x.second<<endl;
                ans += ((x.second)*(x.second-1));
            }
        }
        return ans;
    }
};