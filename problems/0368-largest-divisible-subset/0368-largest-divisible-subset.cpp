class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();

        vector<int> dp(n,1);
        vector<int> trace(n,1);
        int maxi = 0;
        int max_ind = 0;
        for(int i= 0; i< n ; i++){
            trace[i] = i;
            for(int j=0;  j<i; j++){
                if( (arr[i]%arr[j]== 0)){   //dp[i] <= 1+dp[j]  for  lex. largest
                    dp[i] = max(dp[i],1+dp[j]);
                    trace[i] = j;
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                max_ind = i;
            }
        }
        vector<int> ret;
        ret.push_back(arr[max_ind]);
        while(max_ind != trace[max_ind]){
            max_ind = trace[max_ind];
            ret.push_back(arr[max_ind]);
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};