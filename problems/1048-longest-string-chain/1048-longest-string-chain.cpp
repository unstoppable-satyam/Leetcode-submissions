bool cmp_sort(string a, string b){
    return a.size()<b.size();    
}

class Solution {
private:
    bool cmp(string a,string b){
        if( a.size() != (b.size()+1) ) return false;
        int i=0, j=0;
        while(i<a.size() && j<b.size()){
            if(a[i] == b[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if( i == j ) return true;
        return ( i == a.size() && j == b.size() );
    }

   

public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort( words.begin(), words.end(),cmp_sort );
        vector<int> dp(n,1);
      
        int maxi = 0;
        for(int i= 0; i< n ; i++){
            for(int j=0;  j<i; j++){
                if( cmp(words[i],words[j]) && dp[i] < 1+dp[j]){   //dp[i] <= 1+dp[j]  for  lex. largest
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
            }
        }
        // cout<<" maxi "<<maxi<<endl;
        // vector<string> ret;
        // ret.push_back( words[max_ind]);
        // while( max_ind != trace[max_ind] ){
        //     max_ind = trace[max_ind];
        //     ret.push_back( words[max_ind]);
        // }
        // reverse(ret.begin(),ret.end());
        // for(auto it : ret ){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        return maxi;
    }
};