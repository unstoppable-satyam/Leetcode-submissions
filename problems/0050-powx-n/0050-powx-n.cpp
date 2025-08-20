class Solution {
    double binExp(double x, long long n ){
        if(n == 0 ) return 1;
        double cur = binExp(x,n/2);
        if(n%2 == 1 ){
            return x*cur*cur;
        }
        else{
            return 1*cur*cur;
        }
    }

public:
    double myPow(double x, int n) {
        if(x == 0 || x == 1 || n == 1) return x;
        if(n == 0 ) return 1;
        double cur = x;
        long long nn = n;
        if (n >= 1){
            return binExp(x,nn);
        }
        else{
            nn = -nn;
            return binExp(1/x,nn);
        }
    }
};