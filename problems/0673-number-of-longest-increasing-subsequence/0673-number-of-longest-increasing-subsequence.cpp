class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n,1);
        int maxi = 0;
        int max_ind = 0;
        vector<int> gbv(n,1);
        for(int i= 0; i< n ; i++){
            for(int j=0;  j<i; j++){
                if(arr[i] > arr[j]){
                    if(dp[i] == 1+ dp[j]){
                        gbv[i] += gbv[j];
                        dp[i] = max(dp[i],1+dp[j]);
                    }
                    else if( dp[i] < 1+dp[j]){
                        gbv[i] = gbv[j];
                        dp[i] = max(dp[i],1+dp[j]);
                    }
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                max_ind = i;
            }
        }
        for(int i= 0; i<n; i++){
            cout<<gbv[i]<<" ";
        }
        cout<<endl;
        int ret =0;
        for(int i= 0; i<n; i++){
            if(dp[i] == maxi){
                ret += gbv[i];
            }
        }
        
        return ret;
    }
};