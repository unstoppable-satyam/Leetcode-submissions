class Solution {

public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> fwd(2,vector<int>(3,0));
        vector<vector<int>> cur(2,vector<int>(3,0));
        fwd[0][0]=0; fwd[0][1]=0; fwd[0][2]=0; fwd[1][0]=0; fwd[1][1]=0; fwd[1][2]=0;
        for(int ind = n-1 ; ind >=0 ; ind--){
            for(int buy = 0 ; buy <= 1; buy++){
                for(int cnt=0 ; cnt <= 2 ; cnt++){
                    if(buy == 0 ){
                        // buys
                        int op1 =0;
                        if(cnt<2) op1 = -prices[ind] + fwd[!buy][cnt];
                        // not buys
                        int op2 = fwd[buy][cnt];
                        cur[buy][cnt] = max(op1,op2);
                    }
                    else{
                        //sells
                        int op3 =0;
                        if(cnt<2 ) op3 = prices[ind] +  fwd[!buy][cnt+1];
                        // not sells
                        int op4 = fwd[buy][cnt];
                        cur[buy][cnt]= max(op3,op4);
                    }
                }
            }
            fwd = cur;
        }
        return cur[0][0];
    }
};