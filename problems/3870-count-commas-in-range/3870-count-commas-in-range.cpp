class Solution {
public:
    int countCommas(int n) {
        int ans = 0;
        int cnt = 1000;
        for(int i = 1 ; cnt <= n; i++ ) {
            int num1 = cnt*1000 - 1;
            int num2 = cnt - 1;
            ans += i * ( min(n, num1) - num2 );
            cnt  = cnt*1000;
        }
        return ans;
    }
};