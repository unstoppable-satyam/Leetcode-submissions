class Solution {
public:
    
long long int binarySearch(long long int s,long long int e,long long int target){
    long long int mid = s+ (e-s)/2;
    while( 1 < e-s){
        if(mid*mid > target){
            e= mid;
        }
        else{
            s = mid;
        }
        mid = s+ (e-s)/2;
    }
    return s;
}

int mySqrt(int x) {
    long long int s = -1;
    long long a = 1;
    long long int e = x+a;
    int ans = binarySearch(s,e,x);
    return ans;
}
};