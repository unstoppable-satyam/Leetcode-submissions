typedef long long ll;
class Solution {

public:
    const int MOD = 1000000007;
    long long binExp(long long a, long long b) {
        long long result = 1;
        while (b) {
            if (b & 1)
                result = (result * a) %MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        ll ans = 1LL;
        ll even = ceil(n/2.0);
        ll odd = n - even;
        ans = (ans*binExp(5,even))%MOD;
        ans = (ans*binExp(4,odd))%MOD;
        return ans;
    }
};