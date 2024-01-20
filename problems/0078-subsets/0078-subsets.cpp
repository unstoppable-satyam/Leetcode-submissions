class Solution {
public:
    vector<vector<int>> Allsets;

    void sets(vector<int> &nums,int i,vector<int> &tempSet){
        if( i >= nums.size()){
            Allsets.push_back(tempSet);
            //tempSet.clear();
            return;
        }

        tempSet.push_back(nums[i]);
        sets(nums,i+1,tempSet);
        tempSet.pop_back();

        sets(nums,i+1,tempSet);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        sets(nums,0,temp);
        return Allsets;
    }
};