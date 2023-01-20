// https://leetcode.com/problems/max-points-on-a-line/

class Solution {
public:
    double slope(int& x1,int& x2,int& y1,int& y2){
        double diffx = x2 - x1;
        double diffy = y2 - y1;
        if(diffy == 0) return 1000000;
        double m = diffx/diffy;
        return m;
    }
    int maxPoints(vector<vector<int>>& points) {
        map<vector<int>,int> mpp;

        for(int i=0;i<points.size();i++){
            map<double,int> mpp2;
            for(int j=0;j<points.size();j++){
                if(i==j) continue;
                int x1,x2,y1,y2;
                x1 = points[i][0];
                y1 = points[i][1];
                x2 = points[j][0];
                y2 = points[j][1];
                double m = slope(x1,x2,y1,y2);
                cout<<m<<endl;
                mpp2[m]++;
            }
            int max_times_occurs_slope = 0;
            for(auto x:mpp2){
                if(x.second > max_times_occurs_slope){
                    max_times_occurs_slope = x.second;
                }
            }
            mpp[points[i]]=max_times_occurs_slope;
        }
        int ans = 0;
        for(auto x:mpp){
            if(x.second > ans){
                ans = x.second;
            }
        }
        return ans+1;
    }
};