// https://leetcode.com/problems/bulls-and-cows/description/

class Solution {
public:
    string getHint(string secret, string guess) {
        map<char,int> secret_mpp;
        map<char,int> guess_mpp;

        int bulls = 0;
        for(int i=0;i<secret.size();i++){
            secret_mpp[secret[i]]++;
            if(secret[i]==guess[i]) bulls++;
        }

        int count = 0;
        for(int i=0;i<guess.size();i++){
            if((secret_mpp.find(guess[i])!=secret_mpp.end()) && (secret_mpp[guess[i]] > guess_mpp[guess[i]])){
                count++;
                guess_mpp[guess[i]]++;
            }
        }
        int cows = count - bulls;
        string ans = to_string(bulls)+"A"+to_string(cows)+"B";
        return ans;

    }
};