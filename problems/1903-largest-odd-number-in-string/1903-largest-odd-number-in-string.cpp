class Solution {
public:
    string largestOddNumber(string num) {
        bool fnd = false;
        int n = num.size();
        string ret = "";
        for(int i = n-1 ; i >= 0 ; i--){
            if( (num[i] - '0')%2 == 1){
                ret = num.substr(0, i+1);
                break;
            }
        }
        return ret;
    }
};