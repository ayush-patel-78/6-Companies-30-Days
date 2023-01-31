// https://leetcode.com/problems/fraction-to-recurring-decimal/

#define ll long long
class Solution {
public:
    string fractionToDecimal(ll numerator, ll denominator) {
        string ans = "";
        if(numerator == 0) return "0";
        if(numerator <0 && denominator < 0){
            numerator *= -1;
            denominator *= -1;
        }
        else if(numerator < 0){
            numerator *= -1;
            ans = "-";
        }
        else if(denominator < 0){
            denominator *= -1;
            ans = "-";
        }

        ll quotient = numerator/denominator;
        
        string q = to_string(quotient);
        map<ll,ll> mpp;
        ll rem = numerator%denominator;
        if(rem == 0){
            ans = ans + q;
            return ans;
        }
        
        bool repeating = false;
        string dec = "";
        ll count = 0;
        ll index = 0;
        string dec_non_repeating =".";
        string dec_repeating ="";
        while(rem != 0){
            if(mpp.find(rem)==mpp.end()){
                mpp[rem]=count;
                count++;
                rem = rem*10;
                ll q_temp = rem/denominator;
                dec += to_string(q_temp);
                rem = rem%denominator;

            }
            else {
                index = mpp[rem];
                for(int i=0;i<index;i++){
                    dec_non_repeating += dec[i];
                }
                for(int i=index;i<dec.size();i++){
                    dec_repeating += dec[i];
                }
                repeating=true;
                break;
            }

        }
        if(repeating){
            dec_repeating = '('+ dec_repeating;
            dec_repeating = dec_repeating + ')';
            dec = dec_non_repeating + dec_repeating;
        }
        else{
            dec = dec_non_repeating + dec;
        }
        q = q+dec;
        ans = ans + q;
        return ans;
    }
};