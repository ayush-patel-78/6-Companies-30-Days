// https://leetcode.com/problems/perfect-rectangle/description/

#define ll long long 
class Solution {
public:
   bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int>m;
        for(auto P:rectangles)
        {
            m[{P[0],P[1]}]++;//bottom left
            m[{P[2],P[3]}]++;//top right
            m[{P[0],P[3]}]--;//top left
            m[{P[2],P[1]}]--;//bottom right

        }
        int sum=0;
        for(auto it:m)
        {
            sum+=abs(it.second);
        }
        if(sum==4) return true;
        return false;
    }
 
};