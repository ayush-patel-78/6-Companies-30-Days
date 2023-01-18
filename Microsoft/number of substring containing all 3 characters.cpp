// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

class Solution {
public:
    bool isValid(unordered_map<char,int> & mpp){
        for(auto it:mpp){
            if(it.second == 0) return false;
        }
        return true;
    }
    int numberOfSubstrings(string s) {
        unordered_map<char,int>mpp;
        mpp['a']=0;
        mpp['b'] = 0;
        mpp['c'] = 0;
        
        int i = 0,j = 0;
        int ans = 0;
        
        int back_length = 0;
        int front_length = 0;
      
        while(j < s.size()){
            mpp[s[j]]++;
            if(isValid(mpp)){
                back_length = s.size()-j;
                front_length = 0;
                while(isValid(mpp)){
                    mpp[s[i]]--;
                    i++;
                    front_length++;
                }
                ans += back_length * front_length;
            }
            j++;
        }
        return ans;
    }
};