class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int cnt = 0 ;
        for( int i = 1; i< n-1; i++ ){
            int ls = 0, rs = 0, lg = 0, rg = 0;
            int j = i-1;
            while( j >= 0 ){
                if(rating[j] < rating[i] ){
                    ls++;
                }
                else if(rating[j] > rating[i] ){
                    lg++;
                }
                j--;
            }
            j = i+1;
            while( j < n ){
                if(rating[j] < rating[i] ){
                    rs++;
                }
                else if(rating[j] > rating[i] ){
                    rg++;
                }
                j++;
            }
            cnt +=  ls*rg + lg*rs;
        }
        return cnt;
    }
};