// https://leetcode.com/problems/maximum-matrix-sum/description/

#define ll long long
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        ll sum=0;
        ll n = matrix.size();
        ll min_pos_ele = INT_MAX;
        ll count_negative = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] < 0){
                    count_negative++;  
                }
                sum += abs(matrix[i][j]);
                if(abs(matrix[i][j]) < min_pos_ele){
                      min_pos_ele = abs(matrix[i][j]);
                }
            }
        }
        if(count_negative % 2==1) sum -= 2*min_pos_ele;
        return sum;
    }
};