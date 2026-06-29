class Solution {
public:
    void nextPermutation(vector<int>& num) {
        // int n = A.size(); // size of the array.

        // // Step 1: Find the break point:
        // int ind = -1; // break point
        // for (int i = n - 2; i >= 0; i--) {
        //     if (A[i] < A[i + 1]) {
        //         // index i is the break point
        //         ind = i;
        //         break;
        //     }
        // }

        // // If break point does not exist:
        // if (ind == -1) {
        //     // reverse the whole array:
        //     reverse(A.begin(), A.end());
        //     return;
        // }

        // // Step 2: Find the next greater element
        // //         and swap it with arr[ind]:

        // for (int i = n - 1; i > ind; i--) {
        //     if (A[i] > A[ind]) {
        //         swap(A[i], A[ind]);
        //         break;
        //     }
        // }

        // // Step 3: reverse the right half:
        // reverse(A.begin() + ind + 1, A.end());

        // return;

        // int n = nums.size();
        // bool largest = true;
        // for(int i = 0; i<n-1;i++){
        //     if(nums[i+1] > nums[i]){
        //         largest = false;
        //         break;
        //     }
        // }
        // if(largest){
        //     sort(nums.begin(), nums.end());
        //     return;
        // }
        // multiset<int> temp;
        // int turn = 0;
        // int i = n-1;
        // for(; i>0; i--){
        //     temp.insert(nums[i]);
        //     if( nums[i-1] < nums[i] ){
        //         turn = nums[i-1];
        //         temp.insert(nums[i-1]);
        //         break;
        //     }     
        // }
        // int ub = INT_MAX;
        // int ubind = n;
        // for(int j = i; j<n; j++){
        //     if(nums[j] > turn ){
        //         if(nums[j] < ub ){
        //             ub = nums[j];
        //             ubind = j;
        //         }
        //     }
        // }
        // swap(nums[i-1],nums[ubind]);
        // sort(nums.begin() + i, nums.end());
        // auto it = temp.upper_bound(turn);
        // nums[i-1] = *it;
        // temp.erase(it);
        // for(auto it: temp){
        //     nums[i++] = it;
        // }


        int dw = -1;
        int n = num.size();
        for(int i = n-1; i>0 ; i--){
            if(num[i-1] < num[i] ){
                dw = i-1;
                break;
            }
        }
        if(dw == -1 ){
            sort(num.begin(),num.end());
        }
        else{
            int j = dw;
            for(int i = dw+1; i<n; i++){
                if(num[i] > num[dw] ){
                    j = i;
                }
            }
            swap(num[dw],num[j]);
            sort(num.begin()+dw+1, num.end());
        }
    }
};