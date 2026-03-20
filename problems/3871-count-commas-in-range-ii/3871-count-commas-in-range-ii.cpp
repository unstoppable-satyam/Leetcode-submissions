class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long cnt = 1000;
        for(int i = 1 ; cnt <= n; i++ ) {
            long long num1 = cnt*1000LL - 1;
            long long num2 = cnt - 1;
            ans += i * ( min(n, num1) - num2 );
            cnt  = cnt*1000LL;
        }
        return ans;
    }
};