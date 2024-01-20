class Solution {
public:
    vector<vector<int>> Allsets;
    void sets(vector<int> &nums,int i,vector <int> &tempSet){
        if( i >= nums.size()){
            Allsets.push_back(tempSet);
            return;
        }
        for(int j = 0 ; j < nums.size() ; j++){
            if( find(tempSet.begin(),tempSet.end(),nums[j])   != tempSet.end()) continue;
            tempSet.push_back(nums[j]);
            sets(nums,i+1,tempSet);
            tempSet.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tempSet;
        sets(nums,0,tempSet);
        return Allsets;
    }
};