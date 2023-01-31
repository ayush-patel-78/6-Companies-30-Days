// https://leetcode.com/problems/maximum-good-people-based-on-statements/description/

class Solution {
public:
    string generate_binary(int num,int n){
        string s = "";
        while(n--){
            s += to_string(num%2);
            num = num/2;
        }
        return s;
    }
    int maximumGood(vector<vector<int>>& statements) {
        int n = statements.size();
        int ans = 0;
        for(int i=0;i<pow(2,n);i++){
            string s = generate_binary(i,n);
            bool flag = true;
            for(int j = 0;j<n;j++){
                if(s[j]=='1'){
                    for(int k=0;k<n;k++){
                        int z = statements[j][k];
                        if(z==2) continue;
                        if(z==1 && s[k]=='0' || z==0 && s[k]=='1'){
                            flag = false;
                            break;
                        }
                    }
                }
            }
            if(flag){
                int count = 0;
                for(int l=0;l<n;l++){
                    if(s[l]=='1') count++;
                }
                if(count >= ans) ans = count;
            }
        }
        return ans;
    }
};