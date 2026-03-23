class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n <= 2) return 0;
        vector<int> lg(n,-1);
        vector<int> rg(n,-1);
        int mx = height[0];
        lg[0] = 0;
        for(int i = 1; i<n;i++){
            lg[i] = mx;
            mx = max(mx,height[i]);
        }
        rg[n-1] = 0;
        mx = height[n-1];
        for(int i = n-2; i>= 0; i--){
            rg[i] = mx;
            mx = max(mx,height[i]);
        }
        // for(int i = 0; i< n;i++){
        //     cout<<lg[i]<<" ";
        // }
        // cout<<endl;
        // for(int i = 0; i< n;i++){
        //     cout<<rg[i]<<" ";
        // }
        // cout<<endl;
        int ans = 0;
        for(int i = 1; i<n-1; i++){
            int cur = max(0 , min(lg[i],rg[i]) - height[i] ) ;
            ans += cur;
        }
        return ans;

    }
};