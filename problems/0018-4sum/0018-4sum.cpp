class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        long long tar = target;
        set<vector<int>> st;
        for(int i = 0; i<n-3; i++){
            //if(i > 1 && nums[i] == nums[i-2] ) continue;
            for( int j = i+1; j<n-2; j++ ){
                int k = j+1 , m = n-1;
                while(k<m){
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[m];
                    if( sum > tar){
                        m--;
                    }
                    else if( sum < tar){
                        k++;
                    }
                    else{
                        vector<int> temp ={nums[i],nums[j],nums[k],nums[m]};
                        k++;
                        m--;
                        st.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};