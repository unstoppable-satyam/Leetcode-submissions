class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> fwd(2,0);
        vector<int> cur(2,0);
        fwd[0] = 0;
        fwd[1] = 0;
        for(int ind = n-1 ; ind >=0 ; ind--){
            for(int bd = 0; bd <=1;  bd++){
                if(bd == 0){
                    // buys
                    int op1 = -prices[ind] + fwd[!bd];
                    // not buys
                    int op2 = fwd[bd];
                    cur[bd] = max(op1,op2);
                }
                else{
                    //sells
                    int op3 = prices[ind] + fwd[!bd];
                    // not sells
                    int op4 =fwd[bd];
                    cur[bd]= max(op3,op4);
                }
            }
            fwd = cur;
        }   
        return cur[0];
    }
};