class Solution {
public:
    long long merge(vector<int> &nums, int i,int sz1,int j,int sz2){
        vector<int> sorted_arr(sz1+sz2);
        int cnt= 0;
        int ii = i;
        int jj = j;
        long long cnt_inv = 0;
        for(; jj< j + sz2; jj++){
            while(ii < i+ sz1 && nums[ii] <= nums[jj]){
                ii++;
            }
            cnt_inv += ( i+sz1 - ii);
        }
        jj = j; 
        ii = i;
        while(ii < i+sz1 && jj < j+sz2){
            if(nums[ii] <= nums[jj]){
                sorted_arr[cnt++] = nums[ii++];
            }
            else{
                sorted_arr[cnt++] = nums[jj++];
            }
        }
        while(ii < i+sz1){
            sorted_arr[cnt++] = nums[ii++];
        }
        while(jj< j+sz2 ){
            sorted_arr[cnt++] = nums[jj++];
        }
        for(int k  = i ; k < j + sz2; k++){
            nums[k] = sorted_arr[k-i];
        }
        return cnt_inv;
    }

    void ms(vector<int> &nums, int i, int j,long long &cnt){
        if(i >= j) return;
        int mid = i + (j-i)/2;
        ms(nums,i,mid,cnt);
        ms(nums,mid+1,j,cnt);
        cnt += merge(nums,i,mid-i+1 , mid+1,j-(mid+1)+1 );
    }

    bool isIdealPermutation(vector<int>& nums) {
        vector<int> nums_org(nums.begin(),nums.end());
        int n = nums.size();
        long long cnt = 0;
        ms(nums,0,n-1,cnt);
        long long cnt2 = 0;
        //cout<<cnt<<endl;

        for(int i= 0; i<n-1; i++){
            //cout<<" hi ";
            //cout<<nums[i]<<" "<<nums[i+1]<<endl;
            if( nums_org[i] > nums_org[i+1]){
                cnt2++;
            }
        }
        //cout<<cnt2<<endl;
        return (cnt2 == cnt);
    }
};