class Solution {
public:
    int jump(vector<int>& arr) {
        int i = 0 ; int n= arr.size();
        int cnt =0;
        int maxi =0;
        if(n == 1 ) return 0;
        while ( i < n){
            if(i > maxi) return -1;
            maxi = i + arr[i];
            cnt +=1;
            for(int ind = i+ 1; ind <=  i+  arr[i]; ind++){
                maxi = max(maxi , arr[ind] + ind);
            }
            if(maxi >= n-1) return cnt+1;
            i = maxi+1;
        }
        return -1;

        // int step = 1;
        // int n = nums.size();
        // if(n ==  1 ) return 0;
        // int i = 0;
        // int j = nums[i];
        // int mx_ind_reach = nums[0];
        // if(i+ mx_ind_reach >= n-1) return 1;
        // while(i<n && mx_ind_reach<n){
        //     for( ; i<=j; i++){
        //         mx_ind_reach = max(mx_ind_reach, i+ nums[i]);
        //     }
        //     if(mx_ind_reach >= n-1 ) return step+1;
        //     step++;
        //     j = mx_ind_reach;
        // }
        // return -1;
    }
};