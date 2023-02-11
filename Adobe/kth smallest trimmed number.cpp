// https://leetcode.com/problems/query-kth-smallest-trimmed-number/

class Solution {
public:
    int trim(vector<string>& nums,int k,int t){
        priority_queue<pair<string,int>> pq;
        
        for(int i=0;i<nums.size();i++){
            string num = nums[i].substr(nums[i].size()-t);
            pq.push({num,i});
            if(pq.size()>k) pq.pop();
        }
        return pq.top().second;
    }
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int k = queries[i][0];
            int t = queries[i][1];
            ans.push_back(trim(nums,k,t));
        }
        return ans;
    }
};