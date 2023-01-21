// https://leetcode.com/problems/ipo/description/

class Solution {
public:
    bool static comparator(pair<int,int>& p1,pair<int,int>& p2){
        if(p1.second == p2.second){
            return p1.first > p2.first;
        }
        return p1.second < p2.second;
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>> p;
        for(int i=0;i<profits.size();i++){
            p.push_back({profits[i],capital[i]});
        }   
        sort(p.begin(),p.end(),comparator);
        priority_queue<pair<int,int>> pq;
        int i=0;
        while(i<p.size() && w >= p[i].second ){
            pq.push(p[i]);
            i++;
        }

        while(!pq.empty() && k>0){
            int profit = pq.top().first;
            w += profit;
            pq.pop();
            k--;
            while(i<p.size() && w >= p[i].second){
                pq.push(p[i]);
                i++;
            }
        }
        return w;  
        
    }
};