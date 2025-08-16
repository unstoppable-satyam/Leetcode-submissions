class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums_org) { 
        sort(nums_org.begin(),nums_org.end());
        map<int,int> fr;
        for(int i= 0; i< nums_org.size(); i++){
            fr[nums_org[i]]++;
        }
        vector<int> nums;
        for(auto it: fr){
            if(it.second >= 3 ){
                nums.push_back(it.first);
                nums.push_back(it.first);
                nums.push_back(it.first);
            }
            else if( it.second == 2 ){
                nums.push_back(it.first);
                nums.push_back(it.first);
            }
            else{
                nums.push_back(it.first);
            }
        }
        int n = nums.size();
        set<vector<int>> ret;
        for(int i = 0; i<n-2; i++){
            int j = i+1, k = n-1;
            while(j < k ){
                int sum = nums[i] + nums[j];
                if( sum + nums[k] > 0 ){
                    k--;
                }
                else if( sum + nums[k] < 0 ){
                    j++;
                }
                else{
                    vector<int> temp = {nums[i],nums[j],nums[k]};
                    j++;
                    k--;
                    sort(temp.begin(),temp.end());
                    ret.insert(temp);
                }
            }
        }
        vector<vector<int>> ans(ret.begin(),ret.end());
        return ans;
    }
};