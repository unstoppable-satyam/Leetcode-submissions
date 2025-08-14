class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 1e6, sell = -1;
        int mx = 0;
        int n  = prices.size();
        for(int i= 0; i< n; i++){
            mx = max( mx, prices[i]-buy);
            buy = min(buy, prices[i]);           
        }
        return mx;
    }
};